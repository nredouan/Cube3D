/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:16:21 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/31 15:48:23 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	move_f_b(int key, t_game *game, int pos_x, int pos_y)
{
	if (key == SDL_SCANCODE_W)
	{
		pos_x = (int)(game->player.pos_x + (game->player.dir_x / 4));
		pos_y = (int)(game->player.pos_y + (game->player.dir_y / 4));
		if (game->map[pos_y][pos_x] == '1' ||
				(game->map[pos_y][(int)game->player.pos_x] == '1' &&
				game->map[(int)game->player.pos_y][pos_x] == '1'))
			return ;
		game->player.pos_x += game->player.dir_x / 4;
		game->player.pos_y += game->player.dir_y / 4;
	}
	if (key == SDL_SCANCODE_S)
	{
		pos_x = (int)(game->player.pos_x - (game->player.dir_x / 4));
		pos_y = (int)(game->player.pos_y - (game->player.dir_y / 4));
		if (game->map[pos_y][pos_x] == '1' ||
				(game->map[pos_y][(int)game->player.pos_x] == '1' &&
				game->map[(int)game->player.pos_y][pos_x] == '1'))
			return ;
		game->player.pos_x -= game->player.dir_x / 4;
		game->player.pos_y -= game->player.dir_y / 4;
	}
}

static void	move_l_r(int key, t_game *game, int pos_x, int pos_y)
{
	if (key == SDL_SCANCODE_A)
	{
		pos_x = (int)(game->player.pos_x - (game->player.plane_x / 4));
		pos_y = (int)(game->player.pos_y - (game->player.plane_y / 4));
		if (game->map[pos_y][pos_x] == '1' ||
				(game->map[pos_y][(int)game->player.pos_x] == '1' &&
				game->map[(int)game->player.pos_y][pos_x] == '1'))
			return ;
		game->player.pos_x -= game->player.plane_x / 4;
		game->player.pos_y -= game->player.plane_y / 4;
	}
	if (key == SDL_SCANCODE_D)
	{
		pos_x = (int)(game->player.pos_x + (game->player.plane_x / 4));
		pos_y = (int)(game->player.pos_y + (game->player.plane_y / 4));
		if (game->map[pos_y][pos_x] == '1' ||
				(game->map[pos_y][(int)game->player.pos_x] == '1' &&
				game->map[(int)game->player.pos_y][pos_x] == '1'))
			return ;
		game->player.pos_x += game->player.plane_x / 4;
		game->player.pos_y += game->player.plane_y / 4;
	}
}

static void	turn(int key, t_game *game)
{
	if (!game->is_mouse)
		return ;
	if (key == SDL_SCANCODE_LEFT)
	{
		game->player.angle -= 0.1;
		if (game->player.angle <= 0)
			game->player.angle += 2 * PI;
		game->player.dir_x = cosf(game->player.angle);
		game->player.dir_y = sinf(game->player.angle);
	}
	if (key == SDL_SCANCODE_RIGHT)
	{
		game->player.angle += 0.1;
		if (game->player.angle > 2 * PI)
			game->player.angle -= 2 * PI;
		game->player.dir_x = cosf(game->player.angle);
		game->player.dir_y = sinf(game->player.angle);
	}
}

static void	mouse_handler(t_game *game)
{
	if (!game->is_mouse)
	{
		mlx_mouse_show(game->mlx);
		game->is_mouse = true;
	}
	else
	{
		mlx_mouse_hide(game->mlx);
		game->is_mouse = false;
	}
}

void	key_hook(int key, void *param)
{
	t_game	*game;
	int		pos_x;
	int		pos_y;

	game = param;
	pos_x = 0;
	pos_y = 0;
	if (key == SDL_SCANCODE_SPACE)
		mouse_handler(game);
	if (key == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(game->mlx);
	turn(key, game);
	move_f_b(key, game, pos_x, pos_y);
	move_l_r(key, game, pos_x, pos_y);
}
