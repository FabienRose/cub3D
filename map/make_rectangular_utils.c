/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:52:37 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/21 00:52:37 by fmixtur          ###   ########.ch       */
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
	free_array(map);
	return (new_map);
}
