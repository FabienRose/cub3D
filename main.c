/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:33:05 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/02 22:05:34 by diana            ###   ########.fr       */
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
	
	free_array(config);
	free_array(map);
	free_array(array);
	free_config_data(config_data);
	return (0);
}