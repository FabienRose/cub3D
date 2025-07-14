/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:24:31 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/14 23:50:21 by fmixtur          ###   ########.ch       */
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

static void	draw_vertical_line(int x, int y1, int y2, t_game *game, int color)
{
	int y;
	int y_start;
	int y_end;

	if (y1 < y2)
	{
		y_start = y1;
		y_end = y2;
	}
	else
	{
		y_start = y2;
		y_end = y1;
	}
	y = y_start;
	while (y <= y_end)
	{
		put_pixel(&game->img, x, y, color);
		y++;
	}
}

static void	draw_horizontal_line(int x1, int x2, int y, t_game *game, int color)
{
	int x;
	int x_start;
	int x_end;

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

void	draw_line(int x1, int y1, int x2, int y2, t_game *game, int color)
{
	if (x1 == x2)
		draw_vertical_line(x1, y1, y2, game, color);
	else if (y1 == y2)
		draw_horizontal_line(x1, x2, y1, game, color);
}

void	draw_background(t_game *game)
{
	int y;

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		draw_horizontal_line(0, WINDOW_WIDTH - 1, y, game, game->config.ceiling_color);
		y++;
	}
	while (y < WINDOW_HEIGHT)
	{
		draw_horizontal_line(0, WINDOW_WIDTH - 1, y, game, game->config.floor_color);
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

void draw_square(int x, int y, t_game *game, int size, int color)
{
	int i;
	int j;

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
