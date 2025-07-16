/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:38:51 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/16 22:44:32 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static void	player_init(int x, int y, char angle, t_game *game)
{
	if (angle == 'S')
		game->player.angle = PI / 2;
	else if (angle == 'W')
		game->player.angle = PI;
	else if (angle == 'N')
		game->player.angle = 3 * PI / 2;
	else
		game->player.angle = 0;
	game->player.x = x;
	game->player.y = y;
	game->player.key_down = 0;
	game->player.key_up = 0;
	game->player.key_left = 0;
	game->player.key_right = 0;
	game->player.left_rotate = 0;
	game->player.right_rotate = 0;
}

int	player_find_and_init(char **map, t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'E' || map[i][j] == 'W')
			{
				player_init(j * game->cell_size + game->cell_size / 2,
					i * game->cell_size + game->cell_size / 2, map[i][j], game);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	init_collision_offsets(int *dx, int *dy, int r)
{
	dx[0] = 0;
	dx[1] = -r;
	dx[2] = r;
	dx[3] = 0;
	dx[4] = 0;
	dx[5] = -r;
	dx[6] = r;
	dx[7] = -r;
	dx[8] = r;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = 0;
	dy[3] = -r;
	dy[4] = r;
	dy[5] = -r;
	dy[6] = -r;
	dy[7] = r;
	dy[8] = r;
}

int	is_wall_collision(float new_x, float new_y, t_game *game)
{
	int	dx[9];
	int	dy[9];
	int	i;
	int	map_x;
	int	map_y;

	init_collision_offsets(dx, dy, game->minimap_cell_size);
	i = 0;
	while (i < 9)
	{
		map_x = (int)(new_x + dx[i]) / game->cell_size;
		map_y = (int)(new_y + dy[i]) / game->cell_size;
		if (map_x >= 0 && map_y >= 0
			&& game->map[map_y] && map_x < (int)ft_strlen(game->map[map_y])
			&& game->map[map_y][map_x] == '1')
			return (1);
		i++;
	}
	return (0);
}
