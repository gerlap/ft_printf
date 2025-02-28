/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgiilapshin <georgiilapshin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 06:39:24 by georgiilaps       #+#    #+#             */
/*   Updated: 2025/02/28 20:33:36 by georgiilaps      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr(char *str);
int	ft_putnbr_fd(int n);
int	ft_putunnbr(unsigned int n);
int	ft_puthex(unsigned int n, char x);
int	ft_puthex_ad(unsigned long i);
int	ft_put_p(void *ptr);

#endif
