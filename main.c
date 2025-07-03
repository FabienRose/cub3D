/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:33:05 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/03 16:23:30 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
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
	
	// Print the configuration data using our new function
	print_config_data(config_data);
	ft_putendl_fd("Configuración válida", 1);

	// Test the new map functions
	t_game_map *game_map = init_game_map(map);
	if (game_map)
	{
		printf("\n--- Map Information ---\n");
		printf("Map dimensions: %d x %d\n", game_map->width, game_map->height);
		printf("Player position: (%.1f, %.1f)\n", game_map->player.x, game_map->player.y);
		printf("Player direction: %c (%.2f radians)\n", game_map->player.dir_char, game_map->player.dir);
		
		// Test get_map_cell function
		int px = (int)game_map->player.x;
		int py = (int)game_map->player.y;
		printf("Map cell at player position: %c\n", get_map_cell(game_map, px, py));
		
		free_game_map(game_map);
	}
	
	free_array(config);
	free_array(map);
	free_array(array);
	free_config_data(config_data);
	return (0);
}
