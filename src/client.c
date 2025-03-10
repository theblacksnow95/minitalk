/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:05:47 by emurillo          #+#    #+#             */
/*   Updated: 2025/03/10 18:40:42 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t	g_check = 0;

static void	update_check(int signum)
{
	(void)signum;
	g_check = 1;
}

void	send_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		while (0 == g_check)
			usleep(500);
		g_check = 0;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*message;
	int		i;

	i = 0;
	if (ac != 3)
	{
		ft_printf("Wrong format.\n\t $./client [PID] ['MESSAGE']\n");
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	message = av[2];
	ft_signal(SIGUSR1, update_check, false);
	ft_signal(SIGUSR2, update_check, false);
	while (message[i] != '\0')
	{
		send_bits(pid, message[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
