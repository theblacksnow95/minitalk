/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:05:47 by emurillo          #+#    #+#             */
/*   Updated: 2025/03/10 15:32:57 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	confirm(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("\033[0;32mMessage sent and received correctly!\033[0;32m\n");
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
		usleep(500);
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
		signal(SIGUSR1, confirm);
		signal(SIGUSR2, confirm);
		while (av[2][i] != '\0')
		{
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
