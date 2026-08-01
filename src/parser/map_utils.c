/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 12:40:20 by scegla            #+#    #+#             */
/*   Updated: 2026/08/01 16:14:09 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	line_is_good(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '1')
			return (0);
		i++;
	}
	return (1);
}

int	str_is_white_space(char *c)
{
	int	i;

	i = 0;
	while (c[i] == ' ' || (c[i] >= 9 && c[i] <= 13))
		i++;
	if (!c[i])
		return (0);
	return (1);
}
