/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:33:44 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/06 15:21:33 by nredouan         ###   ########.fr       */
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

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
}			t_player;
#endif