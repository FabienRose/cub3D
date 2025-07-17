/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_raycast_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:11:31 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/17 09:11:36 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	calculate_wall_distance(t_game *game, t_ray *ray,
	float *side_dist_x_y, float *delta_dist_x_y)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (side_dist_x_y[0] - delta_dist_x_y[0])
			* game->cell_size;
	else
		ray->perp_wall_dist = (side_dist_x_y[1] - delta_dist_x_y[1])
			* game->cell_size;
}

void	calculate_wall_x_position(t_game *game, t_ray *ray)
{
	float	pos_x;
	float	pos_y;

	pos_x = game->player.x / game->cell_size;
	pos_y = game->player.y / game->cell_size;
	if (ray->side == 0)
		ray->wall_x = pos_y + (ray->perp_wall_dist / game->cell_size)
			* ray->ray_dir_y;
	else
		ray->wall_x = pos_x + (ray->perp_wall_dist / game->cell_size)
			* ray->ray_dir_x;
	ray->wall_x = ray->wall_x - floor(ray->wall_x);
}

void	calculate_texture_coordinates(t_game *game, t_ray *ray)
{
	ray->tex_x = (int)(ray->wall_x * game->texture_width);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		ray->tex_x = game->texture_width - ray->tex_x - 1;
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->texture_index = 2;
	else if (ray->side == 0 && ray->ray_dir_x < 0)
		ray->texture_index = 3;
	else if (ray->side == 1 && ray->ray_dir_y > 0)
		ray->texture_index = 1;
	else
		ray->texture_index = 0;
}
