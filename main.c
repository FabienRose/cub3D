/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 01:04:23 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/21 01:04:23 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define _USE_MATH_DEFINES

void	game_launch(t_game *game)
{
	player_find_and_init(game->map, game);
	hooks_setup(game->win, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_parsing_data	parsing;
	t_game			game;

	if (!check_args(argc, argv))
		return (1);
	if (!initialize_parsing_data(&parsing, argv[1]))
	{
		free_parsing_data(&parsing);
		return (1);
	}
	if (!game_init(&game, &parsing))
	{
		free_parsing_data(&parsing);
		cleanup_game(&game);
		return (1);
	}
	game_launch(&game);
	cleanup_game(&game);
	free_parsing_data(&parsing);
	return (0);
}
