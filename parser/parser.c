/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:14:49 by scegla            #+#    #+#             */
/*   Updated: 2026/07/03 12:17:01 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

static void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == '2')
		return ;
	map[y][x] = '2';
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
	flood_fill(map, y + 1, x);
	flood_fill(map, y - 1, x);
	return ;
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
		else if (map[y][x] != 'C' && map[y][x] != 'E' && map[y][x] != 'P'
			&& map[y][x] != '0' && map[y][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

static int	check_map_objects(char **map, int y, int x)
{
	int	count_c;
	int	count_e;
	int	count_p;

	count_c = 0;
	count_e = 0;
	count_p = 0;
	while (map[y])
	{
		if (map[y][x] == 'C')
			count_c++;
		else if (map[y][x] == 'E')
			count_e++;
		else if (map[y][x] == 'P')
			count_p++;
		x++;
		if (map[y][x] == '\n' || map[y][x] == '\0')
		{
			y++;
			x = 0;
		}
	}
	if (!error_handler(count_c, count_e, count_p))
		return (0);
	return (1);
}

int	map_has_what_we_need(char	**map, int y, int x)
{
	if (!is_there_a_unvalid_character(map, y, x))
	{
		ft_printf("Error\nA character in the map is not valid.\n");
		return (0);
	}
	if (!check_map_objects(map, y, x))
		return (0);
	if (!map_enclosed(map, y))
	{
		ft_printf("Error\nThe map is not enclosed.\n");
		return (0);
	}
	if (!map_is_a_rectangle(map, y))
	{
		ft_printf("Error\nThe map is not a rectangle.\n");
		return (0);
	}
	return (1);
}

int	parser_parser(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!map_has_what_we_need(map, y, x))
		return (0);
	while (map[y][x] != 'P')
	{
		if (map[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		x++;
	}
	flood_fill(map, y, x);
	if (!is_there_something_left(map))
		return (0);
	return (1);
}

