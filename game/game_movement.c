/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:08:38 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/15 08:02:33 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	game_move_up(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player.x + cosf(game->player.angle) * game->move_speed;
	new_y = game->player.y + sinf(game->player.angle) * game->move_speed;
	if (!is_wall_collision(new_x, new_y, game))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	game_move_down(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player.x - cosf(game->player.angle) * game->move_speed;
	new_y = game->player.y - sinf(game->player.angle) * game->move_speed;
	if (!is_wall_collision(new_x, new_y, game))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	game_move_left(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player.x + cosf(game->player.angle - PI / 2)
		* game->move_speed;
	new_y = game->player.y + sinf(game->player.angle - PI / 2)
		* game->move_speed;
	if (!is_wall_collision(new_x, new_y, game))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	game_move_right(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player.x + cosf(game->player.angle + PI / 2)
		* game->move_speed;
	new_y = game->player.y + sinf(game->player.angle + PI / 2)
		* game->move_speed;
	if (!is_wall_collision(new_x, new_y, game))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	game_movement(t_game *game)
{
	if (game->player.key_up)
		game_move_up(game);
	if (game->player.key_down)
		game_move_down(game);
	if (game->player.key_left)
		game_move_left(game);
	if (game->player.key_right)
		game_move_right(game);
	if (game->player.left_rotate)
		game->player.angle -= game->rot_speed;
	if (game->player.right_rotate)
		game->player.angle += game->rot_speed;
}
