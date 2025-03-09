/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:21:49 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/05 16:51:06 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *str, int search_chr)
{
	int	i;

	i = 0;
	search_chr = search_chr & 0xFF;
	while (*str != '\0' && search_chr != *str)
	{
		str++;
	}
	if (search_chr == *str)
	{
		return (&str[i]);
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
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
	t_len = (ft_strlen_gnl(s1) + ft_strlen_gnl(s2));
	join = (char *)malloc((t_len + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	while (s1[j])
		join[i++] = s1[j++];
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	free(s1);
	return (join);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen_gnl(s);
	if (start >= str_len)
	{
		sub = (char *)malloc(sizeof(char));
		if (sub)
			sub[0] = '\0';
		return (sub);
	}
	if (len > str_len - start)
		len = str_len - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup_gnl(char const *string)
{
	char	*cp;
	int		i;

	i = 0;
	cp = (char *)malloc(ft_strlen_gnl(string) * sizeof(char) + 1);
	if (cp == NULL)
		return (NULL);
	while (string[i])
	{
		cp[i] = string[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
