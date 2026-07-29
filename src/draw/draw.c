/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:16:29 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/27 17:40:29 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_fov(t_game *game, float deltax, float deltay, mlx_color color)
{
	int		pixels;
	double	pixelX;
	double	pixelY;

	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	pixelX = game->player.pos_x * 12;
	pixelY = game->player.pos_y * 12;
	while (pixels)
	{
		mlx_pixel_put(game->mlx, game->window, pixelX, pixelY,color);
		pixelX += deltax;
		pixelY += deltay;
		pixels--;
	}
}

static void	calculate_delta(t_game *game)
{
	mlx_color	color;
	float		deltax;
	float		deltay;

	color.rgba = 0xFF0000FF;
	deltax = ((game->left_ray_hit_x) * 12) - game->player.pos_x * 12;
	deltay = ((game->left_ray_hit_y) * 12) - game->player.pos_y * 12;
	draw_fov(game, deltax, deltay, color);
	deltax = ((game->right_ray_hit_x) * 12) - game->player.pos_x * 12;
	deltay = ((game->right_ray_hit_y) * 12) - game->player.pos_y * 12;
	draw_fov(game, deltax, deltay, color);
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
	calculate_delta(game);
}

static void	draw_line(t_game *game, int line_height, double x, mlx_color color)
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

void	draw_walls(t_game *game, t_ray ray)
{
	mlx_color	color;
	int			line_height;

	color.rgba = 0x00FF00FF;
	if (ray.x == 0)
	{
		game->left_ray_hit_x = game->hit_x;
		game->left_ray_hit_y = game->hit_y;
	}
	else if (ray.x == WIDTH - 1)
	{
		game->right_ray_hit_x = game->hit_x;
		game->right_ray_hit_y = game->hit_y;
	}
	if (ray.side == 1)
	{
		if (ray.dir_y < 0)
			color.rgba /= 2;
		else
			color. rgba /= 4;
	}
	else
	{
		if (ray.dir_x < 0)
			color.rgba /= 3;
	}
	line_height = HEIGHT / game->perp_wall_dist;
	draw_line(game, line_height, ray.x, color);
}
