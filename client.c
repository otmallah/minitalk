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
	t_test2	index;

	index.a = 0;
	if (tab >= 32 && tab <= 63)
	{
		index.j = 1;
		index.result = malloc(sizeof(char) * 8);
		index.result2 = malloc(sizeof(char) * 8);
		if (!index.result2 || !index.result)
			return (NULL);
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

char	*ft_sec(char *res, char *res2)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(res);
	while (i--)
	{
		res2[j] = res[i];
		j++;
	}
	free(res);
	res2[j] = '\0';
	return (res2);
}

char	*ft_convert_binary_2(int tab)
{
	t_test2	index;

	index.a = 0;
	index.j = 0;
	index.result = malloc(sizeof(char) * 8);
	index.result2 = malloc(sizeof(char) * 8);
	if (!index.result2 || !index.result)
		return (NULL);
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
	return (ft_sec(index.result, index.result2));
}

int	main(int ac, char **av)
{
	t_test	index;

	index.i = -1;
	if (ac == 3)
	{
		index.pid = ft_atoi(av[1]);
		if (index.pid <= 0)
			exit(1);
		while (av[2][++index.i])
		{
			index.j = -1;
			index.tab = ft_convert_binary((int)av[2][index.i]);
			while (index.tab[++index.j])
			{
				if (index.tab[index.j] == '1')
					kill(index.pid, SIGUSR1);
				else if (index.tab[index.j] == '0')
					kill(index.pid, SIGUSR2);
				usleep(110);
			}
			free(index.tab);
		}
	}
	else
		write (1, "ERROR{404}\n", 11);
}
