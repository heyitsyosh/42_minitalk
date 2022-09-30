NAME = minitalk

SERVER = server
CLIENT = client

SERVER_SRC = ./minitalk_mandatory/server.c
CLIENT_SRC = ./minitalk_mandatory/client.c

SERVER_OBJ = ./minitalk_mandatory/server.o
CLIENT_OBJ = ./minitalk_mandatory/client.o

PRINTFDIR = ./lib/printf/

CFLAGS = -Wall -Wextra -Werror -I ./includes

ifeq ($(MAKECMDGOALS),bonus)
SERVER_SRC = ./minitalk_bonus/server_bonus.c
CLIENT_SRC = ./minitalk_bonus/client_bonus.c
SERVER_OBJ = ./minitalk_bonus/server_bonus.o
CLIENT_OBJ = ./minitalk_bonus/client_bonus.o
endif

#--------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(SERVER_OBJ) $(CLIENT_OBJ)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER) -L$(PRINTFDIR) -llibftprintf
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT) -L$(PRINTFDIR) -llibftprintf

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

bonus: all

clean:
	$(MAKE) clean -C $(PRINTFDIR)
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	$(MAKE) fclean -C $(PRINTFDIR)
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re bonus