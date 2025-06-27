/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:15:24 by diana             #+#    #+#             */
/*   Updated: 2025/06/27 15:13:15 by diana            ###   ########.fr       */
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
//put together the F & C configuration lines 
char *ft_strjoin_three(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin(s1, s2);
	if (!tmp)
		return (NULL);
	result = ft_strjoin(tmp, s3);
	free(tmp);
	return (result);
}

//if is neccesary we can convert this function to char later
static char	*rebuild_clean_rgb(char **parts)
{
	char	*tmp;
	char	*clean;
	char	*result;
	int		i;

	if (!parts)
		return (NULL);
	result = NULL;
	i = 0;
	while (parts[i])
	{
		clean = ft_strtrim(parts[i], " \t\n\r\v\f");
		if (!clean)
			return (free(result), NULL);
		tmp = result;
		if (i == 0)
			result = ft_strdup(clean);
		else
			result = ft_strjoin_three(tmp, ",", clean);
		free(tmp);
		free(clean);
		if (!result)
			return (NULL);
		i++;
	}
	return (result);
}

int	assign_color(t_config *cfg, char *key, char *value)
{
	char	**parts;
	char	*cleaned;
	int		color;

	if (!cfg || !key || !value)
		return (1);
	parts = ft_split(value, ',');
	if (!parts)
		return (1);
	cleaned = rebuild_clean_rgb(parts);
	free_split(parts);
	if (!cleaned)
		return (1);
	color = parse_rgb(cleaned);
	free(cleaned);
	if (color == -1)
		return (1);
	if (ft_strncmp(key, "F", 2) == 0)
		cfg->floor_color = color;
	else if (ft_strncmp(key, "C", 2) == 0)
		cfg->ceiling_color = color;
	else
		return (1);
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

int	parse_map(t_node *head)
{
	t_node	*current = head;
	t_flags	flags = {0};

	while (current && !all_flags_set(&flags))
	{
		if (is_line_empty_or_spaces_only(current->line))
		{
			current = current->next;
			continue;
		}
		if (!check_and_set_flag(current->line, &flags))
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("Clave no reconocida", 2);
			return (0);
		}
		current = current->next;
	}
	if (!all_flags_set(&flags))
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Faltan claves obligatorias", 2);
		return (0);
	}
	return (1);
}

void	free_list(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head->next;
		if (head->line)
			free(head->line);
		free(head);
		head = tmp;
	}
}