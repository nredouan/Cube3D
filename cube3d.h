/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:33:44 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/07 16:16:28 by scegla           ###   ########.fr       */
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

# define RED "\033[0;31m"
# define END "\033[0m"

typedef struct s_game
{
	mlx_context				mlx;
	mlx_window_create_info	*win_infos;
	mlx_window				window;
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
int	no(t_data **data, char *info);
int	so(t_data **data, char *info);
int	we(t_data **data, char *info);
int	ea(t_data **data, char *info);
int	f(t_data **data, char *info);
int	c(t_data **data, char *info);

// parser
int		parser(t_data **data);
char	**get_map(int fd);

t_map	*ft_lstnew_file(char *str);
void	ft_lstadd_back_map(t_map **lst, t_map *new);
void	free_tmap(t_map **map);
int		ft_tmapsize(t_map *lst);
// utils
void	free_memory(char **s);
void	free_data(t_data **data);

#endif