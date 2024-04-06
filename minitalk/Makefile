NAME = minitalk

SERVER = server
CLIENT = client

SRCSDIR = srcs/
OBJSDIR = objs/
PRINTFDIR = lib/printf/
PRINTF = $(PRINTFDIR)libftprintf.a

SERVER_SRC = $(SRCSDIR)server.c
CLIENT_SRC = $(SRCSDIR)client.c

SERVER_OBJ = $(SERVER_SRC:$(SRCSDIR)%.c=$(OBJSDIR)%.o)
CLIENT_OBJ = $(CLIENT_SRC:$(SRCSDIR)%.c=$(OBJSDIR)%.o)

OBJS = $(SERVER_OBJ) $(CLIENT_OBJ)

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/

#--------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(PRINTF) $(SERVER) $(CLIENT)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

$(SERVER): $(OBJSDIR) $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(SERVER_OBJ) -o $(SERVER) $(PRINTF)

$(CLIENT): $(OBJSDIR) $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(CLIENT_OBJ) -o $(CLIENT) $(PRINTF)

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(PRINTF):
	make -C $(PRINTFDIR)

clean:
	make clean -C $(PRINTFDIR)
	$(RM) $(OBJS)
	$(RM) -r $(OBJSDIR)

fclean: clean
	make fclean -C $(PRINTFDIR)
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re