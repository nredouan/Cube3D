/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:01:44 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/15 17:18:58 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cube3d.h"

void	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end((mlx_context)param);
}

void	key_hook(int key, void *param)
{
	t_game	*game;

	game = param;
	if (key == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(game->mlx);
	if (key == SDL_SCANCODE_A)
	{
		game->player.pa -= 0.1;
		if (game->player.pa < 0)
			game->player.pa += 2 * PI;
		game->player.dx = cosf(game->player.pa)*5;
		game->player.dy = sinf(game->player.pa)*5;
	}
	if (key == SDL_SCANCODE_D)
	{
		game->player.pa += 0.1;
		if (game->player.pa > 2* PI)
			game->player.pa -= 2 * PI;
		game->player.dx = cosf(game->player.pa)*5;
		game->player.dy = sinf(game->player.pa)*5;
	}
	if (key == SDL_SCANCODE_W)
	{
		game->player.px += game->player.dx;
		game->player.py += game->player.dy;
	}
	if (key == SDL_SCANCODE_S)
	{
		game->player.px -= game->player.dx;
		game->player.py -= game->player.dy;
	}
	
}

char	**init_map()
{
	char	**map;
	int		i = 0;
	int		fd;

	map = malloc(sizeof(char*) * 8);
	fd = open("map.test", O_RDONLY);
	while (i < 7)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

t_game	*init_game(void)
{
	t_game			*game;

	game = malloc(sizeof(t_game));
		//protect malloc
	ft_bzero(game, sizeof(t_game));
	game->win_infos = malloc(sizeof(mlx_window_create_info));
	ft_bzero(game->win_infos, sizeof(mlx_window_create_info));
	game->mlx = mlx_init();
		//protect mlx_init
	game->win_infos->title = "cube3D";
	game->win_infos->width = 1024;
	game->win_infos->height = 512;
	game->window = mlx_new_window(game->mlx, game->win_infos);
		//protect window_init
	game->player.px = 300;
	game->player.py = 300;
	game->player.pa = 0;
	game->player.dx = cosf(game->player.pa)*5;
	game->player.dy = sinf(game->player.pa)*5;
	game->map = init_map();
	return (game);
}

void	game_destroy(t_game *game)
{
	int	i = 0;
	
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_context(game->mlx);
	free(game->win_infos);
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
}

void	update(void *param)
{
	t_game	*game;

	game = param;
	mlx_clear_window(game->mlx, game->window, (mlx_color)0xFFu);
	draw_map(game);
	draw_player(game);
	// draw_rays(game);
}

int	main()
{
	t_game	*game;

	game = init_game();
	mlx_on_event(game->mlx, game->window, MLX_WINDOW_EVENT, window_hook, game->mlx);
	mlx_on_event(game->mlx, game->window, MLX_KEYDOWN, key_hook, game);
	mlx_add_loop_hook(game->mlx, update, game);
	mlx_loop(game->mlx);
	game_destroy(game);
}
