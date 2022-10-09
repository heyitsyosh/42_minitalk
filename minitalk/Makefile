NAME = minitalk

SERVER = server
CLIENT = client

DIR = ./minitalk_mandatory/
BONUS_DIR = ./minitalk_bonus/
PRINTFDIR = ./lib/printf/

SERVER_SRC = $(DIR)server.c
CLIENT_SRC = $(DIR)client.C

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
B_SERVER_OBJ = $(BONUS_DIR)server_bonus.o
B_CLIENT_OBJ = $(BONUS_DIR)client_bonus.o

OBJS = $(SERVER_OBJ) $(CLIENT_OBJ) $(B_CLIENT_OBJ) $(B_SERVER_OBJ)

ifeq ($(MAKECMDGOALS),bonus)
SERVER_SRC = $(BONUS_DIR)server_bonus.c
CLIENT_SRC = $(BONUS_DIR)client_bonus.c
SERVER_OBJ = $(BONUS_DIR)server_bonus.o
CLIENT_OBJ = $(BONUS_DIR)client_bonus.o
endif

CFLAGS = -Wall -Wextra -Werror -I ./includes

#--------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(SERVER_OBJ) $(CLIENT_OBJ)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER) -L$(PRINTFDIR) -lftprintf
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT) -L$(PRINTFDIR) -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

bonus: all

clean:
	make clean -C $(PRINTFDIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(PRINTFDIR)
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re bonus