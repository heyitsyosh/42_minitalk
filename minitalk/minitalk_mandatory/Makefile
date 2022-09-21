NAME = minitalk
SERVER = server
CLIENT = client

LIBFTDIR = ../lib/libft/
PRINTFDIR = ../lib/printf/

CLIENT_SRC = client.c
SERVER_SRC = server.c
OBJS = client.o\
		server.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = ../lib/libft/libft.a -I ../lib/libft
FT_PRINTF = ../lib/printf/libftprintf.a -I ../lib/printf
MINITALK = -I ./

#--------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) -o $(SERVER)
	$(CC) $(CFLAGS) -o $(CLIENT)

clean:
	make clean -C $(PRINTFDIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(PRINTFDIR)
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re bonus