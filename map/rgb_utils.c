/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:09:18 by diana             #+#    #+#             */
/*   Updated: 2025/06/30 17:10:54 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	are_parts_valid(char **parts)
{
	int		i;
	char	*trimmed_part;

	i = 0;
	while (i < 3)
	{
		if (!parts[i])
			return (0);
		trimmed_part = ft_strtrim_whitespace(parts[i]);
		if (!trimmed_part || !is_valid_component(trimmed_part))
		{
			free(trimmed_part);
			return (0);
		}
		free(trimmed_part);
		i++;
	}
	return (1);
}

static int	has_correct_number_of_components(char **parts)
{
	return (parts[3] == NULL);
}

int	validate_rgb_format(char *line)
{
	char	**parts;
	int		valid;

	parts = ft_split(line, ',');
	if (!parts)
		return (0);
	valid = are_parts_valid(parts);
	if (valid)
		valid = has_correct_number_of_components(parts);
	free_array(parts);
	return (valid);
}
