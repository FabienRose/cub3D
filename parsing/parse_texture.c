/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:05:15 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/11 15:05:37 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	assign_texture(char **field, char *value)
{
	char	*trimmed;

	if (*field != NULL)
		return (0);
	trimmed = ft_strtrim(value, " \n");
	if (!trimmed)
		return (0);
	if (!is_valid_xpm_path(trimmed))
	{
		free(trimmed);
		return (0);
	}
	*field = trimmed;
	return (1);
}

int	parse_texture_line(t_config *cfg, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (assign_texture(&cfg->no_texture, ft_clean_path(line + 3)));
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (assign_texture(&cfg->so_texture, ft_clean_path(line + 3)));
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (assign_texture(&cfg->we_texture, ft_clean_path(line + 3)));
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (assign_texture(&cfg->ea_texture, ft_clean_path(line + 3)));
	return (1);
}
