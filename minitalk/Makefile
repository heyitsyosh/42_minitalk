NAME = minitalk

SERVER = server
CLIENT = client

DIR = ./minitalk_mandatory/
BONUS_DIR = ./minitalk_bonus/
PRINTF_DIR = ./lib/printf/
PRINTF = $(PRINTF_DIR)libftprintf.a

SERVER_SRC = $(DIR)server.c
CLIENT_SRC = $(DIR)client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
B_SERVER_OBJ = $(BONUS_DIR)server_bonus.o
B_CLIENT_OBJ = $(BONUS_DIR)client_bonus.o

OBJS = $(SERVER_OBJ) $(CLIENT_OBJ) $(B_CLIENT_OBJ) $(B_SERVER_OBJ)

ifeq ($(MAKECMDGOALS),bonus)
SERVER_SRC = $(BONUS_DIR)server_bonus.c
CLIENT_SRC = $(BONUS_DIR)client_bonus.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
endif

CFLAGS = -Wall -Wextra -Werror -I ./includes

#--------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(PRINTF) $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER) $(PRINTF)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT) $(PRINTF)

$(PRINTF):
	make -C $(PRINTF_DIR)

bonus: all

clean:
	make clean -C $(PRINTF_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(PRINTF_DIR)
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all bonus clean fclean re
