/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:37:08 by yourlogin         #+#    #+#             */
/*   Updated: 2024/10/16 11:52:27 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}

/* int	main(void)
{
	int	c;

	c = 32;
	if (ft_isprint(c))
	{
		printf("The value %d is printable", c);
	}
	else
		printf("The value %d is NOT printable", c);
	return (1);
} */
