/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgiilapshin <georgiilapshin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:28:26 by georgiilaps       #+#    #+#             */
/*   Updated: 2025/02/27 19:50:32 by georgiilaps      ###   ########.fr       */
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
	int	ret;

	counter = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[counter])
	{
		ret = ft_putchar_fd(str[counter], 1);
		if (ret == -1)
			return (-1);
		counter++;
	}
	return (counter);
}

int	ft_putnbr_fd(int n)
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
		count += ft_putnbr_fd(n / 10);
	count += ft_putchar_fd((n % 10) + '0', 1);
	return (count);
}

int ft_putunnbr(unsigned int n)
{
    int count = 0;
    if (n >= 10)
        count += ft_putunnbr(n / 10);
    count += ft_putchar_fd((n % 10) + '0', 1);
    return count;
}

int	ft_puthex(unsigned int i, char x)
{
	int		counter;
	int		ret;
	char	*base;

	counter = 0;
	base = "0123456789ABCDEF";
    if (x == 'x')
        base = "0123456789abcdef";
	if (i >= 16)
	{
		ret = ft_puthex((i / 16), x);
		if (ret == -1)
			return (-1);
		counter += ret;
	}
	ret = ft_putchar_fd(base[i % 16], 1);
	if (ret == -1)
		return (-1);
	counter += ret;
	return (counter);
}

int ft_put_p(void *ptr)
{
    unsigned long address = (unsigned long)ptr;
    int count = 0;
    count += ft_putstr("0x");
    count += ft_puthex(address, 'x');
    return count;
}