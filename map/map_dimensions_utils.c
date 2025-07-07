/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:30:20 by diana             #+#    #+#             */
/*   Updated: 2025/07/03 17:23:18 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	if (!map)
		return (0);
	while (map[height])
		height++;
	return (height);
}

int	get_map_width(char **map)
{
	int	width;
	int	max_width;
	int	i;

	if (!map || !map[0])
		return (0);
	max_width = 0;
	i = 0;
	while (map[i])
	{
		width = ft_strlen(map[i]);
		if (width > max_width)
			max_width = width;
		i++;
	}
	return (max_width);
}

char	get_map_cell(t_game_map *game_map, int x, int y)
{
	if (!game_map || !game_map->map_data || x < 0 || y < 0 || \
		x >= game_map->width || y >= game_map->height)
		return ('\0');
	return (game_map->map_data[y][x]);
}

void	free_game_map(t_game_map *game_map)
{
	if (!game_map)
		return ;// Note:don't free map_data here
	free(game_map);
}
