/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:20:07 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/16 17:20:46 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	extract_texture_by_prefix(char **config_lines, char **target_field,
	const char *prefix)
{
	int		i;
	char	*clean_line;

	i = 0;
	while (config_lines[i])
	{
		clean_line = ft_reduce_spaces(config_lines[i]);
		if (clean_line && ft_strncmp(clean_line, prefix, 3) == 0)
		{
			char *clean_path = ft_clean_path(clean_line + 3);
			if (assign_texture(target_field, clean_path) == 0)
			{
				free(clean_path);
				free(clean_line);
				return (0);
			}
			free(clean_path);
		}
		if (clean_line)
			free(clean_line);
		i++;
	}
	return (1);
}

int	extract_north_texture(char **config_lines, t_config *cfg)
{
	return (extract_texture_by_prefix(config_lines, &cfg->no_texture, "NO "));
}

int	extract_south_texture(char **config_lines, t_config *cfg)
{
	return (extract_texture_by_prefix(config_lines, &cfg->so_texture, "SO "));
}

int	extract_west_texture(char **config_lines, t_config *cfg)
{
	return (extract_texture_by_prefix(config_lines, &cfg->we_texture, "WE "));
}

int	extract_east_texture(char **config_lines, t_config *cfg)
{
	return (extract_texture_by_prefix(config_lines, &cfg->ea_texture, "EA "));
}
