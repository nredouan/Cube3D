/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:01:44 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/06 13:03:14 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cube3d.h"

void	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end((mlx_context)param);
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
	game->win_infos->width = 1920;
	game->win_infos->height = 1080;
	game->window = mlx_new_window(game->mlx, game->win_infos);
		//protect window_init
	
	return (game);
}

void	game_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_context(game->mlx);
	free(game->win_infos);
	free(game);
}

void	update(void *param)
{
	t_game	*game;

	game = param;
	mlx_clear_window(game->mlx, game->window, (mlx_color)0xFFu);
}

int	main()
{
	t_game	*game;

	game = init_game();
	mlx_on_event(game->mlx, game->window, MLX_WINDOW_EVENT, window_hook, game->mlx);
	mlx_add_loop_hook(game->mlx, update, game);
	mlx_loop(game->mlx);
	game_destroy(game);
}
