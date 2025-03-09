/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:36:33 by emurillo          #+#    #+#             */
/*   Updated: 2024/10/18 13:28:47 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	fcount(int n)
{
	size_t	i;

	i = 1;
	if (n == -2147483648)
	{
		n = n + 1;
	}
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*int_min(char *str)
{
	int		i;
	char	*min;

	i = 0;
	min = "-2147483648";
	while (min[i])
	{
		str[i] = min[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_putnbr(int nb, char *str, size_t len)
{
	if (nb == -2147483648)
	{
		int_min(str);
		return (str);
	}
	str[len] = '\0';
	if (nb < 0 && nb != -2147483648)
	{
		nb = -nb;
		str[0] = '-';
	}
	len--;
	while (nb >= 10)
	{
		str[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	str[len] = nb % 10 + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char		*nbr;
	size_t		len;

	len = fcount(n);
	nbr = (char *) malloc((sizeof(char) * len) + 1);
	if (!nbr)
		return (NULL);
	nbr = ft_putnbr(n, nbr, len);
	return (nbr);
}

/* int	main(void)
{
	int		nb;
	char	*str;

	nb = -2147483648;
	str = ft_itoa(nb);
	printf("%s", str);
	return (0);
} */
