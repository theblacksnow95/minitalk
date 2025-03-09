/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:59:54 by emurillo          #+#    #+#             */
/*   Updated: 2024/10/16 11:51:55 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 97 && c <= 122) || (c >= 65 && c <= 90)))
	{
		return (1024);
	}
	else if ((c >= '0' && c <= '9'))
	{
		return (1024);
	}
	return (0);
}

/* int	main(void)
{
	char	c;

	c = '[';
	printf("result of (%s): %i", &c, ft_isalnum(c));
	return (0);
}
 */
