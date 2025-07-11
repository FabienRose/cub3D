/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:25:07 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/11 15:25:58 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return ;
	dest = img->data + (y * img->sl + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}

void	draw_square(int x, int y, t_game *game, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(&game->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_line(int x1, int y1, int x2, int y2, t_game *game, int color)
{
	int	dx = abs(x2 - x1);
	int	dy = abs(y2 - y1);
	int	sx = x1 < x2 ? 1 : -1;
	int	sy = y1 < y2 ? 1 : -1;
	int	err = dx - dy;
	int	x = x1;
	int	y = y1;
	int	e2;

	while (1)
	{
		if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
			put_pixel(&game->img, x, y, color);
		if (x == x2 && y == y2)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y += sy;
		}
	}
}

void	draw_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			put_pixel(&game->img, x, y, game->config.ceiling_color);
			x++;
		}
		y++;
	}
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			put_pixel(&game->img, x, y, game->config.floor_color);
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				draw_square(j * game->cell_size, i * game->cell_size,
					game, game->cell_size, 0xAAAAAA);
			else if (game->map[i][j] == ' ')
				draw_square(j * game->cell_size, i * game->cell_size,
					game, game->cell_size, 0x222222);
			else
				draw_square(j * game->cell_size, i * game->cell_size,
					game, game->cell_size, 0x444444);
			j++;
		}
		i++;
	}
}
