/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:17:23 by otmallah          #+#    #+#             */
/*   Updated: 2021/12/14 02:17:25 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_convert_binary_2(int tab);

char	*norme(int taab, char *res)
{
	int		a;

	a = 0;
	while (taab)
	{
		if (taab % 2 == 1)
			res[a] = '1';
		else
			res[a] = '0';
		taab /= 2;
		a++;
	}
	res[a] = '\0';
	return (res);
}

char	*ft_convert_binary(int tab)
{
	t_test3	index;

	index.a = 0;
	if (tab >= 32 && tab <= 63)
	{
		index.j = 1;
		index.result = calloc(sizeof(char), 8);
		index.result2 = calloc(sizeof(char), 8);
		index.result = norme(tab, index.result);
		index.result2[0] = '0';
		index.i = ft_strlen(index.result);
		while (index.i--)
		{
			index.result2[index.j] = index.result[index.i];
			index.j++;
		}
		free(index.result);
		index.result2[index.j] = '\0';
	}
	else
		return (ft_convert_binary_2(tab));
	return (index.result2);
}

char	*ft_convert_binary_2(int tab)
{
	t_test2	index;

	index.a = 0;
	index.j = 0;
	index.result = calloc(sizeof(char), 8);
	index.result2 = calloc(sizeof(char), 8);
	while (tab)
	{
		if (tab % 2 == 1)
			index.result[index.a] = '1';
		else
			index.result[index.a] = '0';
		tab /= 2;
		index.a++;
	}
	index.result[index.a] = '\0';
	index.i = ft_strlen(index.result);
	while (index.i--)
	{
		index.result2[index.j] = index.result[index.i];
		index.j++;
	}
	free(index.result);
	index.result2[index.j] = '\0';
	return (index.result2);
}

void	client(pid_t pid, char *str)
{
	t_test	index;

	index.i = 0;
	if (pid == -1)
		exit(1);
	index.tab = malloc(sizeof(char) * 8);
	while (str[index.i])
	{
		index.j = 0;
		index.tab = ft_convert_binary((int)str[index.i]);
		while (index.tab[index.j])
		{
			if (index.tab[index.j] == '1')
				kill(pid, SIGUSR1);
			else if (index.tab[index.j] == '0')
				kill(pid, SIGUSR2);
			usleep(100);
			index.j++;
		}
		free(index.tab);
		index.i++;
	}
}

int main(int ac, char **av)
{ 
	if (ac == 3)
	client(atoi(av[1]) , av[2]);
	else
		puts("ERR{404}");
}