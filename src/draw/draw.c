/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:16:29 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/24 17:50:50 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_line(t_game *game, int line_height, double x, mlx_color color)
{
	int	pixel;
	int	draw_start;
	int	draw_end;

	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end > HEIGHT)
		draw_end = HEIGHT - 1;
	pixel = draw_start;
	while (pixel <= draw_end)
	{
		mlx_pixel_put(game->mlx, game->window, x, pixel, color);
		pixel++;
	}
}

void	draw_player(t_game *game)
{
	mlx_color	green[25];
	int			i;
	int			x;
	int			y;

	i = 0;
	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			green[i].rgba = 0x00FF00FF;
			i++;
			x++;
		}
		y++;
	}
	mlx_pixel_put_region(game->mlx, game->window, game->player.pos_x * 12 - 2,
		game->player.pos_y * 12 - 2, 5, 5, green);
}

void	draw_walls(t_game *game, int side, double x)
{
	mlx_color	color;
	int			line_height;

	color.rgba = 0x00FF00FF;
	if (side == 1)
		color.rgba /= 2;
	line_height = HEIGHT / game->perp_wall_dist;
	draw_line(game, line_height, x, color);
}
