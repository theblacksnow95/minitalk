/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:41:16 by yourlogin         #+#    #+#             */
/*   Updated: 2024/10/16 11:50:59 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int ch)
{
	if (ch >= 65 && ch <= 90)
	{
		ch = ch + 32;
		return (ch);
	}
	return (ch);
}

/* int	main(void)
{
	int	ch;
	int	a;
	int	b;

	ch = 'p';
	a = 'S';
	b = '9';
	printf("%c => %c\n", ch, ft_tolower(ch));
	printf("%c => %c\n", a, ft_tolower(a));
	printf("%c => %c\n", b, ft_tolower(b));
	return (0);
} */
