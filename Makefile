NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = $(wildcard src/*/*.c) $(wildcard src/*.c) 

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INCLUDES = -I include

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re