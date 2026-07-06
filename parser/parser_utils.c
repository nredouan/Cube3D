/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:58:11 by scegla            #+#    #+#             */
/*   Updated: 2026/07/03 12:09:28 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	something_is_not_reachable(char **map, int y, int x)
{
	if (map[y][x] == 'C')
		ft_printf("Error\nThere is a collectable that cannot be reached.\n");
	else if (map[y][x] == 'E')
		ft_printf("Error\nThe exit cannot be reached.\n");
	else if (map[y][x] == 'P')
		ft_printf("Error\nWhattttt???.\n");
}

int	is_there_something_left(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		if (map[y][x] == '\n' || map[y][x] == '\0')
		{
			y++;
			x = 0;
		}
		else if (map[y][x] == 'C' || map[y][x] == 'E' || map[y][x] == 'P')
		{
			something_is_not_reachable(map, y, x);
			return (0);
		}
		x++;
	}
	return (1);
}

int	error_handler(int count_c, int count_e, int count_p)
{
	if (count_c == 0 || count_e != 1 || count_p != 1)
	{
		if (count_e > 1)
			ft_printf("Error\nThere is more than one exit on the map.\n");
		else if (count_e == 0)
			ft_printf("Error\nThere is no exit on the map\n");
		else if (count_p == 0)
			ft_printf("Error\nThere is no start on the map\n");
		else if (count_p > 1)
			ft_printf("Error\nThere is more than one start on the map.\n");
		else if (count_c == 0)
			ft_printf("Error\nThe map has no collectables.\n");
		return (0);
	}
	return (1);
}

int	map_is_a_rectangle(char **map, int y)
{
	while (map[y + 1])
	{
		if (ft_strlen_new_line(map[y]) != ft_strlen_new_line(map[y + 1]))
			return (0);
		y++;
	}
	return (1);
}

int	map_enclosed(char **map, int y)
{
	int	x;

	x = 0;
	while (map[0][x] != '\n')
	{
		if (map[0][x] != '1')
			return (0);
		x++;
	}
	x = 0;
	while (map[y])
	{
		if (map[y][0] != '1' || map[y][ft_strlen_new_line(map[y]) - 1] != '1')
			return (0);
		y++;
	}
	y--;
	while (map[y][x] != '\n' && map[y][x] != '\0')
	{
		if (map[y][x] != '1')
			return (0);
		x++;
	}
	return (1);
}
