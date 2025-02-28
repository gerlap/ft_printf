/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgiilapshin <georgiilapshin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 06:40:20 by georgiilaps       #+#    #+#             */
/*   Updated: 2025/02/28 20:29:45 by georgiilaps      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checktype(char c, va_list *args)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter = ft_putchar_fd(va_arg(*args, int), 1);
	else if (c == 's')
		counter = ft_putstr(va_arg(*args, char *));
	else if (c == 'd' || c == 'i')
		counter = ft_putnbr_fd(va_arg(*args, int));
	else if (c == 'u')
		counter = ft_putunnbr(va_arg(*args, unsigned int));
	else if (c == 'x' || c == 'X')
		counter = ft_puthex(va_arg(*args, unsigned int), c);
	else if (c == 'p')
		counter = ft_put_p(va_arg(*args, void *));
	else if (c == '%')
		counter = ft_putchar_fd('%', 1);
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	int		ret;
	va_list	args;

	i = 0;
	counter = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			ret = ft_checktype(str[++i], &args);
		else
			ret = ft_putchar_fd(str[i], 1);
		if (ret == -1)
			return (-1);
		counter += ret;
		i++;
	}
	va_end(args);
	return (counter);
}

int	ft_puthex_ad(unsigned long i)
{
	int		counter;
	char	*base;

	counter = 0;
	base = "0123456789abcdef";
	if (i >= 16)
	{
		counter += ft_puthex_ad(i / 16);
		counter += ft_puthex_ad(i % 16);
	}
	else
		counter += ft_putchar_fd(base[i % 16], 1);
	if (counter == -1)
		return (-1);
	return (counter);
}

int	ft_put_p(void *ptr)
{
	int				counter;
	unsigned long	adr;
	int				tmp;

	adr = (unsigned long)ptr;
	counter = ft_putstr("0x");
	if (counter == -1)
		return (-1);
	tmp = ft_puthex_ad(adr);
	if (tmp == -1)
		return (-1);
	counter += tmp;
	return (counter);
}
