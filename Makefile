NAME    = SO_LONG
CFLAGS  = -Wall -Wextra -Werror -g
SRC		= main.c src/maps.c
OBJ		= ${SRC:.c=.o}
LIBFT = src/libft/libft.a
INC = -I includes/ 
MLX = src/MLX42/libmlx42.a

COLOUR_GREEN=\033[0;32m
COLOUR_END=\033[0m

BREW = "/Users/$(USER)/.brew/opt/glfw/lib/"

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	@gcc $(CFLAGS) $(OBJ) $(MLX) -lglfw -L $(BREW) $(INC) -o $(NAME) $(LIBFT)
	@echo "$(COLOUR_GREEN)🔥 🔥 Compliling Everything ✅ ✅$(COLOUR_END)"

$(LIBFT):
	@make -C src/libft

$(MLX):
	@make -C src/MLX42/
clean:
	@rm -rf $(OBJ)
	@make -C src/MLX42/ clean
	@make -C src/libft/ clean
fclean: clean
	@rm -f $(NAME)
	@make -C src/MLX42/ fclean
	@make -C src/libft/ fclean

%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $<

re: fclean all

.PHONY: all clean fclean re mlx42