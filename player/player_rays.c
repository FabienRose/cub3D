/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:03:15 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/17 11:03:15 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static void	init_ray_direction(t_game *game, t_ray *ray)
{
	float	pos_x;
	float	pos_y;

	pos_x = game->player.x / game->cell_size;
	pos_y = game->player.y / game->cell_size;
	ray->ray_dir_x = cosf(ray->angle);
	ray->ray_dir_y = sinf(ray->angle);
	ray->map_x = (int)pos_x;
	ray->map_y = (int)pos_y;
}

static void	init_ray_struct(t_ray *ray)
{
	ray->side = 0;
	ray->perp_wall_dist = 0.0f;
	ray->wall_x = 0.0f;
	ray->tex_x = 0;
	ray->texture_index = 0;
	ray->ray_dir_x = 0.0f;
	ray->ray_dir_y = 0.0f;
	ray->map_x = 0;
	ray->map_y = 0;
}

static void	draw_textured_wall_stripe(t_game *game, t_ray *ray, int x,
	int wall_height)
{
	int	draw_start;
	int	draw_end;
	int	y;
	int	tex_y;
	int	color;

	draw_start = (WINDOW_HEIGHT - wall_height) / 2;
	draw_end = (WINDOW_HEIGHT + wall_height) / 2;
	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)((y - draw_start) * game->texture_height / wall_height);
		if (tex_y >= game->texture_height)
			tex_y = game->texture_height - 1;
		color = get_texture_pixel(game, ray->texture_index, ray->tex_x, tex_y);
		put_pixel(&game->img, x, y, color);
		y++;
	}
}

float	raycast_hit_dda(t_game *game, t_ray *ray, float *hit_x_y)
{
	t_dda_data	dda;
	int			hit;

	hit = 0;
	init_ray_direction(game, ray);
	calculate_delta_distances(ray, dda.delta_dist);
	calculate_step_and_side_dist(game, ray, &dda);
	while (!hit)
	{
		perform_dda_step(ray, dda.side_dist, dda.delta_dist, dda.step);
		if (is_wall_hit(game, ray))
			hit = 1;
		if (is_out_of_bounds(game, ray))
			break ;
	}
	calculate_wall_distance(game, ray, dda.side_dist, dda.delta_dist);
	calculate_wall_x_position(game, ray);
	calculate_texture_coordinates(game, ray);
	hit_x_y[0] = game->player.x + ray->ray_dir_x * ray->perp_wall_dist;
	hit_x_y[1] = game->player.y + ray->ray_dir_y * ray->perp_wall_dist;
	return (ray->perp_wall_dist);
}

void	cast_rays_3d(t_game *game)
{
	int		x;
	float	hit_x_y[2];	
	float	distance;
	int		wall_height;
	t_ray	ray;

	ray.fov = PI / 3;
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		ray.angle = game->player.angle - ray.fov / 2 + (ray.fov * x)
			/ WINDOW_WIDTH;
		init_ray_struct(&ray);
		distance = raycast_hit_dda(game, &ray, hit_x_y);
		if (distance > 0.1f)
		{
			distance = distance * cosf(ray.angle - game->player.angle);
			wall_height = (int)(WINDOW_HEIGHT * game->cell_size
					/ distance);
			draw_textured_wall_stripe(game, &ray, x, wall_height);
		}
		x++;
	}
}
