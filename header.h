#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void    handler(int sum);
void            client(pid_t pid, char *str);
size_t ft_strlen(char *str);
size_t ft_strle(char *str);
void	ft_putnbr_fd(int n, int fd);
int	ft_count_int(int numb);
void	ft_bzero(void *s, size_t n);