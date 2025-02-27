/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgiilapshin <georgiilapshin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 06:40:20 by georgiilaps       #+#    #+#             */
/*   Updated: 2025/02/27 19:50:00 by georgiilaps      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checktype(char c, va_list *args)
{
	int	type;

	type = 0;
    if (c == 'd' || c == 'i')
        type = ft_putnbr_fd(va_arg(*args, int));
    else if (c == 'c')
        type = ft_putchar_fd(va_arg(*args, int), 1);
    else if (c == 's')
        type = ft_putstr(va_arg(*args, char *));
    else if (c == '%')
        type = ft_putchar_fd('%', 1);
    else if (c == 'u')
        type = ft_putunnbr(va_arg(*args, unsigned int));
    else if (c == 'x' || c == 'X')
        type = ft_puthex(va_arg(*args, unsigned int), c);
    else if (c == 'p')
        type = ft_put_p(va_arg(*args, void *));
    if (type == -1)
		return (-1);
	return (type);
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
