
NAME = so_long

CC = cc

SRC = ./src/so_long.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

COMP_LIBFT = cd ./utils/libft && make

COMP_MLX = cd ./minilibx-linux && make

LIBFT = -L ./utils/libft -lft

MLX = -L ./minilibx-linux -lmlx -lXext -lX11

MAKEFLAGS += -s

all: $(NAME)

$(NAME): $(OBJ)
	$(COMP_LIBFT)
	$(COMP_MLX)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(MLX)

val: all
	valgrind --leack-check=full -s --show-leak-kinds=all --track-origins=yes ./$(NAME) map/map.ber

%.o: ./src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	cd ./utils/libft && make fclean
	cd ./minilibx-linux && make clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re val
