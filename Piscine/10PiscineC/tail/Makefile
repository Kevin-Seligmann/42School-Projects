#Source files
OBJ = parse.o print_tails.o tail.o util.o

#Flags
FLAGS = -Wall -Wextra -Werror

#Compiler
CC = cc

#Target name
NAME = ft_tail

#Colors
YELLOW = "\e[33m"
GREEN = "\e[32m"
NO_COLOR = "\e[0m"

all: $(NAME)

$(NAME): $(OBJ) Makefile
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo $(YELLOW)ft_tail - Creating exec:$(NO_COLOR) $(NAME)

%.o:%.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo $(YELLOW)ft_tail - Compiling object file:$(NO_COLOR) $(notdir $@)

clean:
	@rm -f $(OBJ)
	@echo $(YELLOW)ft_tail - Removing:$(NO_COLOR) Object files

fclean: clean
	@echo $(YELLOW)ft_tail - Removing:$(NO_COLOR) $(NAME)
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
