/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:36:36 by emurillo          #+#    #+#             */
/*   Updated: 2025/03/10 19:02:08 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <signal.h>

volatile t_data	g_data;

static void	init_data(void)
{
	g_data.c = 0;
	g_data.bit = 0;
	g_data.pid_client = 0;
}


void	handler(int signum, siginfo_t *info, void *extra_info)
{
	(void)extra_info;
	if (info->si_pid)
		g_data.pid_client = info->si_pid;
	if (signum == SIGUSR1)
		g_data.c |= (0x01 << g_data.bit);
	else if (signum == SIGUSR2)
		g_data.c &= ~(0x01 << g_data.bit);
	g_data.bit++;
	if (g_data.bit == CHAR_BIT)
	{
		g_data.bit = 0;
		if (g_data.c == '\0')
		{
			ft_printf("\n");
			ft_kill(g_data.pid_client, SIGUSR2);
			g_data.c = 0;
			return ;
		}
		ft_printf("%c", g_data.c);
		g_data.c = 0;
	}
	usleep(100);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("Format: ./server\n");
		return (EXIT_FAILURE);
	}
	init_data();
	ft_printf("Server PID: %d\n", getpid());
	ft_signal(SIGUSR1, handler, true);
	ft_signal(SIGUSR2, handler, true);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
