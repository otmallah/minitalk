/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:35:58 by otmallah          #+#    #+#             */
/*   Updated: 2021/12/14 01:36:00 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

	index.str[i] = '0';
	if (strlen(index.str) == 7)
	{
		res = (char)ft_conver_bin_to_dec(index.str);
		write(1, &res, 1);
		ft_bzero(index.str, 7);
		i = -1;
	}
	i++;
}

void	ft_get_usr1(int sum)
{
	t_glob		index;
	char		res;

	index.str[i] = '1';
	if (strlen(index.str) == 7)
	{
		res = (char )ft_conver_bin_to_dec(index.str);
		write(1, &res, 1);
		ft_bzero(index.str, 7);
		i = -1;
	}
	i++;
}

void	server()
{
	signal(SIGUSR1, ft_get_usr1);
	signal(SIGUSR2, ft_get_usr2);
	while(1);
}