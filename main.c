/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:00:10 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/19 11:00:16 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define _USE_MATH_DEFINES

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
		return (1);
	}
	if (!load_textures(&game))
	{
		ft_putendl_fd("Error\nFailed to load textures", 2);
		cleanup_game(&game);
		free_parsing_data(&parsing);
		return (1);
	}
	player_find_and_init(game.map, &game);
	hooks_setup(game.win, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	free_parsing_data(&parsing);
	return (0);
}
