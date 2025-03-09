/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:12:28 by yourlogin         #+#    #+#             */
/*   Updated: 2024/10/28 14:03:05 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_printf(const char *format, ...);
int			ft_putchar_int(int c);
int			ft_putstr_fd_int(char const *str, int fd);
int			ft_checkflags(char str, va_list ap, int fd);
int			ft_putnbr(int nb, int fd);
int			ft_putunsigned(unsigned int nb, int fd);
int			ft_putnbrhex_l(unsigned int nb, int fd);
int			ft_putnbrhex_c(unsigned int nb, int fd);
int			ft_putpointer(void *p, int fd);
int			ft_putnbrhex_p(unsigned long long nb, int fd);

#endif
