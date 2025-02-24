VPATH = src

# Files
OBJ = hello.o ft_strlen.o ft_strcpy.o ft_strcmp.o ft_write.o\
	ft_read.o ft_strdup.o ft_atoi_base.o ft_list_push_front.o ft_list_size.o\
	ft_list_sort.o ft_list_remove_if.o

# Target
NAME = libasm.a

# Project
PROJ = libasm

# Directories
OBJ_DIR = obj

INC_DIR = inc

OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))

# DEPS = $(OBJ_PATH:.o=.d)

# Include
INCLUDES = -I./$(INC_DIR)

# Compilation Flags
CFLAGS = -f elf64

# Linker flags
LFLAGS = -pie

# Linker
LK = ar rcs

# Compiler
CC = nasm

# Colors
YELLOW = "\e[33m"
GREEN = "\e[32m"
NO_COLOR = "\e[0m"

# Linking
all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ_PATH) Makefile
	@$(LK) $(NAME) $(OBJ_PATH) 
	@echo $(YELLOW)$(PROJ) - Creating exec:$(NO_COLOR) $(NAME)

# Compilation
$(OBJ_DIR)/%.o:%.s
	@$(CC) $(INCLUDES) $(CFLAGS) $< -o $@
	@echo $(YELLOW)$(PROJ) - Compiling object file:$(NO_COLOR) $(notdir $@)

# Utils
-include $(DEPS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR) tester
	@echo $(YELLOW)$(PROJ) - Removing:$(NO_COLOR) Object and dependency files

fclean: clean
	@rm -rf $(NAME) $(NAME_B)
	@echo $(YELLOW)$(PROJ) - Removing:$(NO_COLOR) $(NAME) $(NAME_B)

re: fclean all

tester: all
	cc -z noexecstack -g src/main.c libasm.a -o tester

.PHONY: clean fclean all re $(OBJ_DIR)
