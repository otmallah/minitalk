/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:12:06 by otmallah          #+#    #+#             */
/*   Updated: 2021/12/14 02:12:07 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

size_t	ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);
void	ft_putnbr(int t);
void	ft_putchar(char c);

static int	g_i;

typedef struct s_glob {
	char	str[7];
}	t_glob;

typedef struct s_test {
	int		i;
	int		j;
	int		a;
	char	*tab;
	pid_t	pid;
}	t_test;

typedef struct s_test2
{
	int		a;
	int		i;
	int		j;
	char	*result;
	char	*result2;
}	t_test2;

#endif
