/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:15:24 by diana             #+#    #+#             */
/*   Updated: 2025/06/20 17:41:20 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

//interprete each line of the .cub file and extract colors and textures
int	parse_config_line(char *line, t_map_config *config)
{
	char	**tokens;

	if(!line || !*line)
		return (0);
	
	tokens = ft_split(line, ' ');
	if (!tokens || !tokens[0])
		return(0);
	
	if (ft_strncmp(tokens[0], "NO", 3) == 0)
		config->north_texture = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "SO", 3) == 0)
		config->south_texture = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "WE", 3) == 0)
		config->west_texture = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "EA", 3) == 0)
		config->east_texture = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "F", 2) == 0)
		parse_color(tokens[1], &(config->floor_color));
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		parse_color(tokens[1], &(config->ceiling_color));
	else
	{
		free_split(tokens);
		return (0);
	}

	free_split(tokens);
	return (1);
}

int	parse_map(int fd, char *first_line, t_map_config *config)
{
	char	**lines = NULL;
	char	*line;
	int		i = 0;

	lines = malloc(sizeof(char *) * 1024);
	if (!lines)
		return (0);
	lines[i++] = ft_strdup(first_line);
	free(first_line);
	while((line = *ft_gnl(fd)))
	{
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			break;
		}
		lines[i++] = ft_strdup(line);
		free(line);
	}
	lines[i] = NULL;

	config->map = lines;
	config->map_heigth = i;
	if( i > 0)
		config->map_width = ft_strlen(lines[0]);
	
	return(1);
}
