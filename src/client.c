/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:05:47 by emurillo          #+#    #+#             */
/*   Updated: 2025/03/09 20:27:17 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	confirm(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("\033[0;32mSent!\033[0;32m\n");
	else
		ft_printf("\033[0;32mSent!\033[0;32m\n");
}

void	send_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i] != '\0')
		{
			signal(SIGUSR1, confirm);
			signal(SIGUSR2, confirm);
			send_bits(pid, av[2][i]);
			i++;
		}
		send_bits(pid, '\n');
	}
	else
	{
		ft_printf("Wrong format.\n");
		ft_printf("\t ./client [PID] ['MESSAGE']\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
