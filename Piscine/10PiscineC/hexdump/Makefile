#Directories
SRC_DIR = src

#Source files
OBJ = hexdump.o flag.o error.o utils.o get_next_byte.o fill_buffer.o

#Flags
FLAGS = -Wall -Wextra -Werror

#Compiler
CC = cc

#Target name
NAME = ft_hexdump

#Colors
YELLOW = "\e[33m"
GREEN = "\e[32m"
NO_COLOR = "\e[0m"

all: $(NAME)

$(NAME): $(OBJ) Makefile
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo $(YELLOW)ft_cat - Creating exec:$(NO_COLOR) $(NAME)

%.o:%.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo $(YELLOW)ft_cat - Compiling object file:$(NO_COLOR) $(notdir $@)

clean:
	@rm -f $(OBJ)
	@echo $(YELLOW)ft_cat - Removing:$(NO_COLOR) Object files

fclean: clean
	@echo $(YELLOW)ft_cat - Removing:$(NO_COLOR) $(NAME)
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
