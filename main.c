/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:01:44 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/31 17:40:36 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

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

void	move_view(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_mouse_get_pos(game->mlx, &x, &y);
	if (x < WIDTH / 4)
	{
		game->player.angle -= 0.2;
		if (game->player.angle <= 0)
			game->player.angle += 2 * PI;
		game->player.dir_x = cosf(game->player.angle);
		game->player.dir_y = sinf(game->player.angle);
	}
	if (x > WIDTH - WIDTH / 4)
	{
		game->player.angle += 0.2;
		if (game->player.angle > 2 * PI)
			game->player.angle -= 2 * PI;
		game->player.dir_x = cosf(game->player.angle);
		game->player.dir_y = sinf(game->player.angle);
	}
}

void	update(void *param)
{
	t_game	*game;

	game = param;
	mlx_clear_window(game->mlx, game->window, (mlx_color)0xFFu);
	calc_rays(game);
	draw_map(game);
	draw_player(game);
	if (!game->is_mouse)
		move_view(game);
}

static void	error_handler(char *message)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	exit(1);
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		fd;

	if (ac != 2)
		error_handler("Wrong number of arguments.");
	is_cub(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || fd > 1023)
		error_handler("Your file is not accessible.");
	game = init_game(fd);
	if (!game)
		return (1);
	mlx_on_event(game->mlx, game->window,
		MLX_WINDOW_EVENT, window_hook, game->mlx);
	mlx_on_event(game->mlx, game->window,
		MLX_KEYDOWN, key_hook, game);
	mlx_add_loop_hook(game->mlx, update, game);
	mlx_loop(game->mlx);
	game_destroy(game);
}
