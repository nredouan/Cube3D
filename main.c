/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:01:44 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/27 16:51:24 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"


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
	game->win_infos->title = "cub3D";
	game->win_infos->width = WIDTH;
	game->win_infos->height = HEIGHT;
	// game->win_infos->is_fullscreen = true;
	// game->win_infos->is_resizable = false;
	game->window = mlx_new_window(game->mlx, game->win_infos);
		//protect window_init
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
	game->player.plane_y= 0.66;
	return (game);
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

void	update(void *param)
{
	t_game	*game;

	game = param;
	mlx_clear_window(game->mlx, game->window, (mlx_color)0xFFu);
	calc_rays(game);
	draw_map(game);
	draw_player(game);
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
