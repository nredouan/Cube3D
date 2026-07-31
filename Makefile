NAME		= cub3D
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

OBJ_DIR		= obj

VPATH		= src:src/parser:src/draw:src/raycasting:src/hook:src/init_game

SRCS 		=	main.c \
				map.c \
				set_id.c \
				t_map.c \
				parser.c \
				set_fandc.c \
				get_data.c \
				parser_utils.c \
				utils.c \
				draw.c \
				draw_map.c \
				draw_view.c \
				raycasting.c \
				key_hook.c \
				hook.c \
				init.c \
				map_utils.c \
				id_utils.c \

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

MLX_DIR		= includes/MacroLibX
MLX_REPO    = https://github.com/seekrs/MacroLibX.git
MLX_VERSION = ddfbe32

LIBFT_DIR	= includes/libft
LIBMLX		= MacroLibX
LIBFT		= $(LIBFT_DIR)/libft.a
MLX_SO		= $(MLX_DIR)/libmlx.so -lSDL2
INCLUDES	= -I includes -I src -I $(LIBFT_DIR)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBFT) $(MLX_SO) $(OBJS)
	@$(CC) $(CFLAGS) -lm $(OBJS) $(LIBFT) $(MLX_SO) -o $(NAME)
	@echo "cub3D OK"

$(MLX_SO) :
	@git clone $(MLX_REPO) $(MLX_DIR)
	@git -C $(MLX_DIR) checkout $(MLX_VERSION) 2>/dev/null
	@make -C $(MLX_DIR) -j4

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR) all

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean: 
	@$(RM) -r $(OBJ_DIR)
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@echo "Objects removed"

fclean: clean
	@$(RM) -r $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "cub3D removed"

re: fclean all

rebonus : fclean bonus

.PHONY : all clean fclean re bonus
