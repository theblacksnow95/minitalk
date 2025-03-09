/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:04:13 by yourlogin         #+#    #+#             */
/*   Updated: 2024/10/28 12:04:25 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		fd;
	va_list	ap;
	int		temp;

	fd = 1;
	i = 0;
	temp = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			temp += ft_checkflags(format[++i], ap, fd);
		else
		{
			temp += write(fd, &format[i], 1);
			if (temp < 0)
				return (-1);
		}
		if (temp < 0)
			return (-1);
		i++;
	}
	va_end(ap);
	return (temp);
}
