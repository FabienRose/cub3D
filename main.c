/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:29:45 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/09 17:21:55 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _USE_MATH_DEFINES
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_parsing_data	parsing;
	t_game			game;

	check_args(argc, argv);
	parsing.file_array = load_file_to_array(argv[1]);
	parsing.map_start_index = get_map_start_index(parsing.file_array);
	parsing.map = extract_and_validate_map(parsing.file_array, parsing.map_start_index);
	parsing.config_lines = get_config_lines(parsing.file_array, parsing.map, parsing.map_start_index);
	if (!parse_config_data(parsing.config_lines, parsing.map, parsing.file_array, &parsing.config))
	{
		ft_putendl_fd("Error\nInvalid configuration", 2);
		free_array(parsing.config_lines);
		free_array(parsing.map);
		free_array(parsing.file_array);
		return (1);
	}
	game.map = parsing.map;
	game_init(&game);
	player_find_and_init(game.map, game.cell_size, &game);
	hooks_setup(game.win, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	free_array(parsing.config_lines);
	free_array(parsing.map);
	free_array(parsing.file_array);
	free_config_data(&parsing.config);
	return (0);
}
