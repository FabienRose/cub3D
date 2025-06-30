/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:49:37 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/28 18:49:47 by fmixtur          ###   ########.ch       */
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

	while (1)
	{
		if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
			put_pixel(&game->img, x, y, color);
		
		if (x == x2 && y == y2)
			break;
		
		int	e2 = 2 * err;
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
