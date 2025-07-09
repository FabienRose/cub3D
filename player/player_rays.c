/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:16:23 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/02 16:02:34 by fmixtur          ###   ########.ch       */
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
			|| map_x < 0 || map_x >= (int)ft_strlen(game->map[map_y]))
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

float raycast_hit_dda(t_game *game, t_ray *ray, float *hit_x, float *hit_y)
{
	int map_x, map_y;
	float ray_dir_x, ray_dir_y;
	float side_dist_x, side_dist_y;
	float delta_dist_x, delta_dist_y;
	int step_x, step_y;
	int hit = 0;
	int side;
	float perp_wall_dist;

	float pos_x = game->player.x;
	float pos_y = game->player.y;

	ray_dir_x = cosf(ray->angle);
	ray_dir_y = sinf(ray->angle);

	map_x = (int)(pos_x / game->cell_size);
	map_y = (int)(pos_y / game->cell_size);

	delta_dist_x = fabs(1 / ray_dir_x);
	delta_dist_y = fabs(1 / ray_dir_y);

	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (pos_x - map_x * game->cell_size) * delta_dist_x / game->cell_size;
	}
	else
	{
		step_x = 1;
		side_dist_x = ((map_x + 1) * game->cell_size - pos_x) * delta_dist_x / game->cell_size;
	}
	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (pos_y - map_y * game->cell_size) * delta_dist_y / game->cell_size;
	}
	else
	{
		step_y = 1;
		side_dist_y = ((map_y + 1) * game->cell_size - pos_y) * delta_dist_y / game->cell_size;
	}

	while (!hit)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}
		if (map_y >= 0 && map_x >= 0 && game->map[map_y] && 
			map_x < (int)ft_strlen(game->map[map_y]) && game->map[map_y][map_x] == '1')
			hit = 1;
		if (map_y < 0 || !game->map[map_y] || map_x < 0 || 
			map_x >= (int)ft_strlen(game->map[map_y]))
			break;
	}

	if (side == 0)
		perp_wall_dist = (side_dist_x - delta_dist_x);
// (ou pareil pour side_dist_y)
	else
		perp_wall_dist = (side_dist_y - delta_dist_y);
// (ou pareil pour side_dist_y)

	*hit_x = pos_x + ray_dir_x * perp_wall_dist;
	*hit_y = pos_y + ray_dir_y * perp_wall_dist;
	return perp_wall_dist;
}

void	draw_single_ray(t_game *game, t_ray *ray)
{
	float	hit_x;
	float	hit_y;

	raycast_hit_dda(game, ray, &hit_x, &hit_y);
	draw_line(game->player.x, game->player.y, hit_x, hit_y, game, 0x0000FF);
	draw_square(hit_x - 2, hit_y - 2, game, 4, 0xFF0000);
}

// void	cast_rays_90_degrees(t_game *game)
// {
// 	int		num_rays;
// 	float	angle_step;
// 	float	start_angle;
// 	float	current_angle;
// 	t_ray	ray;

// 	num_rays = WINDOW_WIDTH;
// 	ray.fov = PI / 3;
// 	start_angle = game->player.angle - ray.fov / 2;
// 	angle_step = ray.fov / num_rays;
// 	while (num_rays)
// 	{
// 		current_angle = start_angle + (num_rays * angle_step);
// 		ray.angle = current_angle;
// 		draw_single_ray(game, &ray);
// 		num_rays--;
// 	}
// }

void cast_rays_3d(t_game *game)
{
	int x;
	float ray_angle;
	float hit_x, hit_y;
	float distance;
	int wall_height;
	t_ray ray;

	ray.fov = PI / 3; // 60 degrés
	for (x = 0; x < WINDOW_WIDTH; x++)
	{
		ray_angle = game->player.angle - ray.fov / 2 + (ray.fov * x) / WINDOW_WIDTH;
		ray.angle = ray_angle;
		distance = raycast_hit_dda(game, &ray, &hit_x, &hit_y);
		if (distance > 0.1f)
		{
			float corrected_distance = distance * cosf(ray.angle - game->player.angle);
			wall_height = (int)(WINDOW_HEIGHT / corrected_distance);
			if (wall_height > WINDOW_HEIGHT) wall_height = WINDOW_HEIGHT;
			draw_line(x, (WINDOW_HEIGHT - wall_height) / 2, x, (WINDOW_HEIGHT + wall_height) / 2, game, 0xFF0000);
		}
	}
}
