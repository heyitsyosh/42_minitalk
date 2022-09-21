NAME = minitalk
SERVER = server
CLIENT = client

LIBFTDIR = ../lib/libft/
PRINTFDIR = ../lib/printf/

CLIENT_SRC = client.c
SERVER_SRC = server.c
OBJS = client.o\
	server.o

LIBFT = ../lib/libft/libft.a -I ../lib/libft
FT_PRINTF = ../lib/printf/libftprintf.a -I ../lib/printf
MINITALK = -I ./

CFLAGS = -Wall -Wextra -Werror

/* -------------------------------------------------------------------------- */

all: $(SERVER) $(CLIENT)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	make -C $(PRINTFDIR)

bonus: all

clean:
	make clean -C $(LIBFTDIR)
	make clean -C $(PRINTFDIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus