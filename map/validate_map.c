/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diramire <diramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:38:28 by diana             #+#    #+#             */
/*   Updated: 2025/07/22 11:38:58 by diramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_players(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
map[i][j] == 'E' || map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_top_and_bottom_closed(char **map, int line_count)
{
	int	top_closed;
	int	bottom_closed;

	top_closed = is_line_closed(map[0]);
	bottom_closed = is_line_closed(map[line_count - 1]);
	if (!top_closed || !bottom_closed)
	{
		printf("Error: The map is not closed at the top or bottom.\n");
		return (0);
	}
	return (1);
}

int	check_side_boundaries(char **map, int line_count)
{
	int	j;

	j = 0;
	while (j < line_count)
	{
		if (!has_wall_boundaries(map[j]))
		{
			printf("Error: the map is not closed on the sides\n");
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_player_count(char **map)
{
	int	player_count;

	player_count = count_players(map);
	if (player_count != 1)
	{
		printf("Error: There must be exactly one player (N, S, E o W)\n");
		return (0);
	}
	return (1);
}

int	validate_map(char **map)
{
	int	line_count;

	if (!map || !map[0])
	{
		printf("Error: the map is empty\n");
		return (0);
	}
	if (!check_empty_lines(map))
		return (0);
	line_count = 0;
	while (map[line_count])
		line_count++;
	if (!check_top_and_bottom_closed(map, line_count))
		return (0);
	if (!validate_irregular_map_borders(map))
		return (0);
	if (!validate_surrounded_spaces(map))
		return (0);
	if (!check_player_count(map))
		return (0);
	return (1);
}
