/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:02:39 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/15 08:02:39 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "../cub3d.h"

typedef struct s_game	t_game;

typedef struct s_ray
{
	float	angle;
	float	ray_x;
	float	ray_y;
	float	distance;
	float	fov;
}	t_ray;

int	player_find_and_init(char **map, t_game *game);
int		is_wall_collision(float new_x, float new_y, t_game *game);
float	raycast_hit(t_game *game, t_ray *ray, float *hit_x, float *hit_y);
void	draw_single_ray(t_game *game, t_ray *ray);
void	cast_rays_90_degrees(t_game *game);
void	cast_rays_3d(t_game *game);

#endif