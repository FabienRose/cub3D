/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:44:21 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/22 13:44:21 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_init(int x, int y, t_game *game)
{
	game->player.x = x;
	game->player.y = y;
	game->player.angle = 0;
	game->player.key_down = 0;
	game->player.key_up = 0;
	game->player.key_left = 0;
	game->player.key_right = 0;
	game->player.left_rotate = 0;
	game->player.right_rotate = 0;
	draw_square(game->player.x, game->player.y, game, 0x00FF00);
}
