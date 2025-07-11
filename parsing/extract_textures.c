/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:03:39 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/11 15:04:25 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	extract_north_texture(char **config_lines, t_config *cfg)
{
	int		i;
	char	*clean_line;

	i = 0;
	while (config_lines[i])
	{
		clean_line = ft_reduce_spaces(config_lines[i]);
		if (clean_line && ft_strncmp(clean_line, "NO ", 3) == 0)
		{
			if (assign_texture(&cfg->no_texture, ft_clean_path(clean_line + 3)) \
				== 0)
			{
				free(clean_line);
				printf("TEST\n");
				return (0);
			}
		}
		if (clean_line)
			free(clean_line);
		i++;
	}
	return (1);
}

int	extract_south_texture(char **config_lines, t_config *cfg)
{
	int		i;
	char	*clean_line;

	i = 0;
	while (config_lines[i])
	{
		clean_line = ft_reduce_spaces(config_lines[i]);
		if (clean_line && ft_strncmp(clean_line, "SO ", 3) == 0)
		{
			if (assign_texture(&cfg->so_texture, ft_clean_path(clean_line + 3)) \
			== 0)
			{
				free(clean_line);
				return (0);
			}
		}
		if (clean_line)
			free(clean_line);
		i++;
	}
	return (1);
}

int	extract_west_texture(char **config_lines, t_config *cfg)
{
	int		i;
	char	*clean_line;

	i = 0;
	while (config_lines[i])
	{
		clean_line = ft_reduce_spaces(config_lines[i]);
		if (clean_line && ft_strncmp(clean_line, "WE ", 3) == 0)
		{
			if (assign_texture(&cfg->we_texture, ft_clean_path(clean_line + 3)) \
			== 0)
			{
				free(clean_line);
				return (0);
			}
		}
		if (clean_line)
			free(clean_line);
		i++;
	}
	return (1);
}

int	extract_east_texture(char **config_lines, t_config *cfg)
{
	int		i;
	char	*clean_line;

	i = 0;
	while (config_lines[i])
	{
		clean_line = ft_reduce_spaces(config_lines[i]);
		if (clean_line && ft_strncmp(clean_line, "EA ", 3) == 0)
		{
			if (assign_texture(&cfg->ea_texture, ft_clean_path(clean_line + 3)) \
			== 0)
			{
				free(clean_line);
				return (0);
			}
		}
		if (clean_line)
			free(clean_line);
		i++;
	}
	return (1);
}
