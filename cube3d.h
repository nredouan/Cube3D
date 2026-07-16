/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:33:44 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/16 11:15:02 by nredouan         ###   ########.fr       */
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
	float	px;
	float	py;
	float	dx;
	float	dy;
	float	pa;
}			t_player;

typedef struct	s_game
{
	mlx_context				mlx;
	mlx_window_create_info	*win_infos;
	mlx_window				window;
	t_player				player;
	char					**map;
}		t_game;

typedef struct s_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	char	**map;
}				t_data;

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
	int		(*f)(t_data **data, char *info);
}	t_set_id;

//Simon parser
// set_id
int		no(t_data **data, char *info);
int		so(t_data **data, char *info);
int		we(t_data **data, char *info);
int		ea(t_data **data, char *info);
int		f(t_data **data, char *info);
int		c(t_data **data, char *info);

// parser
void	is_map_is_error(t_data **data, int x, int y);
void	map_is_error(t_data **data);
int		parser(t_data **data);
char	**get_map(int fd);

// t_map
void	ft_lstadd_back_map(t_map **lst, t_map *new);
t_map	*ft_lstnew_file(char *str);
int		ft_tmapsize(t_map *lst);
void	free_tmap(t_map **map);

// utils
void	free_data(t_data **data);
int		until_space(char *str);
void	free_memory(char **s);
void	finish_gnl(int fd);
void	is_cub(char *str);

//fill data
int		get_textures(char *str, int fd, t_data **data);
int		error_in_info(char *str, int fd, int i);
int		send_info(const t_set_id *list,
			int fd, char *str, t_data **data);
int		map_valid(t_data **data, int fd);
int		identifier_good(char *str);
void	draw_map(t_game *game);
void	draw_player(t_game *game);
void	draw_rays(t_game *game);

#endif