/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:33:05 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/28 21:33:20 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#define _USE_MATH_DEFINES
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		cell_size;

	(void)argc;
	(void)argv;
	cell_size = WINDOW_WIDTH / 32;
	game_init(&game);
	player_find_and_init(game.map, cell_size, &game);
	hooks_setup(game.win, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
