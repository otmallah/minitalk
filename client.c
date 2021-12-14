#include "header.h"
#include <stdlib.h>

char     *ft_convert_binary_2(int tab);

char     *ft_convert_binary(int tab)
{
	int a;
	int i;
	int j;
	char *result;
	char *result2;

	a = 0;
	if (tab >= 32 && tab <= 63)
	{
		j = 1;
		result = malloc(sizeof(char) * 8);
		result2 = malloc(sizeof(char) * 9);
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
		free(result);
		result2[j] = '\0';
	}
	else
		return ft_convert_binary_2(tab);
	return result2;
}

char     *ft_convert_binary_2(int tab)
{
	int a;
	int i;
	int j;
	char *result;
	char *result2;

	a = 0;
	j = 0;
	result = malloc(sizeof(char) * 8);
	result2 = malloc(sizeof(char) * 8);
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
	while (i--)
	{
		result2[j] = result[i];
		j++; 
	}
	result2[j] = '\0';
	free(result);
	return result2;
}

void    client(pid_t pid, char *str)
{
	int i;
	int j;
	int a;
	char *tab;

	i = 0;
	tab = malloc(sizeof(char) * 8);
	while (str[i])
	{
		j = 0;
		tab = ft_convert_binary((int)str[i]); 
		// j = strlen(tab);
		while (tab[j])
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
			j++;
		}
		free(tab);
		i++;
	}
}

int main(int ac, char **av)
{ 
	// printf("%s" , ft_convert_binary(100));
	client(atoi(av[1]) , av[2]);
	//system("leaks a.out");
}