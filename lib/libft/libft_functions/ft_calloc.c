/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:05:19 by yourlogin         #+#    #+#             */
/*   Updated: 2024/10/16 11:51:45 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** this function uses the samme principle than *bzero()*,
** initializing a block of memory equal to (nitems*size) and
** filling all the memory with zeros, allowing us to use it
** and returning a cast void* to us.
*/

void	*ft_calloc(size_t nitems, size_t size)
{
	unsigned char	*arr;
	size_t			i;

	i = 0;
	arr = malloc(nitems * size);
	if (arr == NULL)
	{
		return (NULL);
	}
	while (i < nitems * size)
		arr[i++] = 0;
	return ((void *)arr);
}

/* int	main(void)
{
	int	*array;
	int	i;
	int	n;

	i = 0;
	n = 1000;
	array = ft_calloc(n, sizeof(int));
	while (i++ < n)
	{
		printf("%d", array[i]);
		i++;
	}
	free(array);
	printf("\n");
	return (0);
}
 */
