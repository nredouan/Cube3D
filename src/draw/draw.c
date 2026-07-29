/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:16:29 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/29 16:09:28 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_fov(t_game *game, float deltax, float deltay, mlx_color color)
{
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	pixel_x = game->player.pos_x * 6;
	pixel_y = game->player.pos_y * 6;
	while (pixels)
	{
		mlx_pixel_put(game->mlx, game->window, pixel_x, pixel_y, color);
		pixel_x += deltax;
		pixel_y += deltay;
		pixels--;
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
	mlx_pixel_put_region(game->mlx, game->window, game->player.pos_x * 6 - 1,
		game->player.pos_y * 6 - 1, 3, 3, green);
	calculate_delta(game);
}

mlx_color	get_color(int rgb[3])
{
	mlx_color	color;

	color.r = rgb[0];
	color.g = rgb[1];
	color.b = rgb[2];
	color.a = 255;
	return (color);
}

void	draw_walls(t_game *game, t_ray ray)
{
	int			line_height;
	int			tex_x;
	double		wall_x;

	game->color_c = get_color(game->c);
	game->color_f = get_color(game->f);
	if (ray.side == 0)
		wall_x = game->hit_y;
	else
		wall_x = game->hit_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)game->image_width);
	line_height = HEIGHT / game->perp_wall_dist;
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
	draw_line(tex_x, game, line_height, ray);
}
