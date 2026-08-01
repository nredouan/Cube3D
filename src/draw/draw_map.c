/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 15:38:45 by nredouan          #+#    #+#             */
/*   Updated: 2026/08/01 13:04:37 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	setup_colors(mlx_color *pixels, uint32_t color)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 6)
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
	mlx_color	pixels_b[6 * 6];
	mlx_color	pixels_w[6 * 6];
	int			y;
	int			x;

	y = 0;
	setup_colors(pixels_b, 0xFFFFFFF0);
	setup_colors(pixels_w, 0x80808080);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_pixel_put_region(game->mlx, game->window, x * 6, y * 6,
					6, 6, pixels_b);
			else if (game->map[y][x] != '\n' && game->map[y][x] != ' ')
				mlx_pixel_put_region(game->mlx, game->window, x * 6, y * 6,
					6, 6, pixels_w);
			x++;
		}
		y++;
	}
}

static void	calculate_delta(t_game *game)
{
	mlx_color	color;
	float		deltax;
	float		deltay;

	color.rgba = 0xFF0000FF;
	deltax = ((game->left_ray_hit_x) * 6) - game->player.pos_x * 6;
	deltay = ((game->left_ray_hit_y) * 6) - game->player.pos_y * 6;
	draw_fov(game, deltax, deltay, color);
	deltax = ((game->right_ray_hit_x) * 6) - game->player.pos_x * 6;
	deltay = ((game->right_ray_hit_y) * 6) - game->player.pos_y * 6;
	draw_fov(game, deltax, deltay, color);
}

void	draw_player(t_game *game)
{
	mlx_color	green[9];
	int			i;
	int			x;
	int			y;

	i = 0;
	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			green[i].rgba = 0x00FF00FF;
			i++;
			x++;
		}
		y++;
	}
	calculate_delta(game);
	mlx_pixel_put_region(game->mlx, game->window, game->player.pos_x * 6 - 1,
		game->player.pos_y * 6 - 1, 3, 3, green);
}
