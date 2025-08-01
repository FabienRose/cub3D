/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:28:01 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/17 11:28:01 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*clean_part(char *part)
{
	char	*clean;

	clean = ft_strtrim(part, " \t\n\r\v\f");
	if (!clean)
		return (NULL);
	return (clean);
}

static char	*process_and_concat_part(char *result, char *part, int i)
{
	char	*clean;
	char	*tmp;
	char	*tmp2;
	char	*new_result;

	clean = clean_part(part);
	if (!clean)
	{
		free(result);
		return (NULL);
	}
	if (i == 0)
		new_result = ft_strdup(clean);
	else
	{
		tmp = result;
		tmp2 = ft_strjoin(tmp, ",");
		new_result = ft_strjoin(tmp2, clean);
		free(tmp);
		free(tmp2);
	}
	free(clean);
	return (new_result);
}

static char	*rebuild_clean_rgb(char **parts)
{
	char	*result;
	int		i;

	if (!parts)
		return (NULL);
	result = NULL;
	i = 0;
	while (parts[i])
	{
		result = process_and_concat_part(result, parts[i], i);
		if (!result)
			return (NULL);
		i++;
	}
	return (result);
}

static int	process_rgb_color(char *value, int *color)
{
	char	**parts;
	char	*cleaned;

	parts = ft_split(value, ',');
	if (!parts)
		return (1);
	cleaned = rebuild_clean_rgb(parts);
	free_split(parts);
	if (!cleaned)
		return (1);
	*color = parse_rgb(cleaned);
	free(cleaned);
	if (*color == -1)
		return (1);
	return (0);
}

int	assign_color(t_config *cfg, char *key, char *value)
{
	int	color;

	if (!cfg || !key || !value)
		return (1);
	if (!is_valid_rgb(value))
		return (1);
	if (process_rgb_color(value, &color))
		return (1);
	if (ft_strncmp(key, "F", 2) == 0)
		cfg->floor_color = color;
	else if (ft_strncmp(key, "C", 2) == 0)
		cfg->ceiling_color = color;
	else
		return (1);
	return (0);
}
