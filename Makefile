NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = $(wildcard src/*/*.c) $(wildcard src/*.c)

OBJ_DIR = obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

INCLUDES = -I include

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
