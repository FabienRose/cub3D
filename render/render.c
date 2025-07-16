/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:49:55 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/16 23:54:50 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	get_texture_pixel(t_game *game, int texture_index, int tex_x, int tex_y)
{
	int		offset;
	char	*data;
	int		color;

	if (texture_index < 0 || texture_index >= 4)
		return (0);
	if (tex_x < 0 || tex_x >= game->texture_width
		|| tex_y < 0 || tex_y >= game->texture_height)
		return (0);
	data = game->textures[texture_index].data;
	offset = (tex_y * game->textures[texture_index].sl)
		+ (tex_x * (game->textures[texture_index].bpp / 8));
	color = *(int *)(data + offset);
	return (color);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return ;
	dest = img->data + (y * img->sl + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}
