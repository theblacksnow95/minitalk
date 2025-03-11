/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:36:36 by emurillo          #+#    #+#             */
/*   Updated: 2025/03/11 17:24:10 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <signal.h>

volatile t_data	g_data;

static void	init_data(void)
{
	int	i;

	g_data.c = 0;
	g_data.bit = 0;
	g_data.pid_client = 0;
	i = 0;
	while (i < MAX_LENGTH)
	{
		g_data.message[i] = 0;
		i++;
	}
	g_data.idx = 0;
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
		g_data.message[g_data.idx] = g_data.c;
		g_data.bit = 0;
		g_data.c = 0;
		if (g_data.message[g_data.idx] == '\0' || g_data.idx == MAX_LENGTH - 1)
		{
			ft_putstr_fd((char *)g_data.message, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
			g_data.idx = 0;
		}
		else
			g_data.idx++;
	}
	kill(g_data.pid_client, SIGUSR1);
	usleep(200);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Format: ./server\n");
		return (EXIT_FAILURE);
	}
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	init_data();
	ft_printf("Server PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
