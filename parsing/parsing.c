/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:15:24 by diana             #+#    #+#             */
/*   Updated: 2025/06/27 18:20:25 by diana            ###   ########.fr       */
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
	*field = trimmed;
	return (0);
}

int	parse_config_line(t_config *cfg, char *line)
{
	char	*newline_pos;
	char	*clean_line;

	newline_pos = ft_strchr(line, '\n');
	if (newline_pos)
		*newline_pos = '\0';
	clean_line = ft_reduce_spaces(line);
	while (*clean_line == ' ')
		clean_line++;

	if (ft_strncmp(clean_line, "NO ", 3) == 0)
		return (assign_texture(&cfg->no_texture, ft_clean_path(clean_line + 3)));
	if (ft_strncmp(clean_line, "SO ", 3) == 0)
		return (assign_texture(&cfg->so_texture, ft_clean_path(clean_line + 3)));
	if (ft_strncmp(clean_line, "WE ", 3) == 0)
		return (assign_texture(&cfg->we_texture, ft_clean_path(clean_line + 3)));
	if (ft_strncmp(clean_line, "EA ", 3) == 0)
		return (assign_texture(&cfg->ea_texture, ft_clean_path(clean_line + 3)));

	if (ft_strncmp(clean_line, "F ", 2) == 0)
	{
		if (assign_color(cfg, "F", clean_line + 2))
			return (1);
		printf("DEBUG: Floor color (int) = %d, hex = %#06x\n", cfg->floor_color, cfg->floor_color);
		return (0);
	}
	if (ft_strncmp(clean_line, "C ", 2) == 0)
	{
		if (assign_color(cfg, "C", clean_line + 2))
			return (1);
		printf("DEBUG: Ceiling color (int) = %d, hex = %#06x\n", cfg->ceiling_color, cfg->ceiling_color);
		return (0);
	}
	return (1);
}

t_config	*parse_config(char **config_lines)
{
	t_config	*cfg;
	int			i;
	char		*clean_line;

	i = 0;
	cfg = malloc(sizeof(t_config));
	if (!cfg)
		return (NULL);
	cfg->no_texture = NULL;
	cfg->so_texture = NULL;
	cfg->ea_texture = NULL;
	cfg->we_texture = NULL;
	cfg->floor_color = -1;
	cfg->ceiling_color = -1;
	while (config_lines[i])
	{
		clean_line = ft_reduce_spaces(config_lines[i]);
		if (!clean_line)
			return (free_config(cfg), NULL);
		if (parse_config_line(cfg, clean_line) != 0)
		{
			free(clean_line);
			free_config(cfg);
			return (NULL);
		}
		free(clean_line);
		i++;
	}
	return (cfg);
}
