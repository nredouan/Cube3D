/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:01:44 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/16 15:11:28 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../cube3d.h"

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

void	game_destroy(t_game *game)
{
	if (game->ea)
		mlx_destroy_image(game->mlx, game->ea);
	if (game->no)
		mlx_destroy_image(game->mlx, game->no);
	if (game->so)
		mlx_destroy_image(game->mlx, game->so);
	if (game->we)
		mlx_destroy_image(game->mlx, game->we);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		mlx_destroy_context(game->mlx);
	if (game->win_infos)
		free(game->win_infos);
	free_memory(game->map);
	free(game);
}

t_game	*init_game(int fd)
{
	t_game			*game;

	game = ft_calloc(sizeof(t_game), 1);
		//protect malloc

	game->win_infos = ft_calloc(sizeof(mlx_window_create_info), 1);
		// protect calloc
	game->mlx = mlx_init();
		//protect mlx_init
	if (map_valid(&game, fd))
	{
		game_destroy(game);
		return (NULL);
	}
	parser(&game);
	game->win_infos->title = "cube3D";
	game->win_infos->width = 1024;
	game->win_infos->height = 512;
	game->window = mlx_new_window(game->mlx, game->win_infos);
		//protect window_init
	
	game->player.px = game->px * 64 + 30;
	game->player.py = game->py * 64 + 30;
	if (game->angle == 'S')
		game->player.pa = PI / 2;
	else if (game->angle == 'N')
		game->player.pa = PI + PI / 2;
	else if (game->angle == 'W')
		game->player.pa = PI;
	else
		game->player.pa = 0;
	game->player.dx = cosf(game->player.pa)*5;
	game->player.dy = sinf(game->player.pa)*5;
	return (game);
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

int	main(int ac, char **av)
{
	t_game	*game;
	int		fd;

	if (ac != 2)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Wrong number of arguments.", 2);
		return (1);
	}
	is_cub(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || fd > 1023)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Your file doesn't exist.", 2);
		return (1);
	}
	game = init_game(fd);
	if (!game)
		return (1);
	mlx_on_event(game->mlx, game->window, MLX_WINDOW_EVENT, window_hook, game->mlx);
	mlx_on_event(game->mlx, game->window, MLX_KEYDOWN, key_hook, game);
	mlx_add_loop_hook(game->mlx, update, game);
	mlx_loop(game->mlx);
	game_destroy(game);
}
