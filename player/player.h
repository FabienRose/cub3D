/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:09:15 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/30 18:09:18 by fmixtur          ###   ########.ch       */
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
} t_ray;

int		find_and_init_player(char **map, int cell_size, t_game *game);
int		is_wall_collision(float new_x, float new_y, t_game *game);
float   raycast_hit(t_game *game, t_ray *ray, float *hit_x, float *hit_y);
void    draw_single_ray(t_game *game, t_ray *ray);
void    cast_rays_90_degrees(t_game *game);

#endif