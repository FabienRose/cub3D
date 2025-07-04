/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:00:25 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/02 18:00:30 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../cub3d.h"

typedef struct s_game	t_game;

void	draw_square(int x, int y, t_game *game, int size, int color);
void	draw_line(int x1, int y1, int x2, int y2, t_game *game, int color);
void	draw_background(t_game *game);

#endif