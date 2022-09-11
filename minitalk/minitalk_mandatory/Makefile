NAME = minitalk
SERVER = server
CLIENT = client

LIBFTDIR = ./libft

CLIENT_SRC = client.c
SERVER_SRC = server.c
CLIENT_OBJ = client.o
SERVER_OBS = server.o

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./libft/libft.h -I minitalk.h

/* -------------------------------------------------------------------------- */

all: $(SERVER) $(CLIENT)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)

bonus: all

clean:
	make clean -C $(LIBFTDIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus