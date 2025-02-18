# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 10:58:24 by kseligma          #+#    #+#              #
#    Updated: 2024/02/17 08:11:17 by kseligma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c\
	  ft_printf_specified.c\
	  ft_printf_order.c\
	  ft_printf_write_extra.c\
	  util.c\

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o: %.c ft_printf.h Makefile
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
