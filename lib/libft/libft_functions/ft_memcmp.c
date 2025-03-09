/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:21:22 by emurillo          #+#    #+#             */
/*   Updated: 2024/10/16 11:53:09 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t c)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)buf1;
	s2 = (unsigned char *)buf2;
	while (i < c)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char buffer1[] = {1, 2, 3, 4};
	char buffer2[] = {1, 2, 3, 4, 8};

	if (ft_memcmp(buffer1, buffer2, 5) == 0)
	{
		printf("Los bloques de memoria son iguales\n");
	}
	else
	{
		printf("Los bloques de memoria son diferentes: %i\n",
			ft_memcmp(buffer1, buffer2, 5));
	}
}
 */
