/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:45:48 by emurillo          #+#    #+#             */
/*   Updated: 2024/10/16 11:53:17 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}
/* int	main(void)
{
	char	dest[10];

	strcpy(dest, "Test1");
	printf("Buffer in origin: %s\n", dest);
	ft_memcpy(((void *)0), ((void *)0), 3);
	printf("Buffer after memcpy: %s\n", dest);
	return (0);
}
 */
