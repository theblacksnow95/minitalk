/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:53:08 by emurillo          #+#    #+#             */
/*   Updated: 2024/10/16 14:26:46 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**
**	The function mapi, takes another function as an argument, and specifies
**	its arguments '(int, char)', it allocates a new str as the result
**	of applying the "f" func to the string "s".
**	When using "f" we have to specifie the function as a pointer, and all its
**	arguments correctly.
**	We make sure the allocation using malloc returns null if there is a problem.
**	Using strlen we have the lentgh of "s" to use in malloc.
**
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	size_t	len;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		return (NULL);
	}
	while (s[i])
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
