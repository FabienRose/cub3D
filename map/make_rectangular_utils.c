/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rectangular_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:08:45 by diana             #+#    #+#             */
/*   Updated: 2025/07/09 15:23:54 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**make_map_rectangular(char **map)
{
	int		max_width;
	int		map_size;
	char	**new_map;

	if (!map)
		return (NULL);
	max_width = calculate_max_width(map);
	map_size = 0;
	while (map[map_size])
		map_size++;
	new_map = allocate_memory_for_new_map(map_size);
	if (!new_map)
		return (NULL);
	new_map = fill_new_map_with_padding(map, new_map, max_width);
	return (new_map);
}
