/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diramire <diramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:08:02 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/22 10:13:27 by diramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_valid_xpm_path(char *path)
{
	int	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len < 5)
		return (0);
	return (ft_strncmp(path + len - 4, ".xpm", 4) == 0);
}

int	check_rgb_parts(char **parts)
{
	int	i;
	int	value;

	i = 0;
	while (i < 3)
	{
		if (!parts[i])
			return (0);
		value = ft_atoi(parts[i]);
		if (value < 0 || value > 255)
			return (0);
		i++;
	}
	if (parts[i])
		return (0);
	return (1);
}

int	is_valid_rgb(char *str)
{
	char	**parts;
	int		result;

	if (!str)
		return (0);
	parts = ft_split(str, ',');
	if (!parts)
		return (0);
	result = check_rgb_parts(parts);
	free_array(parts);
	return (result);
}

static int	process_color_line(char *clean_line, t_config *cfg)
{
	char	*rgb_string;

	if (clean_line && ft_strncmp(clean_line, "F ", 2) == 0)
	{
		rgb_string = clean_line + 2;
		if (!is_valid_rgb(rgb_string) || assign_color(cfg, "F", rgb_string) \
!= 0)
			return (1);
	}
	else if (clean_line && ft_strncmp(clean_line, "C ", 2) == 0)
	{
		rgb_string = clean_line + 2;
		if (!is_valid_rgb(rgb_string) || assign_color(cfg, "C", rgb_string) \
!= 0)
			return (1);
	}
	return (0);
}

int	extract_colors(char **config_lines, t_config *cfg)
{
	int		i;
	char	*clean_line;

	i = 0;
	while (config_lines[i])
	{
		clean_line = ft_reduce_spaces(config_lines[i]);
		if (process_color_line(clean_line, cfg) != 0)
		{
			if (clean_line)
				free(clean_line);
			return (0);
		}
		if (clean_line)
			free(clean_line);
		i++;
	}
	return (1);
}
