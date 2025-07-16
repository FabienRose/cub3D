/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:55:51 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/16 23:56:09 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	draw_horizontal_line(int y, t_game *game, int color)
{
	int	x;
	int	x_start;
	int	x_end;
	int	x1;
	int	x2;

	x1 = 0;
	x2 = WINDOW_WIDTH - 1;
	if (x1 < x2)
	{
		x_start = x1;
		x_end = x2;
	}
	else
	{
		x_start = x2;
		x_end = x1;
	}
	x = x_start;
	while (x <= x_end)
	{
		put_pixel(&game->img, x, y, color);
		x++;
	}
}

void	draw_background(t_game *game)
{
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		draw_horizontal_line(y, game,
			game->config.ceiling_color);
		y++;
	}
	while (y < WINDOW_HEIGHT)
	{
		draw_horizontal_line(y,
			game, game->config.floor_color);
		y++;
	}
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->square_size = game->minimap_cell_size;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				draw_square(j * game->minimap_cell_size, i * game->square_size,
					game, 0xAAAAAA);
			else if (game->map[i][j] == ' ')
				draw_square(j * game->minimap_cell_size, i * game->square_size,
					game, 0x222222);
			else
				draw_square(j * game->minimap_cell_size, i * game->square_size,
					game, 0x444444);
			j++;
		}
		i++;
	}
}

void	draw_square(int x, int y, t_game *game, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->square_size)
	{
		j = 0;
		while (j < game->square_size)
		{
			put_pixel(&game->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
