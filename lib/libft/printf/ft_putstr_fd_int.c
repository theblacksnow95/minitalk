/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:32:02 by emurillo          #+#    #+#             */
/*   Updated: 2024/10/25 13:43:17 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_int(char const *str, int fd)
{
	int	ret;

	ret = 0;
	if (!str)
		str = "(null)";
	while (str[ret])
	{
		if ((write(fd, &str[ret], 1) == -1))
			return (-1);
		ret++;
	}
	return (ret);
}
