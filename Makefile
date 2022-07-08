NAME			=	so_long
NAME_BONUS		=	so_long_bonus

PATH_LIBFT		= 	./lib/libft
LIBFT			= 	$(PATH_LIBFT)/libft.a

MLX_PATH		= 	./lib/minilibx
MLX				= 	$(MLX_PATH)/libmlx.a

I_OBJ			=	-I ./ -I ./lib/minilibx/ -I ./lib/libft/
LINKS			=	-I ./ -I ./lib/minilibx/ -L./lib/minilibx/ -lmlx -I ./lib/libft/ -L./lib/libft/ -lft

CC				= 	clang
CFLAGS			= 	-Wall -Werror -Wextra -g
MLX_FLAGS		= 	-L. -lXext -L. -lX11 -L. -lm

SRC_DIR			= 	src
SRC_FILES		=	so_long.c \
					map_built.c \
					map_validation.c \
					map_validation_utils.c \
					map_to_win.c \
					img_setup.c \
					key_events.c \
					game_setup.c \
					game_exit.c
SRC				= 	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

SRC_DIR_BONUS	=	src_bonus
SRC_FILES_BONUS	=	so_long_bonus.c \
					map_built_bonus.c \
					map_validation_bonus.c \
					map_validation_utils_bonus.c \
					img_setup_bonus.c \
					map_to_win_bonus.c \
					game_setup_bonus.c \
					key_events_bonus.c \
					game_exit_bonus.c \
					animation.c \
					patrol_mov_x.c \
					patrol_mov_y.c \
					score_bonus.c \
					img_anime.c \
					patrol_mov_xy.c
SRC_BONUS				= 	$(addprefix $(SRC_DIR_BONUS)/, $(SRC_FILES_BONUS))

OBJ_DIR			= 	objects
OBJ				= 	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

OBJ_DIR_BONUS	= 	objects_bonus
OBJ_BONUS		= 	$(SRC_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR_BONUS)/%.o)

HEADER			= 	so_long.h
HEADER_BONUS	=	so_long_bonus.h

FS				=	-fsanitize=address -g3

all:	$(NAME)

bonus:	$(NAME_BONUS)

$(NAME):	$(LIBFT) $(MLX) $(OBJ_DIR) $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ)  $(MLX_FLAGS) $(LINKS) -o $(NAME)

$(NAME_BONUS):	$(LIBFT) $(MLX) $(OBJ_DIR_BONUS) $(OBJ_BONUS) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS)  $(MLX_FLAGS) $(LINKS) -o $(NAME_BONUS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(I_OBJ)

$(OBJ_DIR_BONUS)/%.o:	$(SRC_DIR_BONUS)/%.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@ $(I_OBJ)

$(LIBFT):
	make -C $(PATH_LIBFT)

$(MLX):
	make -C $(MLX_PATH)

$(OBJ_DIR):
	mkdir objects

$(OBJ_DIR_BONUS):
	mkdir objects_bonus

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_BONUS)
	rm -rf $(OBJ_DIR_BONUS)
	make -C $(PATH_LIBFT) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	make -C $(PATH_LIBFT) fclean

re: fclean all

re_bonus: fclean bonus

run:
	make fclean
	make && ./so_long ./maps/basic3.ber

run_bonus:
	make fclean
	make bonus && ./so_long_bonus ./maps_bonus/basic_bonus3.ber

sanitize:	$(LIBFT) $(MLX) $(OBJ) $(HEADER)
	$(CC) $(FS) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

valgrind: $(NAME)
	make re
	valgrind --leak-check=full --show-leak-kinds=all ./so_long ./maps/basic3.ber

valgrind_bonus: $(NAME_BONUS)
	make re_bonus
	valgrind --leak-check=full --show-leak-kinds=all ./so_long_bonus ./maps_bonus/basic_bonus3.ber
