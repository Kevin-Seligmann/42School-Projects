src_nf = main.c ft_atoi.c ft_putnbr.c mults.c plus_minus.c

hdr_nf = funct.h

srcf = ./srcs

NAME = do-op

source = $(addprefix $(srcf)/, $(src_nf))

objs = $(source:.c=.o)

flags = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(objs)
	cc -o $(NAME) $(objs)

%.o: %.c
	cc -c $(flags) $^ -o $@

clean:
	rm -f $(objs)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
