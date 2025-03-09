/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:57:06 by yourlogin         #+#    #+#             */
/*   Updated: 2024/12/17 09:45:37 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_rec(int nb, int fd)
{
	int		cont;
	char	num;
	int		temp;

	cont = 0;
	if (nb >= 10)
	{
		temp = ft_putnbr(nb / 10, fd);
		if (temp == -1)
			return (-1);
		cont += temp;
	}
	num = nb % 10 + '0';
	if (write(fd, &num, 1) == -1)
		return (-1);
	cont++;
	return (cont);
}

int	ft_putnbr(int nb, int fd)
{
	int		cont;

	cont = 0;
	if (nb == INT_MIN)
		return (ft_putstr_fd_int("-2147483648", fd));
	cont = 0;
	if (nb < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		cont++;
		nb = -nb;
	}
	cont += ft_putnbr_rec(nb, fd);
	return (cont);
}

int	ft_putunsigned(unsigned int nb, int fd)
{
	char	num;
	int		temp;

	temp = 0;
	if (nb >= 10)
	{
		temp += ft_putnbr(nb / 10, fd);
		if (temp == -1)
			return (-1);
	}
	num = nb % 10 + '0';
	temp += write(fd, &num, 1);
	if (temp == -1)
		return (-1);
	return (temp);
}

int	ft_putnbrhex_l(unsigned int nb, int fd)
{
	char	*hex;
	char	res;
	int		num;

	num = 0;
	hex = "0123456789abcdef";
	if (nb >= 16)
	{
		num = ft_putnbrhex_l(nb / 16, fd);
		if (num == -1)
			return (-1);
	}
	res = hex[nb % 16];
	if (write(fd, &res, 1) == -1)
		return (-1);
	return (num + 1);
}

int	ft_putnbrhex_c(unsigned int nb, int fd)
{
	char	*hex;
	char	res;
	int		num;

	num = 0;
	hex = "0123456789ABCDEF";
	if (nb >= 16)
	{
		num = ft_putnbrhex_c(nb / 16, fd);
		if (num == -1)
			return (-1);
	}
	res = hex[nb % 16];
	if (write(fd, &res, 1) == -1)
		return (-1);
	return (num + 1);
}
