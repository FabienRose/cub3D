/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:29:45 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/09 16:53:07 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _USE_MATH_DEFINES
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	char		**array;
	char		**map;
	char		**config;
	int			start_index;
	t_config	*config_data;

	check_args(argc, argv);
	array = load_file_to_array(argv[1]);
	start_index = get_map_start_index(array);
	map = extract_and_validate_map(array, start_index);
	config = get_config_lines(array, map, start_index);
	config_data = parse_config_data(config, map, array);
	if (!config_data)
	{
		ft_putendl_fd("Error\nConfiguración inválida", 2);
		free_array(config);
		free_array(map);
		free_array(array);
		return (1);
	}
	game.map = map;
	game_init(&game);
	player_find_and_init(game.map, game.cell_size, &game);
	hooks_setup(game.win, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	free_array(config);
	free_array(map);
	free_array(array);
	free_config_data(config_data);
	return (0);
}
