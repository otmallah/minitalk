/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:57:36 by otmallah          #+#    #+#             */
/*   Updated: 2021/12/10 16:57:37 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    handler(int sum);

size_t ft_strlen(char *str)
{
		size_t i;

		i = 0;
		while (str[i])
				i++;
		return i;
}

int     ft_power(int nb, int power)
{
		int     x;

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

int  ft_conver_bin_to_dec(char  *str)
{
		int i;
		int a;
		int j;
		int res;

		a = 0;
		j = 0;
		i = ft_strlen(str) - 1;
		while (str[i])
		{
				if (str[i] == '1') {
						res = res + ft_power(2 , a);
				}
				a++;
				i--;
		}
		return res;
}

void  handel(int sig)
{
	void *str;
	int   i;

	str = signandl(SIGUSR1, h);
	printf("%c\n" , (char)ft_conver_bin_to_dec(str));
}

void  server()
{
	signal(SIGUSR1, handel);
	printf("%d" , getpid());
	while (1)
		pause();
}

int main(void)
{
	server();
}