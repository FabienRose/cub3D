/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:57:31 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/16 10:57:31 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../cub3d.h"

typedef struct s_game	t_game;
typedef struct s_img	t_img;

void	draw_line(int x0, int y0, int x1, int y1, t_game *game, int color);
void	draw_square(int x, int y, t_game *game, int size, int color);
int		get_texture_pixel(t_game *game, int texture_index, int tex_x, int tex_y);
void	draw_background(t_game *game);
void	draw_map(t_game *game);
void    put_pixel(t_img *img, int x, int y, int color);

#endif