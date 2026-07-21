/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:33:44 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/21 11:37:40 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

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
# define PI2 (2*PI)

typedef	struct	s_player
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	angle;
}			t_player;

typedef struct	s_game
{
	mlx_context				mlx;
	mlx_window_create_info	*win_infos;
	mlx_window				window;
	t_player				player;
	char					**map;
	void					*no;
	void					*so;
	void					*we;
	void					*ea;
	int						f[3];
	int						c[3];
	int						py;
	int						px;
	char					angle;
}		t_game;

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
void	map_is_error(t_game **game);
int		parser(t_game **game);
char	**get_map(int fd);

// t_map
void	ft_lstadd_back_map(t_map **lst, t_map *new);
t_map	*ft_lstnew_file(char *str);
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
void	draw_map(t_game *game);
void	draw_player(t_game *game);
void	draw_rays(t_game *game);

#endif