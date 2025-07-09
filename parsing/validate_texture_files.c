/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture_files.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:00:21 by diana             #+#    #+#             */
/*   Updated: 2025/07/09 16:56:38 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	file_exists(char *path)
{
	int	fd;

	if (!path)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

static int	validate_single_texture(char *texture_path, char *texture_name)
{
	if (!file_exists(texture_path))
	{
		printf("Error: Texture file '%s' for %s does not exist\n", \
			texture_path, texture_name);
		return (0);
	}
	return (1);
}

int	validate_texture_files(t_config *cfg)
{
	if (!validate_single_texture(cfg->no_texture, "NO"))
		return (0);
	if (!validate_single_texture(cfg->so_texture, "SO"))
		return (0);
	if (!validate_single_texture(cfg->we_texture, "WE"))
		return (0);
	if (!validate_single_texture(cfg->ea_texture, "EA"))
		return (0);
	return (1);
}
