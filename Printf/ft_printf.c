/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glapshin <glapshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 06:40:20 by georgiilaps       #+#    #+#             */
/*   Updated: 2025/03/03 20:58:20 by glapshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_spec(char c, va_list *args)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter = ft_putchar_fd(va_arg(*args, int), 1);
	else if (c == 's')
		counter = ft_putstr(va_arg(*args, char *));
	else if (c == 'd' || c == 'i')
		counter = ft_putnbr((long)va_arg(*args, int));
	else if (c == 'u')
		counter = ft_putnbr((long)va_arg(*args, unsigned int));
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
	va_list	args;

	i = 0;
	counter = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			counter += ft_spec(str[++i], &args);
		else
			counter += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (counter);
}

int	ft_put_p(void *ptr)
{
	int				counter;
	unsigned long	adr;

	adr = (unsigned long)ptr;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	counter = ft_putstr("0x");
	if (counter == -1)
		return (-1);
	counter += ft_puthex(adr, 'x');
	return (counter);
}
