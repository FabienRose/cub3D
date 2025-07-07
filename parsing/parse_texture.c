/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:51:41 by diana             #+#    #+#             */
/*   Updated: 2025/07/01 13:52:01 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	assign_texture(char **field, char *value)
{
	char	*trimmed;

	if (*field != NULL)
		return (1);
	trimmed = ft_strtrim(value, " \n");
	if (!trimmed)
		return (1);
	if (!is_valid_xpm_path(trimmed))
	{
		free(trimmed);
		return (1);
	}
	*field = trimmed;
	return (0);
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
