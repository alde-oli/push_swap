NAME = push_swap
SRC = main.c check_input.c operations.c operations_mgmt.c simplify_values.c \
      sort_radix.c sort_small.c sort_utils.c stacks_mgmt.c stacks_print.c utils.c utils2.c utils3.c
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -c $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re