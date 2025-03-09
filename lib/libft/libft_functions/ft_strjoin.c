/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:28:48 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/05 14:52:07 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	fstrlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*join;
	size_t	t_len;
	size_t	j;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	i = 0;
	j = 0;
	t_len = (fstrlen(s1) + fstrlen(s2));
	join = (char *)malloc((t_len + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	while (s1[j])
		join[i++] = s1[j++];
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}

/* int	main(void)
{
	char	s1[] = "the wall ";
	char	s2[] = "was sold";
	char	*cat;

	cat = ft_strjoin(s1, s2);
	printf("%s\n", cat);
	free(cat);
	return (0);
} */
