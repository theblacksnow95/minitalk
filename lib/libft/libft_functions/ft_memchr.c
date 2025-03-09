/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:44:20 by emurillo          #+#    #+#             */
/*   Updated: 2024/10/16 11:53:00 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** To look for the value c, we first cast it to an unsigned char,
** we do the same with the void buffer, and compare until we reach LEN
** when we find the value ch, in str, we will return the position in str.
** If 'c' is not found we return NULL.
*/

void	*ft_memchr(const void *buf, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;
	unsigned int	ch;

	str = (unsigned char *)buf;
	ch = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		if (str[i] == ch)
		{
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	str[30] = "las no pasas murcielago";
	char	c;
	char*	res;

	c = 'o';
	res = ft_memchr(str, c, 15);
	printf("the character '%c' is in '%s'\n", c, res);
	return (0);
} */
