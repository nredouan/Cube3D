/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:47:30 by scegla            #+#    #+#             */
/*   Updated: 2026/07/15 16:47:53 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	map_is_error(t_data **data)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("The map is not enclosed.", 2);
	free_data(data);
	exit(1);
}

void	is_map_is_error(t_data **data, int x, int y)
{
	if (y != 0 && (!(*data)->map[y - 1][x]
		|| (*data)->map[y - 1][x] == ' ' || (*data)->map[y - 1][x] == '\n'))
		map_is_error(data);
	if ((*data)->map[y + 1] && (!(*data)->map[y + 1][x]
		|| (*data)->map[y + 1][x] == ' ' || (*data)->map[y + 1][x] == '\n'))
		map_is_error(data);
	if (x != 0 && (!(*data)->map[y][x - 1]
		|| (*data)->map[y][x - 1] == ' ' || (*data)->map[y][x - 1] == '\n'))
		map_is_error(data);
	if (!(*data)->map[y][x + 1]
		|| (*data)->map[y][x + 1] == ' ' || (*data)->map[y][x + 1] == '\n')
		map_is_error(data);
}
