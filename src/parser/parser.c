/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:14:49 by scegla            #+#    #+#             */
/*   Updated: 2026/07/15 16:47:39 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	map_error(t_data **data)
{
	int	resu;
	int	y;
	int	x;

	y = 0;
	x = 0;
	resu = 0;
	while ((*data)->map[y])
	{
		if (x == 0 && ((*data)->map[y][x] != '1' && (*data)->map[y][x] != ' '))
			map_is_error(data);
		if ((*data)->map[y][x] == '0')
			is_map_is_error(data, x, y);
		x++;
		if ((*data)->map[y][x] == '\n' || (*data)->map[y][x] == 0)
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
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("There is not the right amount of start position", 2);
		return (0);
	}
	return (1);
}

int	map_has_what_we_need(char	**map, int y, int x)
{
	if (!is_there_a_unvalid_character(map, y, x))
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("A character in the map is not valid.", 2);
		return (0);
	}
	if (!check_map_objects(map, y, x))
		return (0);
	return (1);
}

int	parser(t_data **data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!map_has_what_we_need((*data)->map, y, x))
		return (0);
	while ((*data)->map[y][x] != 'N' && (*data)->map[y][x] != 'S'
		&& (*data)->map[y][x] != 'E' && (*data)->map[y][x] != 'W')
	{
		if ((*data)->map[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		x++;
	}
	map_error(data);
	return (1);
}
