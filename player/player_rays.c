/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 23:33:55 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/30 23:34:14 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static int	raycast_loop(t_game *game, t_ray *ray)
{
	int	map_x;
	int	map_y;

	while (ray->distance < WINDOW_WIDTH)
	{
		ray->ray_x += cosf(ray->angle);
		ray->ray_y += sinf(ray->angle);
		ray->distance += 1.0f;
		map_x = (int)(ray->ray_x) / game->cell_size;
		map_y = (int)(ray->ray_y) / game->cell_size;
		if (map_y < 0 || !game->map[map_y]
			|| map_x < 0 || !game->map[map_y][map_x])
			return (0);
		if (game->map[map_y][map_x] == '1')
			return (1);
	}
	return (0);
}

float	raycast_hit(t_game *game, t_ray *ray, float *hit_x, float *hit_y)
{
	ray->ray_x = game->player.x;
	ray->ray_y = game->player.y;
	ray->distance = 0.0f;
	if (raycast_loop(game, ray))
	{
		*hit_x = ray->ray_x;
		*hit_y = ray->ray_y;
		return (ray->distance);
	}
	*hit_x = ray->ray_x;
	*hit_y = ray->ray_y;
	return (ray->distance);
}

void	draw_single_ray(t_game *game, t_ray *ray)
{
	float	hit_x;
	float	hit_y;

	raycast_hit(game, ray, &hit_x, &hit_y);
	draw_line(game->player.x, game->player.y, hit_x, hit_y, game, 0x0000FF);
	draw_square(hit_x - 2, hit_y - 2, game, 4, 0xFF0000);
}

void	cast_rays_90_degrees(t_game *game)
{
	int		num_rays;
	float	fov;
	float	angle_step;
	float	start_angle;
	int		i;
	float	current_angle;
	t_ray	ray;

	num_rays = 100;
	fov = PI / 2;
	start_angle = game->player.angle - fov / 2;
	angle_step = fov / num_rays;
	i = 0;
	while (i < num_rays)
	{
		current_angle = start_angle + (i * angle_step);
		ray.angle = current_angle;
		draw_single_ray(game, &ray);
		i++;
	}
}
