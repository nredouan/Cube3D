/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:47:30 by scegla            #+#    #+#             */
/*   Updated: 2026/08/01 11:25:13 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	map_is_error(t_game **game)
{
	error_handler("The map is not enclosed.");
	game_destroy(*game);
	exit(1);
}

void	is_map_is_error(t_game **game, int x, int y)
{
	if (y == 0 || (!(*game)->map[y - 1][x]
		|| (*game)->map[y - 1][x] == ' ' || (*game)->map[y - 1][x] == '\n'))
		map_is_error(game);
	if (y == (ft_tab_size((*game)->map) - 1)
		|| ((*game)->map[y + 1] && (!(*game)->map[y + 1][x]
			|| (*game)->map[y + 1][x] == ' '
		|| (*game)->map[y + 1][x] == '\n')))
		map_is_error(game);
	if (x == 0 || (!(*game)->map[y][x - 1]
		|| (*game)->map[y][x - 1] == ' ' || (*game)->map[y][x - 1] == '\n'))
		map_is_error(game);
	if (!(*game)->map[y][x + 1]
		|| (*game)->map[y][x + 1] == ' ' || (*game)->map[y][x + 1] == '\n')
		map_is_error(game);
}
