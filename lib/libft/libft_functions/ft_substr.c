/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:57:07 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/17 11:16:49 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	the function extracts a substring from the main string
**	it takes a start point and a total lenght
**	we char is the start point is farther than the total lenght of s
**	adjust the lengh if it goes outside of the remaining string
**	allocate memory using malloc and copy the str adding the '\0
**	returns null if overflow
*/

size_t	ft_strlen(char const *str);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	str_len;

	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}

/* int	main(void)
{
	char	str[] = "the clostern white.";
	char	*substr;

	substr = ft_substr(str, 400, 20);

	printf("Original str: '%s'\n", str);
	printf("Substr => '%s'\n", substr);
	free(substr);
	return (0);
} */
