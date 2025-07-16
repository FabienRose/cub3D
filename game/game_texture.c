/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:11:49 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/16 22:11:49 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	load_single_texture(t_game *game, int index, char *texture_path,
	char *direction)
{
	game->textures[index].img = mlx_xpm_file_to_image(game->mlx,
			texture_path, &game->texture_width, &game->texture_height);
	if (!game->textures[index].img)
	{
		printf("Failed to load %s texture: %s\n", direction, texture_path);
		return (0);
	}
	game->textures[index].data = mlx_get_data_addr(game->textures[index].img,
			&game->textures[index].bpp, &game->textures[index].sl,
			&game->textures[index].endian);
	return (1);
}

static char	*get_texture_path_by_index(t_game *game, int index)
{
	char	*texture_paths[4];

	texture_paths[0] = game->config.no_texture;
	texture_paths[1] = game->config.so_texture;
	texture_paths[2] = game->config.ea_texture;
	texture_paths[3] = game->config.we_texture;
	if (index >= 0 && index < 4)
		return (texture_paths[index]);
	return (NULL);
}

static char	*get_direction_name_by_index(int index)
{
	char	*direction_names[4];

	direction_names[0] = "NO";
	direction_names[1] = "SO";
	direction_names[2] = "EA";
	direction_names[3] = "WE";
	if (index >= 0 && index < 4)
		return (direction_names[index]);
	return ("UNKNOWN");
}

int	load_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!load_single_texture(game, i, get_texture_path_by_index(game, i),
				get_direction_name_by_index(i)))
			return (0);
		i++;
	}
	return (1);
}
