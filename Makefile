NAME = minitalk.a

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

AR = @ar -rc

RM = @rm -f

FILES = ft_strlen.c \
		ft_bzero.c \
		server.c \
		client.c\
		ft_atoi.c\
		ft_putnbr.c\
		ft_putchar.c

# Colors
C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_GREEN = \033[1;32m
C_BLUE = \033[1;34m
C_L_BLUE = \033[1;34m
C_WHITE = \033[1;37m
C_RES = \033[0m

OBJS = $(subst .c,.o,$(FILES))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -c $(FILES)
	$(AR) $(NAME) $(OBJS)
	@gcc $(CFLAGS) client.c $(NAME) -o client
	@gcc $(CFLAGS) server.c $(NAME) -o server
	@echo "$(C_GREEN)[SERVER CREATED!]$(C_RES)"
	@echo "$(C_GREEN)[CLIENT CREATED!]$(C_RES)"
	@echo "$(C_GREEN)[LIBRARY CREATED!]$(C_RES)"

clean :
	$(RM) $(OBJS)
	@echo "$(C_RED)[OBJECT DELETED!]$(C_RES)"

fclean : clean
	$(RM)  $(NAME) client server
	@echo "$(C_RED)[MINITALK.A REMOVED!]$(C_RES)"

re : fclean all