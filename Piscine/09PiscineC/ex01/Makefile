src_nf = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

hdr_nf = ft.h

srcf = ./srcs

incf = includes

NAME = libft.a

source = $(addprefix $(srcf)/, $(src_nf))

objs = $(source:.c=.o)

includes = $(addprefix $(incf)/, $(hdr_nf))

flags = -Wall -Wextra -Werror

all: $(NAME)

libft.a: $(objs)
	ar -rc $(NAME) $(objs)

%.o: %.c
	cc -c -I $(incf) $(flags) $^ -o $@

clean:
	rm -f $(objs)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
