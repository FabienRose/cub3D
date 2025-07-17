/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:11:58 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/17 10:54:40 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "../cub3d.h"

typedef struct s_game	t_game;

typedef struct s_dda_data
{
	float	side_dist[2];
	float	delta_dist[2];
	int		step[2];
}	t_dda_data;

typedef struct s_ray
{
	float	angle;
	float	fov;
	int		side;
	float	perp_wall_dist;
	float	wall_x;
	int		tex_x;
	int		texture_index;
	float	ray_dir_x;
	float	ray_dir_y;
	int		map_x;
	int		map_y;
}	t_ray;

int		player_find_and_init(char **map, t_game *game);
int		is_wall_collision(float new_x, float new_y, t_game *game);
float	raycast_hit(t_game *game, t_ray *ray, float *hit_x, float *hit_y);
void	draw_single_ray(t_game *game, t_ray *ray);
void	cast_rays_90_degrees(t_game *game);
void	cast_rays_3d(t_game *game);
float	raycast_hit_dda(t_game *game, t_ray *ray, float *hit_x_y);

/* DDA algorithm functions */
void	calculate_delta_distances(t_ray *ray, float *delta_dist_x_y);
void	calculate_step_and_side_dist(t_game *game, t_ray *ray,
			t_dda_data *dda);
int		is_wall_hit(t_game *game, t_ray *ray);
int		is_out_of_bounds(t_game *game, t_ray *ray);
void	perform_dda_step(t_ray *ray, float *side_dist_x_y,
			float *delta_dist_x_y, int *step_x_y);

/* Raycast calculation utilities */
void	calculate_wall_distance(t_game *game, t_ray *ray,
			float *side_dist_x_y, float *delta_dist_x_y);
void	calculate_wall_x_position(t_game *game, t_ray *ray);
void	calculate_texture_coordinates(t_game *game, t_ray *ray);

#endif