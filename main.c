/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:29:45 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/08 00:29:45 by fmixtur          ###   ########.ch       */
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
	
	// // Print the configuration data using our new function
	// print_config_data(config_data);
	// ft_putendl_fd("Configuración válida", 1);

	// // Test the new map functions
	// t_game_map *game_map = init_game_map(map);
	// if (game_map)
	// {
	// 	printf("\n--- Map Information ---\n");
	// 	printf("Map dimensions: %d x %d\n", game_map->width, game_map->height);
	// 	printf("Player position: (%.1f, %.1f)\n", game_map->player.x, game_map->player.y);
	// 	printf("Player direction: %c (%.2f radians)\n", game_map->player.dir_char, game_map->player.dir);
		
	// 	// Test get_map_cell function
	// 	int px = (int)game_map->player.x;
	// 	int py = (int)game_map->player.y;
	// 	printf("Map cell at player position: %c\n", get_map_cell(game_map, px, py));
		
	// 	// Test collision functions
	// 	printf("\n--- Collision Tests ---\n");
	// 	printf("Current position valid: %s\n", can_move_to(game_map, game_map->player.x, game_map->player.y) ? "YES" : "NO");
	// 	printf("Can move forward 0.5: %s\n", can_move_to(game_map, game_map->player.x + 0.5, game_map->player.y) ? "YES" : "NO");
	// 	printf("Can move to wall (1,1): %s\n", can_move_to(game_map, 1.0, 1.0) ? "YES" : "NO");
		
		// free_game_map(game.map);
	// }
	
	free_array(config);
	free_array(map);
	free_array(array);
	free_config_data(config_data);
	return (0);
}
