NAME = push_swap
NAME_BONUS = checker

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = $(wildcard src/*/*.c) src/main.c
SRC_BONUS = $(wildcard src/*/*.c) src/main_bonus.c

OBJ_DIR = obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR)%.o)

INCLUDES = -I include

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

bonus: $(OBJ_BONUS)
	@gcc $(FLAGS) $(INCLUDES) $(OBJ_BONUS) -o $(NAME_BONUS)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
