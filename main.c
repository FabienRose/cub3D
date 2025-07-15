/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:24:32 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/11 15:24:37 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define _USE_MATH_DEFINES

int	main(int argc, char **argv)
{
	t_parsing_data	parsing;
	t_game			game;

	check_args(argc, argv);
	parsing.file_array = load_file_to_array(argv[1]);
	parsing.map_start_index = get_map_start_index(parsing.file_array);
	parsing.config_lines = get_config_lines(parsing.file_array, NULL, \
	parsing.map_start_index);
	if (!initialize_config_data(&parsing.config))
	{
		ft_putendl_fd("Error\nConfig initialization failed", 2);
		free_array(parsing.config_lines);
		free_array(parsing.file_array);
		return (1);
	}
	if (!extract_north_texture(parsing.config_lines, &parsing.config))
	{
		ft_putendl_fd("Error\nInvalid north texture", 2);
		free_array(parsing.config_lines);
		free_array(parsing.file_array);
		free_config_data(&parsing.config);
		return (1);
	}
	if (!extract_south_texture(parsing.config_lines, &parsing.config))
	{
		ft_putendl_fd("Error\nInvalid south texture", 2);
		free_array(parsing.config_lines);
		free_array(parsing.file_array);
		free_config_data(&parsing.config);
		return (1);
	}
	if (!extract_west_texture(parsing.config_lines, &parsing.config))
	{
		ft_putendl_fd("Error\nInvalid west texture", 2);
		free_array(parsing.config_lines);
		free_array(parsing.file_array);
		free_config_data(&parsing.config);
		return (1);
	}
	if (!extract_east_texture(parsing.config_lines, &parsing.config))
	{
		ft_putendl_fd("Error\nInvalid east texture", 2);
		free_array(parsing.config_lines);
		free_array(parsing.file_array);
		free_config_data(&parsing.config);
		return (1);
	}
	if (!extract_colors(parsing.config_lines, &parsing.config))
	{
		ft_putendl_fd("Error\nInvalid colors", 2);
		free_array(parsing.config_lines);
		free_array(parsing.file_array);
		free_config_data(&parsing.config);
		return (1);
	}
	parsing.map = extract_and_validate_map(parsing.file_array, \
	parsing.map_start_index);
	if (!parsing.map)
	{
		ft_putendl_fd("Error\nInvalid map", 2);
		free_array(parsing.config_lines);
		free_array(parsing.file_array);
		free_config_data(&parsing.config);
		return (1);
	}
	game.map = parsing.map;
	game.config = parsing.config;
	game_init(&game);
	player_find_and_init(game.map, &game);
	hooks_setup(game.win, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	free_array(parsing.config_lines);
	free_array(parsing.map);
	free_array(parsing.file_array);
	free_config_data(&parsing.config);
	return (0);
}
