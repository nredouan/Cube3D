/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 14:15:33 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/31 16:26:02 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_ceiling(t_game *game, int draw_start, double x)
{
	int	i;

	i = 0;
	while (i < draw_start)
	{
		mlx_pixel_put(game->mlx, game->window, x, i, game->color_c);
		i++;
	}
}

static void	draw_floor(t_game *game, int pixel, double x)
{
	while (pixel < HEIGHT)
	{
		mlx_pixel_put(game->mlx, game->window, x, pixel, game->color_f);
		pixel++;
	}
}

static mlx_image	get_wall_texture(t_game **game, t_ray ray)
{
	if (ray.side == 1)
	{
		if (ray.dir_y < 0)
			return ((*game)->no);
		return ((*game)->so);
	}
	else
	{
		if (ray.dir_x < 0)
			return ((*game)->we);
		return ((*game)->ea);
	}
}

static int	get_tex_y(t_game *game, int line_height, int pixel)
{
	double	d;
	int		tex_y;

	d = pixel - HEIGHT / 2.0 + line_height / 2.0;
	tex_y = (int)(d * game->image_height / line_height);
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= game->image_height)
		tex_y = game->image_height - 1;
	return (tex_y);
}

void	draw_line(int tex_x, t_game *game, int line_height, t_ray ray)
{
	int			pixel;
	int			draw_start;
	int			draw_end;
	mlx_color	color;

	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end > HEIGHT)
		draw_end = HEIGHT - 1;
	pixel = draw_start;
	draw_ceiling(game, draw_start, ray.x);
	while (pixel < draw_end)
	{
		color = mlx_get_image_pixel(game->mlx, get_wall_texture(&game, ray),
				tex_x, get_tex_y(game, line_height, pixel));
		mlx_pixel_put(game->mlx, game->window, ray.x, pixel, color);
		pixel++;
	}
	draw_floor(game, pixel, ray.x);
}
