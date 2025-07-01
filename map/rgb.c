/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:14:11 by diana             #+#    #+#             */
/*   Updated: 2025/06/30 17:09:52 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	process_rgb_component(char *component, int *value)
{
	char	*trimmed_part;

	trimmed_part = ft_strtrim_whitespace(component);
	if (!trimmed_part)
		return (0);
	*value = ft_atoi(trimmed_part);
	free(trimmed_part);
	return (1);
}

static int	validate_rgb_values(int r, int g, int b)
{
	if (r < 0 || r > 255)
		return (0);
	if (g < 0 || g > 255)
		return (0);
	if (b < 0 || b > 255)
		return (0);
	return (1);
}

static int	process_rgb_components(char **parts, int *r, int *g, int *b)
{
	if (!process_rgb_component(parts[0], r) || \
		!process_rgb_component(parts[1], g) || \
		!process_rgb_component(parts[2], b))
	{
		return (0);
	}
	return (1);
}

int	rgb_to_int(char *rgb_str)
{
	char	**parts;
	int		r;
	int		g;
	int		b;

	parts = ft_split(rgb_str, ',');
	if (!parts)
		return (-1);
	if (!process_rgb_components(parts, &r, &g, &b))
	{
		free_array(parts);
		return (-1);
	}
	free_array(parts);
	if (!validate_rgb_values(r, g, b))
		return (-1);
	return ((r << 16) | (g << 8) | b);
}
