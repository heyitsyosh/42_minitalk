NAME     := libftprintf.a

CFLAGS   := -Wall -Wextra -Werror
INCLUDES := -I ../../includes

OBJS_DIR := objs
LIBFT_DIR := ../libft

SRCS     := ft_printf \
            print_str_char \
            num_to_arr \
            print_num_arr \
            flags
OBJS     := $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(SRCS)))

# **************************************************************************** #

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
