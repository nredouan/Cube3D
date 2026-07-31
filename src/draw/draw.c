/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:16:29 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/31 16:32:45 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_fov(t_game *game, float deltax, float deltay, mlx_color color)
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

mlx_color	get_color(int rgb[3])
{
	mlx_color	color;

	color.r = rgb[0];
	color.g = rgb[1];
	color.b = rgb[2];
	color.a = 255;
	return (color);
}

void	change_image_value(t_game **game, int height, int width)
{
	(*game)->image_height = height;
	(*game)->image_width = width;
}

static void	change_value_of_image(t_game **game, t_ray ray)
{
	if (ray.side == 1)
	{
		if (ray.dir_y < 0)
			change_image_value(game,
				(*game)->texture_height[0], (*game)->texture_width[0]);
		else
			change_image_value(game,
				(*game)->texture_height[1], (*game)->texture_width[1]);
	}
	else
	{
		if (ray.dir_x < 0)
			change_image_value(game,
				(*game)->texture_height[2], (*game)->texture_width[2]);
		else
			change_image_value(game,
				(*game)->texture_height[3], (*game)->texture_width[3]);
	}
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
	change_value_of_image(&game, ray);
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
