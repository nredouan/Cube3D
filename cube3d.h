/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:33:44 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/15 17:17:27 by nredouan         ###   ########.fr       */
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

void	draw_map(t_game *game);
void	draw_player(t_game *game);
void	draw_rays(t_game *game);

#endif