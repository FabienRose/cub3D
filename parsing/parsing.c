/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:15:24 by diana             #+#    #+#             */
/*   Updated: 2025/06/25 11:38:47 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

static int	assign_texture(char **field, char *value)
{
	char *trimmed;

	if (*field != NULL)
		return (1);
	trimmed = ft_strtrim(value, " \n");
	if (!trimmed)
		return (1);
	*field = trimmed;
	return (0);
}

/* No necesito por ahora esta funcion....quizas mas adelante?
esta funcion es sutituida por la linea
cleaned = ft_strtrim(value, " \t\n\r\v\f");
static char	*rebuild_clean_rgb(char **parts) 
{
	char	*trimmed[3];
	char	*result;
	char	*tmp;

	trimmed[0] = ft_strtrim(parts[0], " \t\n\r\v\f");
	trimmed[1] = ft_strtrim(parts[1], " \t\n\r\v\f");
	trimmed[2] = ft_strtrim(parts[2], " \t\n\r\v\f");

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
}*/

static int	assign_color(int *field, char *value)
{
	char	*cleaned;
	int		color;

	cleaned = ft_strtrim(value, " \t\n\r\v\f");
	if (!cleaned)
		return (1);
	color = parse_rgb(cleaned); // función que convierte string a entero RGB
	free(cleaned);
	if (color == -1) // usamos -1 como indicador de error
		return (1);
	*field = color;
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
		if (assign_color(&cfg->floor_color, clean_line + 2))
			return (1);
		printf("DEBUG: Floor color (int) = %d, hex = %#06x\n", cfg->floor_color, cfg->floor_color);
		return (0);
	}
	if (ft_strncmp(clean_line, "C ", 2) == 0)
	{
		if (assign_color(&cfg->ceiling_color, clean_line + 2))
			return (1);
		printf("DEBUG: Ceiling color (int) = %d, hex = %#06x\n", cfg->ceiling_color, cfg->ceiling_color);
		return (0);
	}
	return (1);
}

int	missing_fields(t_config *cfg)
{
	if (!cfg->no_texture) printf("Falta NO\n");
	if (!cfg->so_texture) printf("Falta SO\n");
	if (!cfg->ea_texture) printf("Falta EA\n");
	if (!cfg->we_texture) printf("Falta WE\n");
	if (cfg->floor_color == -1) printf("Falta Floor\n");
	if (cfg->ceiling_color == -1) printf("Falta Ceiling\n");

	return (!cfg->no_texture || !cfg->so_texture
		|| !cfg->ea_texture || !cfg->we_texture
		|| cfg->floor_color == -1 || cfg->ceiling_color == -1);
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
	free(cfg);
}
