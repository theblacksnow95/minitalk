/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:59:45 by emurillo          #+#    #+#             */
/*   Updated: 2025/03/11 10:56:38 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"


void	ft_signal(int sig, void *handler, bool use_siginfo)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	if (use_siginfo)
	{
		sa.sa_sigaction = handler;
		sa.sa_flags = SA_SIGINFO;
	}
	else
		sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(sig, &sa, NULL) < 0)
	{
		perror("Signal handler setup failed");
		exit(EXIT_FAILURE);
	}
}

void	ft_kill(pid_t pid, int signum)
{
	if (kill(pid, signum) < 0)
	{
		perror("Transmission failed");
		exit(EXIT_FAILURE);
	}
}
