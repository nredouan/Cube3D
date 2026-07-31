/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:33:44 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/23 15:03:19 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>
# include <SDL2/SDL_scancode.h>
# include "MacroLibX/includes/mlx.h"
# include "MacroLibX/includes/mlx_extended.h"
# include "libft/libft.h"
# include <math.h>

# define RED "\033[0;31m"
# define END "\033[0m"
# define PI 3.1415926535
# define WIDTH 1920
# define HEIGHT 1080
# define WALL_COLOR 0x00FF00FF

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	angle;
	float	plane_x;
	float	plane_y;
}			t_player;

typedef struct s_ray
{
	double	x;
	float	camera_x;
	float	dir_x;
	float	dir_y;
	int		map_x;
	int		map_y;
	float	delta_x;
	float	delta_y;
	int		step_x;
	int		step_y;
	float	side_dist_x;
	float	side_dist_y;
	int		side;
}			t_ray;

typedef struct s_game
{
	mlx_context				mlx;
	mlx_window_create_info	*win_infos;
	mlx_window				window;
	t_player				player;
	char					**map;
	mlx_image				no;
	mlx_image				so;
	mlx_image				we;
	mlx_image				ea;
	int						image_width;
	int						texture_width[4];
	int						image_height;
	int						texture_height[4];
	int						f[3];
	mlx_color				color_f;
	int						c[3];
	mlx_color				color_c;
	int						py;
	int						px;
	char					angle;
	float					perp_wall_dist;
	float					hit_x;
	float					hit_y;
	float					left_ray_hit_x;
	float					left_ray_hit_y;
	float					right_ray_hit_x;
	float					right_ray_hit_y;
}							t_game;

typedef struct s_mlx
{
	void	*addr;
	void	*win;
	void	*wall_no;
}				t_mlx;

typedef struct s_map
{
	char			*map;
	struct s_map	*next;
}				t_map;

typedef struct s_set_id
{
	char	*type;
	int		(*f)(t_game **game, char *info);
}	t_set_id;

//Simon parser
// set_id
int		no(t_game **game, char *info);
int		so(t_game **game, char *info);
int		we(t_game **game, char *info);
int		ea(t_game **game, char *info);
int		f(t_game **game, char *info);
int		c(t_game **game, char *info);

// parser
void	is_map_is_error(t_game **game, int x, int y);
void	image_does_not_exist(char *cpy);
void	map_is_error(t_game **game);
int		parser(t_game **game);
char	**get_map(int fd);

// map_utils
int		str_is_white_space(char *c);
int		line_is_good(char *str);

// t_map
void	ft_lstadd_back_map(t_map **lst, t_map *new);
t_map	*ft_lstnew_file(char *str);
t_map	*ft_lstlast_map(t_map *lst);
int		ft_tmapsize(t_map *lst);
void	free_tmap(t_map **map);

// utils
int		until_space(char *str);
void	free_memory(char **s);
void	finish_gnl(int fd);
void	is_cub(char *str);
void	game_destroy(t_game *game);

//fill data
int		get_textures(char *str, int fd, t_game **game);
int		error_in_info(char *str, int fd, int i);
int		send_info(const t_set_id *list,
			int fd, char *str, t_game **game);
int		map_valid(t_game **game, int fd);
int		identifier_good(char *str);
void	invalid_info(void);

//init game
t_game	*init_game(int fd);

//raycasting
void	calc_rays(t_game *game);

//drawing
void	draw_map(t_game *game);
void	draw_player(t_game *game);
void	draw_walls(t_game *game, t_ray ray);
void	draw_line(int tex_x, t_game *game, int line_height, t_ray ray);

//hook
void	key_hook(int key, void *param);
void	window_hook(int event, void *param);

#endif