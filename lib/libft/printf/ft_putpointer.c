/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:20:33 by emurillo          #+#    #+#             */
/*   Updated: 2024/12/17 09:46:05 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *p, int fd)
{
	int					temp;
	unsigned long long	num;

	temp = ft_putstr_fd_int("0x", fd);
	if (temp == -1)
		return (-1);
	if (!p)
	{
		ft_putchar_int('0');
		temp++;
		return (temp);
	}
	num = (unsigned long long)p;
	temp += ft_putnbrhex_p(num, fd);
	if (temp < 0)
		return (-1);
	return (temp);
}

int	ft_putnbrhex_p(unsigned long long nb, int fd)
{
	char	*hex;
	int		num;

	num = 0;
	hex = "0123456789abcdef";
	if (nb >= 16)
	{
		num = ft_putnbrhex_p((nb / 16), fd);
		if (num == -1)
			return (-1);
	}
	if (write(fd, &hex[nb % 16], 1) == -1)
		return (-1);
	return (num + 1);
}
