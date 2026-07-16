NAME		= cube3D
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

OBJ_DIR		= obj

VPATH		= src:src/parser

SRCS 		= main.c \
				map.c \
				set_id.c \
				t_map.c \
				parser.c \
				set_fandc.c \
				get_data.c \
				parser_utils.c \
				utils.c \

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

MLX_DIR		= MacroLibX
MLX_REPO    = https://github.com/seekrs/MacroLibX.git
MLX_VERSION = ddfbe32

LIBFT_DIR	= libft
LIBMLX		= MacroLibX
LIBFT		= $(LIBFT_DIR)/libft.a
MLX_SO		= $(MLX_DIR)/libmlx.so -lSDL2
INCLUDES	= -I includes -I src -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX_SO) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_SO) -o $(NAME)
	@echo "Cube3D OK\n"

$(MLX_SO) :
	@git clone $(MLX_REPO) $(MLX_DIR)
	@git -C $(MLX_DIR) checkout $(MLX_VERSION) 2>/dev/null
	@make -C $(MLX_DIR) -j4

$(LIBFT):
	@make -C $(LIBFT_DIR) all

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean: 
	@$(RM) -r $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "Objects removed\n"

fclean: clean
	@$(RM) -r $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "Cube3D removed\n"

re: fclean all

rebonus : fclean bonus

.PHONY : all clean fclean re
