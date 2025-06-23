/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:15:24 by diana             #+#    #+#             */
/*   Updated: 2025/06/23 14:29:09 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

static int	assign_texture(char **field, char *value)
{
	if (*field != NULL)
		return (1);
	*field = ft_strdup(value);
	if (!*field)
		return (1);
	return (0);
}
//check and save one configuration line
int	parse_config_line(t_config *cfg, char *line)
{
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (assign_texture(&cfg->no_texture, line + 3));
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (assign_texture(&cfg->so_texture, line + 3));
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (assign_texture(&cfg->ea_texture, line + 3));
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (assign_texture(&cfg->we_texture, line + 3));
	if (ft_strncmp(line, "F ", 2) == 0)
		return (assign_texture(&cfg->floor_color, line + 2));
	if (ft_strncmp(line, "C ", 2) == 0)
		return (assign_texture(&cfg->ceiling_color, line + 2));
	return (1);
}

int	missing_fields(t_config *cfg)
{
	if (!cfg->no_texture || !cfg->so_texture
		|| !cfg->ea_texture || !cfg->we_texture
		|| !cfg->floor_color || !cfg->ceiling_color)
		return (1);
	return (0);
}
//pass all the file.cub lines before the map 
t_config	*parse_config(char **lines)
{
	t_config	*cfg;
	int			i;
	int			err;

	cfg = malloc(sizeof(t_config));
	if (!cfg)
		return (NULL);
	ft_memset(cfg, 0, sizeof(t_config));
	i = 0;
	err = 0;
	while (lines[i] && err == 0)
	{
		err = parse_config_line(cfg, lines[i]);
		i++;
	}
	if (err || missing_fields(cfg))
		return (free(cfg), NULL);
	return (cfg);
}


/*version ultima antes de cortarla
t_config *parse_config(char **config_lines)
{
    t_config *config = malloc(sizeof(t_config));
    if (!config)
        return NULL;
    ft_memset(config, 0, sizeof(t_config));

    for (int i = 0; config_lines[i]; i++)
    {
        char *line = config_lines[i];
        while (*line == ' ')
            line++;

        if (ft_strncmp(line, "NO ", 3) == 0)
        {
            if (config->no_texture)
                return (printf("Error: Duplicado NO\n"), free(config), NULL);
            config->no_texture = strdup(line + 3);
        }
        else if (ft_strncmp(line, "SO ", 3) == 0)
        {
            if (config->so_texture)
                return (printf("Error: Duplicado SO\n"), free(config), NULL);
            config->so_texture = ft_strdup(line + 3);
        }
        else if (ft_strncmp(line, "EA ", 3) == 0)
        {
            if (config->ea_texture)
                return (printf("Error: Duplicado EA\n"), free(config), NULL);
            config->ea_texture = ft_strdup(line + 3);
        }
        else if (ft_strncmp(line, "WE ", 3) == 0)
        {
            if (config->we_texture)
                return (printf("Error: Duplicado WE\n"), free(config), NULL);
            config->we_texture = ft_strdup(line + 3);
        }
        else if (ft_strncmp(line, "F ", 2) == 0)
        {
            if (config->floor_color)
                return (printf("Error: Duplicado F\n"), free(config), NULL);
            config->floor_color = ft_strdup(line + 2);
        }
        else if (ft_strncmp(line, "C ", 2) == 0)
        {
            if (config->ceiling_color)
                return (printf("Error: Duplicado C\n"), free(config), NULL);
            config->ceiling_color = ft_strdup(line + 2);
        }
        else
        {
            printf("Error: Línea de configuración inválida: %s\n", line);
            free(config);
            return NULL;
        }
    }

    // Validar que todas las claves estén presentes
    if (!config->no_texture || !config->so_texture || !config->ea_texture || !config->we_texture ||
        !config->floor_color || !config->ceiling_color)
    {
        printf("Error: Falta una o más configuraciones obligatorias.\n");
        free(config);
        return NULL;
    }

    return config;
}
*/


/*
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
}*/

