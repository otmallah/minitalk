NAME = minitalk.a

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

AR = @ar -rc

RM = @rm

FILES = ft_strlen.c \
		ft_bzero.c

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
	@echo "$(C_GREEN)[LIBRARY CREATED!]$(C_RES)"

server : server.c
	@gcc $(CFLAGS) server.c $(NAME) -o server
	@echo "$(C_GREEN)[SERVER CREATED!]$(C_RES)"

client : client.c
	@gcc $(CFLAGS) client.c $(NAME) -o client
	@echo "$(C_GREEN)[CLIENT CREATED!]$(C_RES)"

clean :
	$(RM) $(OBJS) client server
	@echo "$(C_RED)[OBJECT DELETED!]$(C_RES)"

fclean :
	$(RM) $(NAME)
	@echo "$(C_RED)[MINITALK.A REMOVED!]$(C_RES)"

re : fclean all