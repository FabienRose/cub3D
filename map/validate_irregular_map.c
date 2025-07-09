/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_irregular_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 00:00:00 by diana             #+#    #+#             */
/*   Updated: 2025/01/27 00:00:00 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	get_line_length(char *line)
{
	int	len;

	if (!line)
		return (0);
	len = 0;
	while (line[len])
		len++;
	while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\n'))
		len--;
	return (len);
}

static int	get_first_non_space(char *line)
{
	int	i;

	if (!line)
		return (-1);
	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\n'))
		i++;
	return (i);
}

static int	check_vertical_closure(char **map, int line_count)
{
	int	i;
	int	j;
	int	current_start;
	int	current_end;
	int	prev_start;
	int	prev_end;

	i = 1;
	prev_start = get_first_non_space(map[0]);
	prev_end = get_line_length(map[0]) - 1;
	while (i < line_count)
	{
		current_start = get_first_non_space(map[i]);
		current_end = get_line_length(map[i]) - 1;
		if (current_start > prev_start)
		{
			j = prev_start;
			while (j < current_start)
			{
				if (map[i - 1][j] != '1' && map[i - 1][j] != ' ')
				{
					printf("Error: Gap detected at line %d, column %d\n", i - 1, j);
					return (0);
				}
				j++;
			}
		}
		if (current_end < prev_end)
		{
			j = current_end + 1;
			while (j <= prev_end)
			{
				if (map[i - 1][j] != '1' && map[i - 1][j] != ' ')
				{
					printf("Error: Gap detected at line %d, column %d\n", i - 1, j);
					return (0);
				}
				j++;
			}
		}
		prev_start = current_start;
		prev_end = current_end;
		i++;
	}
	return (1);
}

int	validate_irregular_map_borders(char **map)
{
	int	line_count;
	int	i;

	if (!map || !map[0])
		return (0);
	line_count = 0;
	while (map[line_count])
		line_count++;
	i = 0;
	while (i < line_count)
	{
		if (!has_wall_boundaries(map[i]))
		{
			printf("Error: Line %d is not properly closed\n", i);
			return (0);
		}
		i++;
	}
	if (!check_vertical_closure(map, line_count))
		return (0);
	return (1);
}

static int	is_valid_neighbor(char **map, int x, int y)
{
	if (!map[y] || x < 0 || x >= (int)ft_strlen(map[y]))
		return (0);
	if (map[y][x] == '1' || map[y][x] == '0' || 
		map[y][x] == 'N' || map[y][x] == 'S' || 
		map[y][x] == 'E' || map[y][x] == 'W')
		return (1);
	return (0);
}

int	validate_surrounded_spaces(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || 
				map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (!is_valid_neighbor(map, j - 1, i) ||
					!is_valid_neighbor(map, j + 1, i) ||
					!is_valid_neighbor(map, j, i - 1) ||
					!is_valid_neighbor(map, j, i + 1))
				{
					printf("Error: Space at (%d,%d) is not properly surrounded\n", j, i);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}