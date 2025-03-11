/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:37:04 by emurillo          #+#    #+#             */
/*   Updated: 2025/03/11 15:25:43 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "../lib/libft/libft.h"
# define MAX_LENGTH 1024

typedef struct signal_data
{
	char	c;
	int		bit;
	pid_t	pid_client;
	char	message[MAX_LENGTH];
	int		idx;
}				t_data;

void	ft_signal(int sig, void *handler, bool use_siginfo);
void	ft_kill(pid_t pid, int signum);

#endif
