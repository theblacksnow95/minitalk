/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:03:09 by yourlogin         #+#    #+#             */
/*   Updated: 2025/01/17 11:13:57 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr(char *str, int search_chr);
size_t		ft_strlen(char const *str);

static size_t	word_count(char *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ((i == 0 || str[i - 1] == c) && str[i] != c)
			count++;
		i++;
	}
	return (count);
}

static void	*ft_free(char **str, int n)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return (NULL);
}

static char	**fill_split(char **arr, char *s, char c)
{
	size_t	i;
	size_t	wlen;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (ft_strchr(s, c))
				wlen = (size_t)(ft_strchr(s, c) - s);
			else
				wlen = ft_strlen(s);
			arr[i] = ft_substr(s, 0, wlen);
			if (arr[i] == NULL)
				return (ft_free(arr, i));
			i++;
			s += wlen;
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char *s, char c)
{
	size_t	wn;
	char	**arr;

	if (!s)
		return (NULL);
	wn = word_count(s, c);
	arr = malloc(sizeof(char **) * (wn + 1));
	if (!arr)
		return (NULL);
	return (fill_split(arr, s, c));
}

/* int	main(void)
{
	char	str[] = "hello, -world, -this, -is, -a, -test";
	int		i;
	char	delimiter = ' ';
	char	**result;

	i = 0;
	result = ft_split(str, delimiter);
	if (result == NULL)
	{
		printf("Error: ft_split returned NULL.\n");
		return (1);
	}
	while (result[i])
	{
		printf("Word %d: %s\n", i + 1, result[i]);
		i++;
	}
	free(result);
	return (0);
} */
