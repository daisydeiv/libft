NAME = libftprintf.a

CC = cc
FLAGS = -Wextra -Werror -Wall

SRCS = ft_printf.c print_char.c print_string.c print_num.c print_unsigned.c \
	print_lowhex.c print_uphex.c print_pointer.c \
	utoa.c hexa_convert.c \
	ft_itoa.c ft_putstr_fd.c ft_toupper.c ft_strlen.c

OBJS := ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re