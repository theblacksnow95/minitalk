/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:05:47 by emurillo          #+#    #+#             */
/*   Updated: 2025/03/11 15:25:30 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t	g_check = 0;

static void	update_check(int signum)
{
	(void)signum;
	g_check = 1;
}

int	send_bits(int pid, char c)
{
	int	bit;
	int	timeout;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		g_check = 0;
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		timeout = 5000;
		while (!g_check && timeout > 0)
		{
			usleep(200);
			timeout--;
		}
		if (timeout == 0)
		{
			ft_printf("Error: NO RESPONSE FROM SERVER.\n");
			return (EXIT_FAILURE);
		}
		bit++;
	}
	return (EXIT_SUCCESS);
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
	signal(SIGUSR1, update_check);
	signal(SIGUSR2, update_check);
	while (message[i] != '\0')
	{
		if (send_bits(pid, message[i++]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (send_bits(pid, '\n') == EXIT_FAILURE \
	|| send_bits(pid, '\n' == EXIT_FAILURE || send_bits(pid, '\0') ))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
