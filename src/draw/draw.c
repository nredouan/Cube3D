/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:16:29 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/29 11:42:42 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_ceiling(t_game *game, int draw_start, double x)
{
	int	i;

	i = 0;
	while (i < draw_start)
	{
		mlx_pixel_put(game->mlx, game->window, x, i, game->color_c);
		i++;
	}
}

void	draw_floor(t_game *game, int pixel, double x)
{
	while (pixel < HEIGHT)
	{
		mlx_pixel_put(game->mlx, game->window, x, pixel, game->color_f);
		pixel++;
	}
}

void	draw_line(int tex_x, t_game *game, int line_height, double x)
{
	int			pixel;
	int			draw_start;
	int			draw_end;
	mlx_color	color;
	double		d;
	int			tex_y;

	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end > HEIGHT)
		draw_end = HEIGHT - 1;
	pixel = draw_start;
	draw_ceiling(game, draw_start, x);
	while (pixel < draw_end)
	{
		d = pixel - HEIGHT / 2.0 + line_height / 2.0;
		tex_y = (int)(d * game->so_height / line_height);
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= game->so_height)
			tex_y = game->so_height - 1;
		color = mlx_get_image_pixel(game->mlx, game->so, tex_x, tex_y);
		mlx_pixel_put(game->mlx, game->window, x, pixel, color);
		pixel++;
	}
}

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
	draw_floor(game, pixel, x);
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

mlx_color	get_color(int rgb[3])
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

	color.r = rgb[0];
	color.g = rgb[1];
	color.b = rgb[2];
	color.a = 255;
	return (color);
}

void	draw_walls(t_game *game, int side, double x)
{
	int			line_height;
	double		wallX;
	int			tex_x;
	// mlx_image	image;

	game->color_c = get_color(game->c);
	game->color_f = get_color(game->f);
	if (side == 0)
		wallX = game->hit_y;
	else
		wallX = game->hit_x;
	wallX -= floor(wallX);
	tex_x = (int)(wallX * (double)game->so_width);
	line_height = HEIGHT / game->perp_wall_dist;
	draw_line(tex_x, game, line_height, x);
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
