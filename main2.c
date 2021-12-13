#include <unistd.h>
#include <stdio.h>

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
	int res = 0;

	a = 0;
	j = 0;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == '1') {
			res = res + ft_power(2 , a);
		}
		a++;
		i--;
	}
	return res;
}

#include <signal.h>
#include "header.h"
#include <stdlib.h>

typedef struct s_glob {
	char str[7];
}	t_glob;

static int i;

void   GET(int sum)
{
	t_glob index;
	index.str[i] = '1';
	if (strlen(index.str) == 7) {
		printf("%c\n" , (char)ft_conver_bin_to_dec(index.str));
		// printf("i : [%d]\n", i);
		ft_bzero(index.str, 7);
		i = -1;
	}
	i++;
}

void   GET2(int sum)
{
	t_glob index;
	index.str[i] = '0';
	if (strlen(index.str) == 7) {
		printf("%c\n" , (char)ft_conver_bin_to_dec(index.str));
		ft_bzero(index.str, 7);
		// printf("i : [%d]\n", i);
		i = -1;
	}
	i++;
}

void    server()
{
	signal(SIGUSR1, GET);
	signal(SIGUSR2, GET2);
	while(1);
}

int main(void)
{
	// ft_conver_bin_to_dec("1100001");
	printf("%d\n" , getpid());
	server();
}