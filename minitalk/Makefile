NAME = minitalk

SERVER = server
CLIENT = client

SERVER_SRC = ./minitalk_mandatory/server.c
CLIENT_SRC = ./minitalk_mandatory/client.c

OBJS = server.o client.o

LIBFTDIR = ./lib/libft/
PRINTFDIR = ./lib/printf/

CFLAGS = -Wall -Wextra -Werror -I ./includes

ifeq ($(MAKECMDGOALS),bonus)
SERVER_SRC = ./minitalk_bonus/server_bonus.c
CLIENT_SRC = ./minitalk_bonus/client_bonus.c
OBJS = client_bonus.o server_bonus.o
endif

#--------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) -o $(SERVER) -Lft_printf -lftprintf minitalk_server.o
	$(CC) $(CFLAGS) -o $(CLIENT) -Lft_printf -lftprintf minitalk_client.o

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

bonus:
	$(MAKE) WITH_BONUS=1

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	$(MAKE) clean -C $(PRINTFDIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./ft_printf
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re bonus