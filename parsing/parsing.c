/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:15:24 by diana             #+#    #+#             */
/*   Updated: 2025/06/24 16:35:11 by diana            ###   ########.fr       */
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


static int	assign_color(char **field, char *value)
{
	char *trimmed;

	if (*field != NULL)
		return (1);
	trimmed = ft_strtrim(value, " \n");
	printf("Valor trimmeado: [%s]\n", trimmed);
	if (!trimmed)
		return (1);
	if (!validate_rgb_format(trimmed))
	{
		free(trimmed);
		return (1);
	}
	*field = trimmed;
	return (0);
}


int	parse_config_line(t_config *cfg, char *line)
{
	char	*newline_pos;
	char	*value;

	newline_pos = ft_strchr(line, '\n');
	if (newline_pos)
		*newline_pos = '\0';
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		value = line + 3;
		while (*value == ' ')
			value++;
		char *clean_path = ft_clean_path(value);
		if (!clean_path)
			return (1);
		int result = assign_texture(&cfg->no_texture, clean_path);
		free(clean_path);
		return (result);
	}
	if (ft_strncmp(line, "SO ", 3) == 0)
	{
		value = line + 3;
		while (*value == ' ')
			value++;
		char *clean_path = ft_clean_path(value);
		if (!clean_path)
			return (1);
		int result = assign_texture(&cfg->no_texture, clean_path);
		free(clean_path);
		return (result);
	}
	if (ft_strncmp(line, "EA ", 3) == 0)
	{
		value = line + 3;
		while (*value == ' ')
			value++;
		char *clean_path = ft_clean_path(value);
		if (!clean_path)
			return (1);
		int result = assign_texture(&cfg->no_texture, clean_path);
		free(clean_path);
		return (result);
	}
	if (ft_strncmp(line, "WE ", 3) == 0)
	{
		value = line + 3;
		while (*value == ' ')
			value++;
		char *clean_path = ft_clean_path(value);
		if (!clean_path)
			return (1); // Error de malloc
		int result = assign_texture(&cfg->no_texture, clean_path);
		free(clean_path);
		return (result);
	}

	// Colores (no verificamos espacios aquí, pero podrías validar formato RGB después)
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		value = line + 2;
		while (*value == ' ')
			value++;
		return (assign_color(&cfg->floor_color, value));
	}
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		value = line + 2;
		while (*value == ' ')
			value++;
		return (assign_color(&cfg->ceiling_color, value));
	}

	fprintf(stderr, "Línea inválida: [%s]\n", line);
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
		printf("Analizando config_lines[%d]: [%s]\n", i, clean_line);
		printf("Original: [%s]\n", config_lines[i]);
		printf("Limpia  : [%s]\n", clean_line);

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
