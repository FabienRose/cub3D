/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:42:38 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/17 10:42:38 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	calculate_delta_distances(t_ray *ray, float *delta_dist_x_y)
{
	delta_dist_x_y[0] = fabs(1 / ray->ray_dir_x);
	delta_dist_x_y[1] = fabs(1 / ray->ray_dir_y);
}

void	calculate_step_and_side_dist(t_game *game, t_ray *ray,
	t_dda_data *dda)
{
	float	pos_x;
	float	pos_y;

	pos_x = game->player.x / game->cell_size;
	pos_y = game->player.y / game->cell_size;
	if (ray->ray_dir_x < 0)
	{
		dda->step[0] = -1;
		dda->side_dist[0] = (pos_x - ray->map_x) * dda->delta_dist[0];
	}
	else
	{
		dda->step[0] = 1;
		dda->side_dist[0] = (ray->map_x + 1.0 - pos_x) * dda->delta_dist[0];
	}
	if (ray->ray_dir_y < 0)
	{
		dda->step[1] = -1;
		dda->side_dist[1] = (pos_y - ray->map_y) * dda->delta_dist[1];
	}
	else
	{
		dda->step[1] = 1;
		dda->side_dist[1] = (ray->map_y + 1.0 - pos_y) * dda->delta_dist[1];
	}
}

int	is_wall_hit(t_game *game, t_ray *ray)
{
	if (ray->map_y >= 0 && ray->map_x >= 0 && game->map[ray->map_y]
		&& ray->map_x < (int)ft_strlen(game->map[ray->map_y])
		&& game->map[ray->map_y][ray->map_x] == '1')
		return (1);
	return (0);
}

int	is_out_of_bounds(t_game *game, t_ray *ray)
{
	if (ray->map_y < 0 || !game->map[ray->map_y] || ray->map_x < 0
		|| ray->map_x >= (int)ft_strlen(game->map[ray->map_y]))
		return (1);
	return (0);
}

void	perform_dda_step(t_ray *ray, float *side_dist_x_y,
	float *delta_dist_x_y, int *step_x_y)
{
	if (side_dist_x_y[0] < side_dist_x_y[1])
	{
		side_dist_x_y[0] += delta_dist_x_y[0];
		ray->map_x += step_x_y[0];
		ray->side = 0;
	}
	else
	{
		side_dist_x_y[1] += delta_dist_x_y[1];
		ray->map_y += step_x_y[1];
		ray->side = 1;
	}
}
