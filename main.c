/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:01:44 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/21 10:33:46 by nredouan         ###   ########.fr       */
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
		game->player.angle -= 0.1;
		if (game->player.angle < 0)
			game->player.angle += 2 * PI;
		game->player.dir_x = cosf(game->player.angle)*5;
		game->player.dir_y = sinf(game->player.angle)*5;
	}
	if (key == SDL_SCANCODE_D)
	{
		game->player.angle += 0.1;
		if (game->player.angle > 2* PI)
			game->player.angle -= 2 * PI;
		game->player.dir_x = cosf(game->player.angle)*5;
		game->player.dir_y = sinf(game->player.angle)*5;
	}
	if (key == SDL_SCANCODE_W)
	{
		game->player.pos_x += game->player.dir_x;
		game->player.pos_y += game->player.dir_y;
	}
	if (key == SDL_SCANCODE_S)
	{
		game->player.pos_x -= game->player.dir_x;
		game->player.pos_y -= game->player.dir_y;
	}
}

char	**init_map(void)
{
	char	**map;
	int		i = 0;
	int		fd;

	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd))
		i++;
	close(fd);
	map = malloc(sizeof(char*) * (i + 1));
	fd = open("map.cub", O_RDONLY);
	i = 0;
	map[0] = get_next_line(fd);
	while (map[i])
	{
		i++;
		map[i] = get_next_line(fd);
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
	game->win_infos->width = 20*64;
	game->win_infos->height = 10*64;
	game->window = mlx_new_window(game->mlx, game->win_infos);
		//protect window_init
	game->map = init_map();
	game->player.pos_x = 300;
	game->player.pos_y = 300;
	game->player.angle = 0;
	game->player.dir_x = cosf(game->player.angle)*5;
	game->player.dir_y = sinf(game->player.angle)*5;
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
	draw_rays(game);
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
