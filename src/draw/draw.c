/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:16:29 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/28 13:25:58 by scegla           ###   ########.fr       */
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
	int	pixel;
	int	draw_start;
	int	draw_end;
	mlx_color	color;
	
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
		double d = pixel - HEIGHT / 2.0 + line_height / 2.0;
    	int tex_y = (int)(d * game->so_height / line_height);
    	if (tex_y < 0)
			tex_y = 0;
    	if (tex_y >= game->so_height)
			tex_y = game->so_height - 1;
		color = mlx_get_image_pixel(game->mlx, game->so, tex_x, tex_y);
		mlx_pixel_put(game->mlx, game->window, x, pixel, color);
		pixel++;
	}
	draw_floor(game, pixel, x);
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

mlx_color get_color(int rgb[3])
{
    mlx_color color;

    color.rgba = (rgb[0] << 24) | (rgb[1] << 16) | (rgb[2] << 8) | 0xFF;
    return (color);
}

void	draw_walls(t_game *game, int side, double x)
{
	
	int			line_height;
	double		wallX;
	// mlx_image	image;

	game->color_c = get_color(game->c);
	game->color_f = get_color(game->f);
	if (side == 0)
    	wallX = game->hit_y;
	else
    	wallX = game->hit_x;
	wallX -= floor(wallX);
	int tex_x = (int)(wallX * (double)game->so_width);
	line_height = HEIGHT / game->perp_wall_dist;
	draw_line(tex_x, game, line_height, x);
}