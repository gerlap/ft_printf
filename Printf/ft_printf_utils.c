/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgiilapshin <georgiilapshin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:28:26 by georgiilaps       #+#    #+#             */
/*   Updated: 2025/03/01 15:19:08 by georgiilaps      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr(char *str)
{
	int	counter;

	counter = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[counter])
	{
		ft_putchar_fd(str[counter], 1);
		counter++;
	}
	return (counter);
}

int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar_fd((n % 10) + '0', 1);
	return (count);
}

int	ft_puthex(unsigned long i, char x)
{
	int		counter;
	char	*base;

	counter = 0;
	base = "0123456789ABCDEF";
	if (x == 'x')
		base = "0123456789abcdef";
	if (i >= 16)
		counter += ft_puthex((i / 16), x);
	counter += ft_putchar_fd(base[i % 16], 1);
	return (counter);
}
