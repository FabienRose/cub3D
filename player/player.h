/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:18:52 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/16 10:18:52 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "../cub3d.h"

typedef struct s_game	t_game;

typedef struct s_ray
{
	float	angle;
	float	fov;
	int		side;			// 0 = vertical wall (E/W), 1 = horizontal wall (N/S)
	float	perp_wall_dist;	// Perpendicular wall distance for correct projection
	float	wall_x;			// Exact hit position on wall (0.0 to 1.0)
	int		tex_x;			// X coordinate on texture (0 to texture_width-1)
	int		texture_index;	// Which texture to use (0=N, 1=S, 2=E, 3=W)
	float	ray_dir_x;		// Ray direction X component
	float	ray_dir_y;		// Ray direction Y component
	int		map_x;			// Map square X coordinate
	int		map_y;			// Map square Y coordinate
}	t_ray;

int		player_find_and_init(char **map, t_game *game);
int		is_wall_collision(float new_x, float new_y, t_game *game);
float	raycast_hit(t_game *game, t_ray *ray, float *hit_x, float *hit_y);
void	draw_single_ray(t_game *game, t_ray *ray);
void	cast_rays_90_degrees(t_game *game);
void	cast_rays_3d(t_game *game);

#endif