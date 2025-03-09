/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:18:24 by emurillo          #+#    #+#             */
/*   Updated: 2024/10/16 14:25:04 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**
**	This function iterates through a string "s" and for each character inside
**	if applies the function "f" to each char, and uses the index and the
**	chars as its own arguments.
**
**
 */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
