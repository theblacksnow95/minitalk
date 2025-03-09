/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:52:30 by emurillo          #+#    #+#             */
/*   Updated: 2024/10/16 11:53:25 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** Copy an array src to dest
** first copy src to a temporary variable s2, annd verify if we are having
** overlapping, overlaping risks changing a value before copying it.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (0);
	if (s2 < s1)
	{
		while (n--)
		{
			s1[n] = s2[n];
		}
	}
	else
	{
		while (i < n)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	return (dest);
}

/* int main()
{
	char str[100] = "Learningisfun";
	char *first, *second;

	first = str;
	second = str;
	printf("Original string :%s\n ", str);
	ft_memmove(second + 8, first, 10);
	printf("memmove overlap : %s\n ", str);

	return (0);
}
 */
