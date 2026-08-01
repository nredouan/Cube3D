/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 16:50:29 by nredouan          #+#    #+#             */
/*   Updated: 2026/08/01 17:04:49 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_open(char **map, int y, int x)
{
	if (y < 0 || map[y] == NULL)
		return (1);
	if (x < 0 || x >= (int)ft_strlen(map[y]))
		return (1);
	if (map[y][x] == ' ' || map[y][x] == '\0')
		return (1);
	return (0);
}

static void	flood_fill(t_game *game, char **map, int y, int x)
{
	if (is_open(map, y, x))
	{
		game_destroy(game);
		free_memory(map);
		error_handler("The map is not enclosed.");
		exit(EXIT_FAILURE);
	}
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(game, map, y + 1, x);
	flood_fill(game, map, y - 1, x);
	flood_fill(game, map, y, x + 1);
	flood_fill(game, map, y, x - 1);
}

void	call_flood_fill(t_game *game)
{
	char	**map;

	map = tab_char_cpy(game->map);
	if (!map)
	{
		game_destroy(game);
		exit(EXIT_FAILURE);
	}
	flood_fill(game, map, game->py, game->px);
	free_memory(map);
}
