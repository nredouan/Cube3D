/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:14:49 by scegla            #+#    #+#             */
/*   Updated: 2026/08/01 13:05:23 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	map_error(t_game **game)
{
	int	resu;
	int	y;
	int	x;

	y = 0;
	x = 0;
	resu = 0;
	while ((*game)->map[y])
	{
		if ((*game)->map[y][x] == '0')
			is_map_is_error(game, x, y);
		x++;
		if ((*game)->map[y][x] == '\n' || (*game)->map[y][x] == 0)
		{
			y++;
			x = 0;
		}
	}
}

int	is_there_a_unvalid_character(char **map, int y, int x)
{
	while (map[y])
	{
		if (map[y][x] == '\n' || map[y][x] == '\0')
		{
			y++;
			x = 0;
		}
		if (!map[y])
			break ;
		if (map[y][x] != 'N' && map[y][x] != 'S'
			&& map[y][x] != 'E' && map[y][x] != 'W'
			&& map[y][x] != '0' && map[y][x] != '1' && map[y][x] != ' ')
			return (0);
		x++;
	}
	return (1);
}

static int	check_map_objects(char **map, int y, int x)
{
	int	count_player;

	count_player = 0;
	while (map[y])
	{
		if (map[y][x] == 'N' || map[y][x] == 'S'
			|| map[y][x] == 'E' || map[y][x] == 'W')
			count_player++;
		x++;
		if (map[y][x] == '\n' || map[y][x] == '\0')
		{
			y++;
			x = 0;
		}
	}
	if (count_player != 1)
	{
		error_handler("There is not the right amount of start position");
		return (0);
	}
	return (1);
}

int	map_has_what_we_need(char	**map, int y, int x)
{
	if (!is_there_a_unvalid_character(map, y, x))
	{
		error_handler("A character in the map is not valid.");
		return (0);
	}
	if (!check_map_objects(map, y, x))
		return (0);
	return (1);
}

int	parser(t_game **game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!map_has_what_we_need((*game)->map, y, x))
		return (0);
	while ((*game)->map[y][x] != 'N' && (*game)->map[y][x] != 'S'
		&& (*game)->map[y][x] != 'E' && (*game)->map[y][x] != 'W')
	{
		if ((*game)->map[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		x++;
	}
	(*game)->px = x;
	(*game)->py = y;
	(*game)->angle = (*game)->map[y][x];
	map_error(game);
	return (1);
}
