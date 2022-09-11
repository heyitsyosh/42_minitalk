NAME = minitalk
SERVER = server
CLIENT = client

LIBFTDIR = ./libft

CLIENT_SRC = 
SERVER_SRC = 
CLIENT_OBJS =
SERVER_OBS = 

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I libft.h

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