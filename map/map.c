/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:47:35 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/09 10:47:40 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	is_map_line(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || \
			line[i] == 'N' || line[i] == 'S' || \
			line[i] == 'E' || line[i] == 'W' || \
			line[i] == ' ' || line[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int	starts_with_map_char(const char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (*line == '1' || *line == '0');
}

int	find_map_start(char **array)
{
	int	i;
	int	map_started;

	i = 0;
	map_started = 0;
	while (array[i])
	{
		if (!map_started && starts_with_map_char(array[i]))
		{
			map_started = 1;
			return (i);
		}
		if (map_started && array[i][0] == '\0')
		{
			printf("Error: Empty line in the map.\n");
			return (-1);
		}
		i++;
	}
	printf("Error: The map was not found.\n");
	return (-1);
}

int	validate_map_lines(char **map)
{
	int	i;

	if (!map)
		return (1);
	i = 0;
	while (map[i])
	{
		if (!is_map_line(map[i]))
		{
			printf("Error: The map contains invalid characters.\n");
			return (1);
		}
		i++;
	}
	return (0);
}
