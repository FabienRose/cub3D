/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:00:00 by diana             #+#    #+#             */
/*   Updated: 2025/07/03 17:16:13 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_player_direction(t_player *player, char dir_char)
{
	player->dir_char = dir_char;
	if (dir_char == 'N')
		player->dir = M_PI / 2;
	else if (dir_char == 'S')
		player->dir = 3 * M_PI / 2;
	else if (dir_char == 'E')
		player->dir = 0;
	else if (dir_char == 'W')
		player->dir = M_PI;
}

static t_player	find_player_position(char **map)
{
	t_player	player;
	int			y;
	int			x;

	ft_memset(&player, 0, sizeof(t_player));
	y = 0;
	while (map && map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSEW", map[y][x]))
			{
				player.x = x + 0.5;
				player.y = y + 0.5;
				set_player_direction(&player, map[y][x]);
				return (player);
			}
			x++;
		}
		y++;
	}
	return (player);
}

t_player	get_player_info(char **map)
{
	return (find_player_position(map));
}

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
	game_map->player = get_player_info(map_data);
	return (game_map);
}
