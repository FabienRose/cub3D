/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:18:01 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/22 17:18:01 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dest;

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
