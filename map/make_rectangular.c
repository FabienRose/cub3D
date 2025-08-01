/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rectangular.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:21:12 by diana            #+#    #+#             */
/*   Updated: 2025/01/27 00:00:00 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	find_max_width(char **map)
{
	int	i;
	int	max_width;
	int	current_width;

	i = 0;
	max_width = 0;
	while (map[i])
	{
		current_width = ft_strlen(map[i]);
		if (map[i][current_width - 1] == '\n')
			current_width--;
		if (current_width > max_width)
			max_width = current_width;
		i++;
	}
	return (max_width);
}

static char	*pad_line_with_spaces(char *line, int target_width)
{
	char	*new_line;
	int		current_len;
	int		i;

	current_len = ft_strlen(line);
	if (line[current_len - 1] == '\n')
		current_len--;
	new_line = malloc(target_width + 1);
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < current_len && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	while (i < target_width)
	{
		new_line[i] = ' ';
		i++;
	}
	new_line[target_width] = '\0';
	return (new_line);
}

int	calculate_max_width(char **map)
{
	int	max_width;

	max_width = find_max_width(map);
	return (max_width);
}

char	**allocate_memory_for_new_map(int map_size)
{
	char	**new_map;

	new_map = malloc(sizeof(char *) * (map_size + 1));
	if (!new_map)
		return (NULL);
	return (new_map);
}

char	**fill_new_map_with_padding(char **map, char **new_map, int max_width)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		new_map[i] = pad_line_with_spaces(map[i], max_width);
		if (!new_map[i])
		{
			j = 0;
			while (j < i)
			{
				free(new_map[j]);
				j++;
			}
			free(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
