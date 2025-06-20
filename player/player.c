/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:35:46 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/20 16:37:08 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_init(int x, int y, t_game *game)
{
	game->player.x = x;
	game->player.y = y;
	game->player.key_down = 0;
	game->player.key_up = 0;
	game->player.key_left = 0;
	game->player.key_right = 0;
	draw_square(x, y, game, 0x00FF00);
}
