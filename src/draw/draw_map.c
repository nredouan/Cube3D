/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 15:38:45 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/27 14:34:37 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	setup_colors(mlx_color *pixels, uint32_t color)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (y < 12)
	{
		x = 0;
		while (x < 12)
		{
			pixels[i].rgba = color;
			i++;
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game)
{
	mlx_color	pixels_b[144];
	mlx_color	pixels_w[144];
	int			y;
	int			x;

	y = 0;
	setup_colors(pixels_b, 0xFFFFFFFF);
	setup_colors(pixels_w, 0x8080808A);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_pixel_put_region(game->mlx, game->window, x * 12, y * 12,
					12, 12, pixels_b);
			else if (game->map[y][x] != '\n' && game->map[y][x] != ' ')
				mlx_pixel_put_region(game->mlx, game->window, x * 12, y * 12,
					12, 12, pixels_w);
			x++;
		}
		y++;
	}
}
