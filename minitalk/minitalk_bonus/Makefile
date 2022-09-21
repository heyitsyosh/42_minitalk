NAME = minitalk
SERVER = server
CLIENT = client

LIBFTDIR = ../lib/libft/
PRINTFDIR = ../lib/printf/

CLIENT_SRC = client_bonus.c
SERVER_SRC = server_bonus.c
OBJS = client_bonus.o\
	server_bonus.o

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