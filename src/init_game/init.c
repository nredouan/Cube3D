/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 14:43:54 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/31 18:32:52 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_game	*init_struct_game(int fd)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
	{
		close(fd);
		return (NULL);
	}
	game->fd = fd;
	game->f[0] = -1;
	game->c[0] = -1;
	game->win_infos = ft_calloc(sizeof(mlx_window_create_info), 1);
	if (!game->win_infos)
	{
		game_destroy(game);
		return (NULL);
	}
	game->mlx = mlx_init();
	if (!game->mlx || map_valid(&game, fd))
	{
		game_destroy(game);
		return (NULL);
	}
	return (game);
}

static int	init_window(t_game *game)
{
	game->win_infos->title = "cub3D";
	game->win_infos->width = WIDTH;
	game->win_infos->height = HEIGHT;
	game->window = mlx_new_window(game->mlx, game->win_infos);
	if (!game->window)
	{
		game_destroy(game);
		return (1);
	}
	return (0);
}

static void	init_player(t_game *game)
{
	game->player.pos_x = game->px + 0.5;
	game->player.pos_y = game->py + 0.5;
	if (game->angle == 'S')
		game->player.angle = PI / 2;
	else if (game->angle == 'N')
		game->player.angle = PI + PI / 2;
	else if (game->angle == 'W')
		game->player.angle = PI;
	else
		game->player.angle = 2 * PI;
	game->player.dir_x = cosf(game->player.angle);
	game->player.dir_y = sinf(game->player.angle);
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
}

t_game	*init_game(int fd)
{
	t_game			*game;

	game = init_struct_game(fd);
	if (!game)
		return (NULL);
	if (!parser(&game))
	{
		game_destroy(game);
		return (NULL);
	}
	if (init_window(game))
		return (NULL);
	init_player(game);
	game->is_mouse = true;
	return (game);
}
