/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 22:24:03 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/21 15:06:11 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"
/*
int	validate_map(t_map *map, t_map_config *config)//porque map? si deberia ser **lines no? estructura
{
	int	player_found = 0;
	int	y = -1;
	int	x;

	while (map->lines[++y])
	{
		x = -1;
		while (map->lines[y][++x])
		{
			char c = map->lines[y][x];
			if (!is_valid_map_char(c))
				return (0);
			if (is_player_char(c))
			{
				if (player_found)
					return (0);
				player_found = 1;
				config->player_x = x;
				config->player_y = y;
				config->player_dir = c;
			}
			if (!check_surroundings(map, x, y))
				return (0);
		}
	}
	return (player_found);
}
*/