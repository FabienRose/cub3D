/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:19:25 by diana             #+#    #+#             */
/*   Updated: 2025/06/27 19:42:50 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

static char	*clean_part(char *part)
{
	char	*clean;

	clean = ft_strtrim(part, " \t\n\r\v\f");
	if (!clean)
		return (NULL);
	return (clean);
}

static char	*rebuild_clean_rgb(char **parts)
{
	char	*tmp;
	char	*result;
	int		i;
	char	*clean;

	if (!parts)
		return (NULL);
	result = NULL;
	i = 0;
	while (parts[i])
	{
		clean = clean_part(parts[i]);
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
	if (!is_valid_rgb(value))
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
