/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:37:04 by emurillo          #+#    #+#             */
/*   Updated: 2025/03/10 18:43:14 by emurillo         ###   ########.fr       */
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

typedef struct signal_data
{
	char	c;
	int		bit;
	pid_t	pid_client;
}				t_data;

void	ft_signal(int sig, void *handler, bool use_siginfo);
void	ft_kill(pid_t pid, int signum);

#endif
