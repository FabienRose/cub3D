/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_irregular_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diramire <diramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 00:00:00 by diana             #+#    #+#             */
/*   Updated: 2025/07/22 11:38:32 by diramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_gap_range(char **map, int line, int start, int end)
{
	int	j;

	j = start;
	while (j < end)
	{
		if (map[line][j] != '1' && map[line][j] != ' ')
		{
			printf("Error: Gap detected at line %d, column %d\n", line, j);
			return (0);
		}
		j++;
	}
	return (1);
}

static int	check_vertical_closure(char **map, int line_count)
{
	int	i;
	int	current_start;
	int	current_end;
	int	prev_start;
	int	prev_end;

	i = 1;
	prev_start = get_first_non_space_pos(map[0]);
	prev_end = get_line_length_trimmed(map[0]) - 1;
	while (i < line_count)
	{
		current_start = get_first_non_space_pos(map[i]);
		current_end = get_line_length_trimmed(map[i]) - 1;
		if (current_start > prev_start)
			if (!check_gap_range(map, i - 1, prev_start, current_start))
				return (0);
		if (current_end < prev_end)
			if (!check_gap_range(map, i - 1, current_end + 1, prev_end + 1))
				return (0);
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

int	validate_position(char **map, int i, int j)
{
	if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' || \
map[i][j] == 'E' || map[i][j] == 'W')
	{
		if (!is_valid_map_neighbor(map, j - 1, i) || \
!is_valid_map_neighbor(map, j + 1, i) || \
!is_valid_map_neighbor(map, j, i - 1) || \
!is_valid_map_neighbor(map, j, i + 1))
		{
			printf("Error: Space at (%d,%d) not surrounded\n", j, i);
			return (0);
		}
	}
	return (1);
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
			if (!validate_position(map, i, j))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
