/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 15:53:59 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/28 13:16:00 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	calculate_hit(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

static void	init_step_and_side(t_game *game, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x)
			* ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.pos_y)
			* ray->delta_y;
	}
}

static void	init_ray(t_game *game, t_ray *ray)
{
	ray->camera_x = 2 * ray->x / WIDTH - 1;
	ray->dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
	ray->dir_y = game->player.dir_y + game->player.plane_y * ray->camera_x;
	if (ray->dir_x == 0)
		ray->dir_x = 1e30;
	if (ray->dir_y == 0)
		ray->dir_y = 1e30;
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
	ray->delta_x = fabs(1 / ray->dir_x);
	ray->delta_y = fabs(1 / ray->dir_y);
}

void	calc_rays(t_game *game)
{
	t_ray	ray;

	ray.x = 0;
	game->player.plane_x = -(game->player.dir_y) * 0.66;
	game->player.plane_y = game->player.dir_x * 0.66;
	while (ray.x < WIDTH)
	{
		init_ray(game, &ray);
		init_step_and_side(game, &ray);
		calculate_hit(game, &ray);
		if (ray.side == 0)
			game->perp_wall_dist = (ray.side_dist_x - ray.delta_x);
		else
			game->perp_wall_dist = (ray.side_dist_y - ray.delta_y);
		game->hit_x = game->player.pos_x + ray.dir_x * game->perp_wall_dist;
		game->hit_y = game->player.pos_y + ray.dir_y * game->perp_wall_dist;
		draw_walls(game, ray.side, ray.x);
		ray.x++;
	}
}
