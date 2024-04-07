NAME = libftprintf.a

LIBFT_DIR = ../libft

SRCS_ = ft_printf\
		print_str_char\
		num_to_arr\
		print_num_arr\
		flags

SRCS = $(addsuffix .c, $(SRCS_))
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ../../includes/libft.h

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	cp ../libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

bonus: all

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
