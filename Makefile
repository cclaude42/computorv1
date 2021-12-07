###################################
# ComputorV1 : parse and compute polynomial equations
###################################

NAME = computorv1

CC = clang++

CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes

SRC = $(addprefix srcs/, \
		computorv1.cpp parse.cpp solve.cpp)

OBJ = $(SRC:cpp=o)

###################################
# Methods
###################################

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;32m\n\nCompiling computorv1..."
	@$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAME) $(OBJ)
	@echo "\n\033[0mDone !"

%.o: %.cpp
	@printf "\033[0;33mGenerating computorv1 objects... %-20.20s\r" $@
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ) $(OBJB)
	@echo "\nDeleting executable..."
	@rm -f $(NAME) $(NAMEB)
	@echo "\033[0m"

re: fclean all

.PHONY: clean fclean re