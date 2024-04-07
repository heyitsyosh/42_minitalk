NAME = minitalk

SERVER = server
CLIENT = client

DIR = ./minitalk_mandatory/
BONUS_DIR = ./minitalk_bonus/
PRINTF_DIR = ./lib/printf/
PRINTF = $(PRINTF_DIR)libftprintf.a

SERVER_OBJ = $(DIR)server.o
CLIENT_OBJ = $(DIR)client.o
B_SERVER_OBJ = $(BONUS_DIR)server_bonus.o
B_CLIENT_OBJ = $(BONUS_DIR)client_bonus.o

OBJS = $(SERVER_OBJ) $(CLIENT_OBJ) $(B_CLIENT_OBJ) $(B_SERVER_OBJ)

ifeq ($(MAKECMDGOALS),bonus)
SERVER_OBJ = $(B_SERVER_OBJ)
CLIENT_OBJ = $(B_CLIENT_OBJ)
endif

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./includes

#--------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(PRINTF) $(SERVER) $(CLIENT)

$(PRINTF):
	make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(SERVER_OBJ) -o $(SERVER) $(PRINTF)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(CLIENT_OBJ) -o $(CLIENT) $(PRINTF)

bonus: all

clean:
	make clean -C $(PRINTF_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(PRINTF_DIR)
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all bonus clean fclean re
