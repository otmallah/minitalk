/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:02:09 by otmallah          #+#    #+#             */
/*   Updated: 2021/12/14 17:02:10 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	g_i;

int	ft_power(int nb, int power)
{
	int	x;

	x = 1;
	if (power == 0 || nb == 1)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	while (power > 0)
	{
		x = x * nb;
		power--;
	}
	return (x);
}

int	ft_conver_bin_to_dec(char	*str)
{
	int		i;
	int		a;
	int		j;
	int		res;

	a = 0;
	j = 0;
	res = 0;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == '1')
			res = res + ft_power(2, a);
		a++;
		i--;
	}
	return (res);
}

void	ft_get_usr2(int sum)
{
	t_glob	index;
	char	res;

	if  (sum == SIGUSR2)
	{
		index.str[g_i] = '0';
		if (ft_strlen(index.str) == 7)
		{
			res = (unsigned char)ft_conver_bin_to_dec(index.str);
			write(1, &res, 1);
			ft_bzero(index.str, 7);
			g_i = -1;
		}
	}
	g_i++;
}

void	ft_get_usr1(int num)
{
	t_glob	index;
	char	res;

	if (num == SIGUSR1)
	{
		index.str[g_i] = '1';
		if (ft_strlen(index.str) == 7)
		{
			res = (unsigned char )ft_conver_bin_to_dec(index.str);
			write(1, &res, 1);
			ft_bzero(index.str, 7);
			g_i = -1;
		}
	}
	g_i++;
}

void	server(void)
{
	signal(SIGUSR1, ft_get_usr1);
	signal(SIGUSR2, ft_get_usr2);
	while (1)
		pause();
}

int main(void)
{
	printf("%d\n" , getpid());
	server();
}