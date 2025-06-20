/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 23:42:08 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/19 23:44:41 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dest;

	dest = img->data + (y * img->sl + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}

void	draw_square(int x, int y, t_game *game, int color)
{
	int	i;

	i = 0;
	while (i <= 10)
	{
		put_pixel(&game->img, x + i, y, color);
		put_pixel(&game->img, x, y + i, color);
		put_pixel(&game->img, x + 10, y + i, color);
		put_pixel(&game->img, x + i, y + 10, color);
		i++;
	}
}