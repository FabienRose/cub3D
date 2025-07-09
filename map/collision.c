/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:35:19 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/09 14:42:57 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_wall(t_game_map *game_map, int x, int y)
{
	char	cell;

	cell = get_map_cell(game_map, x, y);
	return (cell == '1');
}

int	is_position_valid(t_game_map *game_map, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0 || map_x >= game_map->width || \
	map_y >= game_map->height)
		return (0);
	return (1);
}

int	can_move_to(t_game_map *game_map, double new_x, double new_y)
{
	if (!is_position_valid(game_map, new_x, new_y))
		return (0);
	if (is_wall(game_map, (int)new_x, (int)new_y))
		return (0);
	return (1);
}
