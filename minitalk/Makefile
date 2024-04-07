NAME = minitalk

SERVER = server
CLIENT = client

SRCS_DIR = srcs/
OBJS_DIR = objs/
PRINTF_DIR = lib/printf/
PRINTF = $(PRINTF_DIR)libftprintf.a

SERVER_OBJ = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SERVER)))
CLIENT_OBJ = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(CLIENT)))

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/

#--------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(PRINTF) $(SERVER) $(CLIENT)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(PRINTF):
	make -C $(PRINTF_DIR)

$(SERVER): $(OBJS_DIR) $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(SERVER_OBJ) -o $(SERVER) $(PRINTF)

$(CLIENT): $(OBJS_DIR) $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(CLIENT_OBJ) -o $(CLIENT) $(PRINTF)

clean:
	make clean -C $(PRINTF_DIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	make fclean -C $(PRINTF_DIR)
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
