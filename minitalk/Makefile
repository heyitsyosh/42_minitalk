NAME = minitalk

SERVER = server
CLIENT = client

SRCSDIR = srcs/
OBJSDIR = objs/
PRINTFDIR = lib/printf/
PRINTF = $(PRINTFDIR)libftprintf.a

SERVER_OBJ = $(addprefix $(OBJSDIR), $(addsuffix .o, $(SERVER)))
CLIENT_OBJ = $(addprefix $(OBJSDIR), $(addsuffix .o, $(CLIENT)))

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
	$(RM) -r $(OBJSDIR)

fclean: clean
	make fclean -C $(PRINTFDIR)
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re