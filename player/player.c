/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:02:08 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/02 18:02:47 by fmixtur          ###   ########.ch       */
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
	draw_square(game->player.x, game->player.y, game,
		WINDOW_WIDTH / 10, 0x00FF00);
}

int	player_find_and_init(char **map, int cell_size, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j])
			{
				player_init(j * cell_size + cell_size / 2,
					i * cell_size + cell_size / 2, map[i][j], game);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_wall_collision(float new_x, float new_y, t_game *game)
{
	int	cell_size;
	int	radius;

	radius = 7;
	cell_size = game->cell_size;
	if (game->map[(int)new_y / cell_size] && game->map[(int)new_y
			/ cell_size][(int)new_x / cell_size] == '1')
		return (1);
	if (game->map[(int)(new_y - radius) / cell_size]
		&& game->map[(int)(new_y - radius) /
			cell_size][(int)new_x / cell_size] == '1')
		return (1);
	if (game->map[(int)(new_y + radius) / cell_size]
		&& game->map[(int)(new_y + radius) /
			cell_size][(int)new_x / cell_size] == '1')
		return (1);
	if (game->map[(int)new_y / cell_size]
		&& game->map[(int)new_y / cell_size][(int)(new_x - radius)
			/ cell_size] == '1')
		return (1);
	if (game->map[(int)new_y / cell_size]
		&& game->map[(int)new_y / cell_size][(int)(new_x + radius)
			/ cell_size] == '1')
		return (1);
	return (0);
}
