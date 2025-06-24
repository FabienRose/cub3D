/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:15:24 by diana             #+#    #+#             */
/*   Updated: 2025/06/24 17:40:20 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

static int	assign_texture(char **field, char *value)
{
	char *trimmed;

	if (*field != NULL)
	{
		printf("Ya asignado previamente\n");
		return (1);
	}
	printf("Original value recibido: [%s]\n", value);
	trimmed = ft_strtrim(value, " \n");
	if (!trimmed)
	{
		printf("Fallo en ft_strtrim\n");
		return (1);
	}
	printf("Valor trimmed: [%s]\n", trimmed);
	*field = trimmed;
	return (0);
}

static char	*rebuild_clean_rgb(char **parts)
{
	char	*trimmed[3];
	char	*result;
	char	*tmp;

	trimmed[0] = ft_strtrim(parts[0], " \t\n");
	trimmed[1] = ft_strtrim(parts[1], " \t\n");
	trimmed[2] = ft_strtrim(parts[2], " \t\n");

	if (!trimmed[0] || !trimmed[1] || !trimmed[2])
		return (NULL);

	tmp = ft_strjoin(trimmed[0], ",");
	result = ft_strjoin(tmp, trimmed[1]);
	free(tmp);
	tmp = result;
	result = ft_strjoin(result, ",");
	free(tmp);
	tmp = result;
	result = ft_strjoin(result, trimmed[2]);
	free(tmp);

	free(trimmed[0]);
	free(trimmed[1]);
	free(trimmed[2]);
	return (result);
}

static int	assign_color(char **field, char *value)
{
	char	*trimmed;
	char	**parts;
	char	*cleaned;

	if (*field != NULL)
		return (1);
	trimmed = ft_strtrim(value, " \n\t");
	if (!trimmed)
		return (1);
	if (!validate_rgb_format(trimmed))
	{
		free(trimmed);
		return (1);
	}
	parts = ft_split(trimmed, ',');
	free(trimmed);
	if (!parts)
		return (1);
	cleaned = rebuild_clean_rgb(parts);
	free_array(parts);
	if (!cleaned)
		return (1);
	*field = cleaned;
	return (0);
}


int	parse_config_line(t_config *cfg, char *line)
{
	char	*newline_pos;
	char	*clean_line;

	newline_pos = ft_strchr(line, '\n');
	if (newline_pos)
		*newline_pos = '\0';
	// Reducir espacios entre palabras
	clean_line = ft_reduce_spaces(line);
	// Saltar espacios iniciales
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
		return (assign_color(&cfg->floor_color, clean_line + 2));
	if (ft_strncmp(clean_line, "C ", 2) == 0)
		return (assign_color(&cfg->ceiling_color, clean_line + 2));

	printf("Linea invalida: [%s]\n", clean_line);
	return (1);
}



int	missing_fields(t_config *cfg)
{
	if (!cfg->no_texture) printf("Falta NO\n");
	if (!cfg->so_texture) printf("Falta SO\n");
	if (!cfg->ea_texture) printf("Falta EA\n");
	if (!cfg->we_texture) printf("Falta WE\n");
	if (!cfg->floor_color) printf("Falta Floor\n");
	if (!cfg->ceiling_color) printf("Falta Ceiling\n");

	return (!cfg->no_texture || !cfg->so_texture
		|| !cfg->ea_texture || !cfg->we_texture
		|| !cfg->floor_color || !cfg->ceiling_color);
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
	cfg->floor_color = NULL;
	cfg->ceiling_color = NULL;
	while (config_lines[i])
	{
		clean_line = ft_reduce_spaces(config_lines[i]);
		if (!clean_line)
			return (free_config(cfg), NULL);
		if (parse_config_line(cfg, clean_line) != 0)
		{
			fprintf(stderr, "Error procesando línea de config: [%s]\n", clean_line);
			free(clean_line);
			free_config(cfg);
			return (NULL);
		}
		free(clean_line);
		i++;
	}
	return (cfg);
}

void	free_config(t_config *cfg)
{
	if (!cfg)
		return;
	if (cfg->no_texture)
		free(cfg->no_texture);
	if (cfg->so_texture)
		free(cfg->so_texture);
	if (cfg->we_texture)
		free(cfg->we_texture);
	if (cfg->ea_texture)
		free(cfg->ea_texture);
	if (cfg->floor_color)
		free(cfg->floor_color);
	if (cfg->ceiling_color)
		free(cfg->ceiling_color);
	free(cfg);
}
