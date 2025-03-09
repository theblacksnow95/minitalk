/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:12:56 by yourlogin         #+#    #+#             */
/*   Updated: 2024/10/28 11:56:25 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checkwrite(char str, va_list ap, int fd);

int	ft_checkflags(char str, va_list ap, int fd)
{
	int	temp;

	temp = 0;
	if (str == 's' || str == 'c' || str == '%')
		temp += checkwrite(str, ap, fd);
	if (str == 'i' || str == 'd')
		temp += ft_putnbr(va_arg(ap, int), fd);
	if (str == 'u')
		temp += ft_putunsigned(va_arg(ap, unsigned int), fd);
	if (str == 'x')
		temp += ft_putnbrhex_l(va_arg(ap, unsigned int), fd);
	if (str == 'X')
		temp += ft_putnbrhex_c(va_arg(ap, unsigned int), fd);
	if (str == 'p')
	{
		temp += ft_putpointer(va_arg(ap, void *), fd);
		if (temp < 0)
			return (-1);
	}
	if (temp < 0)
		return (-1);
	return (temp);
}

static int	checkwrite(char str, va_list ap, int fd)
{
	int	temp;

	temp = 0;
	if (str == 's')
	{
		temp += ft_putstr_fd_int(va_arg(ap, char const *), fd);
		if (temp < 0)
			return (-1);
	}
	if (str == 'c')
	{
		temp += ft_putchar_int(va_arg(ap, int));
		if (temp < 0)
			return (-1);
	}
	if (str == '%')
		temp += ft_putchar_int('%');
	return (temp);
}
