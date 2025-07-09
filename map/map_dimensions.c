/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:31:23 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/09 15:28:09 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_game_map	*init_game_map(char **map_data)
{
	t_game_map	*game_map;

	if (!map_data)
		return (NULL);
	game_map = (t_game_map *)malloc(sizeof(t_game_map));
	if (!game_map)
		return (NULL);
	game_map->map_data = map_data;
	game_map->width = get_map_width(map_data);
	game_map->height = get_map_height(map_data);
	return (game_map);
}
