/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:58:32 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/16 23:58:32 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

float raycast_hit_dda(t_game *game, t_ray *ray, float *hit_x, float *hit_y)
{
	float side_dist_x, side_dist_y;
	float delta_dist_x, delta_dist_y;
	int step_x, step_y;
	int hit = 0;

	// Convert to grid coordinates (0.0 to 1.0 within each cell)
	float pos_x = game->player.x / game->cell_size;
	float pos_y = game->player.y / game->cell_size;

	ray->ray_dir_x = cosf(ray->angle);
	ray->ray_dir_y = sinf(ray->angle);

	ray->map_x = (int)pos_x;
	ray->map_y = (int)pos_y;

	delta_dist_x = fabs(1 / ray->ray_dir_x);
	delta_dist_y = fabs(1 / ray->ray_dir_y);

	if (ray->ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (pos_x - ray->map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (ray->map_x + 1.0 - pos_x) * delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (pos_y - ray->map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (ray->map_y + 1.0 - pos_y) * delta_dist_y;
	}

	while (!hit)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			ray->map_x += step_x;
			ray->side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			ray->map_y += step_y;
			ray->side = 1;
		}
		if (ray->map_y >= 0 && ray->map_x >= 0 && game->map[ray->map_y] && 
			ray->map_x < (int)ft_strlen(game->map[ray->map_y]) && game->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
		if (ray->map_y < 0 || !game->map[ray->map_y] || ray->map_x < 0 || 
			ray->map_x >= (int)ft_strlen(game->map[ray->map_y]))
			break;
	}

	if (ray->side == 0)
		ray->perp_wall_dist = (side_dist_x - delta_dist_x) * game->cell_size;
	else
		ray->perp_wall_dist = (side_dist_y - delta_dist_y) * game->cell_size;

	// Calculate wall_x (exact hit position on wall)
	if (ray->side == 0)
		ray->wall_x = pos_y + (ray->perp_wall_dist / game->cell_size) * ray->ray_dir_y;
	else
		ray->wall_x = pos_x + (ray->perp_wall_dist / game->cell_size) * ray->ray_dir_x;
	
	// Get fractional part (position within the cell, 0.0 to 1.0)
	ray->wall_x = ray->wall_x - floor(ray->wall_x);

	// Calculate texture X coordinate (stretch texture to fit cell)
	ray->tex_x = (int)(ray->wall_x * game->texture_width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1 && ray->ray_dir_y < 0))
		ray->tex_x = game->texture_width - ray->tex_x - 1;

	// Determine texture index based on side and direction
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->texture_index = 2; // East
	else if (ray->side == 0 && ray->ray_dir_x < 0)
		ray->texture_index = 3; // West
	else if (ray->side == 1 && ray->ray_dir_y > 0)
		ray->texture_index = 1; // South
	else
		ray->texture_index = 0; // North

	*hit_x = game->player.x + ray->ray_dir_x * ray->perp_wall_dist;
	*hit_y = game->player.y + ray->ray_dir_y * ray->perp_wall_dist;
	return ray->perp_wall_dist;
}


void cast_rays_3d(t_game *game)
{
	int x;
	float ray_angle;
	float hit_x, hit_y;
	float distance;
	int wall_height;
	t_ray ray;

	ray.fov = PI / 3;
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		ray_angle = game->player.angle - ray.fov / 2 + (ray.fov * x) / WINDOW_WIDTH;
		ray.angle = ray_angle;
		
		// Initialize ray struct (raycast_hit_dda will fill the rest)
		ray.side = 0;
		ray.perp_wall_dist = 0.0f;
		ray.wall_x = 0.0f;
		ray.tex_x = 0;
		ray.texture_index = 0;
		ray.ray_dir_x = 0.0f;
		ray.ray_dir_y = 0.0f;
		ray.map_x = 0;
		ray.map_y = 0;
		
		distance = raycast_hit_dda(game, &ray, &hit_x, &hit_y);
		if (distance > 0.1f)
		{
			float corrected_distance = distance * cosf(ray.angle - game->player.angle);
			// Scale the distance for proper wall height calculation
			wall_height = (int)(WINDOW_HEIGHT * game->cell_size / corrected_distance);
			// if (wall_height > WINDOW_HEIGHT)
			// 	wall_height = WINDOW_HEIGHT;
			
			// Draw textured wall stripe
			int draw_start = (WINDOW_HEIGHT - wall_height) / 2;
			int draw_end = (WINDOW_HEIGHT + wall_height) / 2;
			int y = draw_start;
			
			while (y < draw_end)
			{
				// Calculate texture Y coordinate
				int tex_y = (int)((y - draw_start) * game->texture_height / wall_height);
				if (tex_y >= game->texture_height)
					tex_y = game->texture_height - 1;
				
				// Get texture color
				int color = get_texture_pixel(game, ray.texture_index, ray.tex_x, tex_y);
				
				// Draw pixel
				put_pixel(&game->img, x, y, color);
				y++;
			}
		}
		x++;
	}
}
