/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:52:50 by otmallah          #+#    #+#             */
/*   Updated: 2021/12/10 16:52:51 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int glb;

size_t ft_strle(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

void    ft_putchar(char c)
{
	write (1, &c, 1);
}

int     ft_convert_binary(int tab)
{
	int a;
	int j;
	char s[]="01";
	char taab[10];

	a = 0;
	//tab /= 2;
	while (tab)
	{
		taab[a] = s[tab % 2];
		tab /= 2;
		a++;
	}
	taab[a] = '\0';
	j = ft_strle(taab) - 1;
	while (j >= 0)
	{
		ft_putchar(taab[j]);
		j--;
	}
	return 1;
}

void     convert(char *str)
{
	int i;
	int j;
	int a = ft_strle(str);
	int tab[a];
	i = 0;
	j = 0;
	while (str[i])
	{
		tab[j]= (int)str[i];
		ft_convert_binary(tab[j]);
		i++;
		j++;
	}
}

void	handler(int sum)
{
	if (sum == SIGUSR1)
	{
		printf("%s" );
	}
}

void	client(pid_t pid, char *str)
{
	signal(SIGUSR1, handler);
	kill(pid, SIGUSR1);
}

int main(int ac, char **av)
{
	pid_t i = atoi(av[1]);
	client(i , av[2]);
}

// #include <stdio.h>
// #include <wchar.h>
// #include <locale.h>

// void hande(int sin) {
//     setlocale(LC_CTYPE, "");
//     wchar_t star = 0x2605;
//     wprintf(L"%lc\n", star);
// }

// int main(int ac, char **av)
// {
//     pid_t i = atoi(av[1]);
//     signal(SIGUSR1, hande);
//     kill(i, SIGUSR1);
// }