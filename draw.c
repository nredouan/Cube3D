/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:16:29 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/15 17:56:23 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_line(t_game *game, float startx, float starty, float endx, float endy)
{
	mlx_color	red;
	
	red.rgba = 0xFF0000FF;
	float deltax = endx - startx;
	float deltay = endy - starty;
	int pixels = sqrt((deltax * deltax) + (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	double pixelX = startx;
	double pixelY = starty;
	while (pixels)
	{
		mlx_pixel_put(game->mlx, game->window, pixelX, pixelY, red);
		pixelX += deltax;
		pixelY += deltay;
		--pixels;
	}
}

void	draw_map(t_game *game)
{
	int	y = 0;
	int	x = 0;

	mlx_color pixels_b[64 * 64] = { 0 };
	mlx_color pixels_w[64 * 64] = { 0 };
	int i = 0;
	for(int y2 = 0; y2 < 64; y2++)
	{
		for(int x2 = 0; x2 < 64; x2++, i++)
			pixels_b[i].rgba = 0xFFFFFFFF;
	}
	i = 0;
	for(int y2 = 0; y2 < 64; y2++)
	{
		for(int x2 = 0; x2 < 64; x2++, i++)
			pixels_w[i].rgba = 0x80808080;
	}
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_pixel_put_region(game->mlx, game->window, x * 64, y * 64, 63, 63, pixels_b);
			else if (game->map[y][x] != '\n')
				mlx_pixel_put_region(game->mlx, game->window, x * 64, y * 64, 63, 63, pixels_w);
			x++;
		}
		y++;
	}	
}

void	draw_player(t_game *game)
{
	mlx_color	green[8 * 8] = { 0 };
	int			i = 0;
	
	for(int y2 = 0; y2 < 8; y2++)
	{
		for(int x2 = 0; x2 < 8; x2++, i++)
			green[i].rgba = 0x00FF00FF;
	}
	mlx_pixel_put_region(game->mlx, game->window, game->player.px, game->player.py, 8, 8, green);
	draw_line(game, game->player.px + 3, game->player.py + 3, game->player.px + 20 * game->player.dx, game->player.py + 20 * game->player.dy);
}

void	draw_rays(t_game *game)
{
	int r, mx, my, mp, dof;
	float rx, ry, ra, xo, yo;
	mlx_color	red;

	ra = game->player.pa;
	red.rgba = 0xFF0000FF;
	for (r = 0; r < 1; r++)
	{
		dof = 0;
		float aTan = -1/tan(ra);
		if (ra > PI)
		{
			ry = (((int)game->player.py >> 6) << 6) - 0.0001;
			rx = (game->player.py - ry) * aTan + game->player.px;
			yo = -64;
			xo = - yo * aTan;
		}
		if (ra < PI)
		{
			ry = (((int)game->player.py >> 6) << 6) + 64;
			rx = (game->player.py - ry) * aTan + game->player.px;
			yo = 64;
			xo = - yo * aTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = game->player.px;
			ry = game->player.py;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			mp = my * 13 + mx;
			if (mp < 13 * 7 && game->map[my][mx] == '1')
				dof = 8;
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;	
			}
		}
		draw_line(game, game->player.px + 3, game->player.py + 3, rx, ry);
	}
}
