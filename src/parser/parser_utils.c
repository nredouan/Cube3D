/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:47:30 by scegla            #+#    #+#             */
/*   Updated: 2026/07/23 15:32:32 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	map_is_error(t_game **game)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("The map is not enclosed.", 2);
	game_destroy(*game);
	exit(1);
}

void	is_map_is_error(t_game **game, int x, int y)
{
	if (y != 0 && (!(*game)->map[y - 1][x]
		|| (*game)->map[y - 1][x] == ' ' || (*game)->map[y - 1][x] == '\n'))
		map_is_error(game);
	if ((*game)->map[y + 1] && (!(*game)->map[y + 1][x]
		|| (*game)->map[y + 1][x] == ' ' || (*game)->map[y + 1][x] == '\n'))
		map_is_error(game);
	if (x != 0 && (!(*game)->map[y][x - 1]
		|| (*game)->map[y][x - 1] == ' ' || (*game)->map[y][x - 1] == '\n'))
		map_is_error(game);
	if (!(*game)->map[y][x + 1]
		|| (*game)->map[y][x + 1] == ' ' || (*game)->map[y][x + 1] == '\n')
		map_is_error(game);
}
