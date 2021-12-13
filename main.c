#include "header.h"
#include <stdlib.h>

char    ft_putchar(char c)
{
	return (write (1, &c, 1));
}

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

char     *ft_convert_binary(int tab)
{
	int a;
	int i;
	int j;
	char *result;
	char *result2;

	a = 0;
	j = 1;
	result = malloc(sizeof(char) * 9);
	while (tab)
	{
		if (tab % 2 == 1)
			result[a] = '1';
		else
			result[a] = '0';
		tab /= 2;
		a++;
	}
	result[a] = '\0';
	i = strlen(result);
	result2[0] = '0';
	while (i--)
	{
		result2[j] = result[i];
		j++; 
	}
	return result2;
}

// int     convert(char *str)
// {
// 	int i;
// 	int j;
// 	int res2;
// 	int a = strlen(str);
// 	int tab[a];
// 	i = 0;
// 	j = 0;
// 	while (str[i])
// 	{
// 		tab[j]= (int)str[i];
// 		res2 = res2 + ft_convert_binary(tab[j]);
// 		i++;
// 		j++;
// 	}
// 	return res2;
// }

void    client(pid_t pid, char *str)
{
	int i;
	int j;
	char *tab;

	i = 0;
	tab = malloc(sizeof(char) * 8);
	while (str[i])
	{
		j = 0;
		tab = ft_convert_binary((int)str[i]); 
		// printf("%s\n", tab);
		j = strlen(tab);
		while (j--)
		{
			if (tab[j] == '1')
			{
				kill(pid, SIGUSR1);
				usleep(100);
			}
			else if (tab[j] == '0')
			{
				kill(pid, SIGUSR2);
				usleep(100);
			}
		}
		free(tab);
		i++;
	}
}

int main(int ac, char **av)
{ 
	// printf("%s" , ft_convert_binary(49));
	client(atoi(av[1]) , av[2]);
}