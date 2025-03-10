/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:36:36 by emurillo          #+#    #+#             */
/*   Updated: 2025/03/10 15:35:10 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <signal.h>

volatile data_t	data;

void	handler(int signum, siginfo_t *info, void *extra_info)
{

	(void)extra_info;
	if (signum == SIGUSR1)
		data.i |= (0x01 << data.bit);
	data.bit++;
	if (data.bit == 8)
	{
		ft_printf("%c", data.i);
		data.i = 0;
		data.bit = 0;
		kill(info->si_pid, SIGUSR2);
	}
	usleep(100);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
