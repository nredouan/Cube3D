/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:16:29 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/27 17:40:41 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_line(int tex_x, t_game *game, int line_height, double x, mlx_image	image)
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
	while (pixel < draw_end)
	{
		double d = pixel - HEIGHT / 2.0 + line_height / 2.0;
    	int tex_y = (int)(d * game->so_height / line_height);
    	if (tex_y < 0)
			tex_y = 0;
    	if (tex_y >= game->so_height)
			tex_y = game->so_height - 1;
		color = mlx_get_image_pixel(game->mlx, image, tex_x, tex_y);
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
	
	int			line_height;
	double		wallX;
	mlx_image	image;

	if (side == 0)
    	wallX = game->hit_y;
	else
    	wallX = game->hit_x;
	wallX -= floor(wallX);
	int tex_x = (int)(wallX * (double)game->so_width);
	line_height = HEIGHT / game->perp_wall_dist;
	draw_line(tex_x, game, line_height, x, image);
}
