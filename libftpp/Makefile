# Utilities folders
UTILITIES = pool data_buffer memento observer singleton state_machine thread_safe_iostream \
	thread_safe_queue thread worker_pool persistent_worker network i_vector2 i_vector3 \
	random_2d_coordinate_generator perlin_noise_2d

# Utilities .cpp files
R_OBJ = data_buffer.o memento.o thread_safe_iostream.o thread.o worker_pool.o persistent_worker.o \
	message.o client.o server.o connection.o random_2d_coordinate_generator.o perlin_noise_2d.o

# Vpath
VPATH = $(addprefix $(UTILITIES_DIR)/, $(UTILITIES))

# Target
NAME = libftpp.a

# Project
PROJ = Libftpp

# Files
OBJ = $(addprefix $(UTILITIES_DIR)/, $(R_OBJ))

# Directories
UTILITIES_DIR = utilities

OBJ_DIR = obj

INC_DIR = inc $(addprefix $(UTILITIES_DIR)/, $(UTILITIES))

OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(R_OBJ))

DEPS = $(OBJ_PATH:.o=.d)

# Include
INCLUDES = $(addprefix -I, $(INC_DIR))

# Flags
FLAGS = -Wall -Wextra -Werror

# Compiler
CC = c++

# Lib
LIB = ar -rc

# Colors
YELLOW = "\e[33m"
GREEN = "\e[32m"
NO_COLOR = "\e[0m"

# Linking
all: $(OBJ_DIR) $(NAME)
	
$(NAME): $(OBJ_PATH) Makefile
	@$(LIB) $(NAME) $(OBJ_PATH)
	@echo $(YELLOW)$(PROJ) - Creating static lib:$(NO_COLOR) $(NAME)

# Compilation
$(OBJ_DIR)/%.o:%.cpp
	@$(CC) -MMD $(INCLUDES) $(FLAGS) -c $< -o $@
	@echo $(YELLOW)$(PROJ) - Compiling object file:$(NO_COLOR) $(notdir $@)

# Utils
-include $(DEPS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo $(YELLOW)$(PROJ) - Removing:$(NO_COLOR) Object and dependency files

fclean: clean
	@rm -rf $(NAME) $(NAME_B)
	@echo $(YELLOW)$(PROJ) - Removing:$(NO_COLOR) $(NAME) $(NAME_B)

re: fclean all

.PHONY: clean fclean all re $(OBJ_DIR)
