/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:51:14 by diana             #+#    #+#             */
/*   Updated: 2025/07/09 14:58:12 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**extract_and_validate_initial_map(char **array, int start_index)
{
	char	**map;

	map = extract_map(array, start_index);
	if (!map || !validate_map(map))
	{
		free_map(map);
		free_array(array);
		exit(EXIT_FAILURE);
	}
	return (map);
}

char	**trim_and_validate_map_lines(char **map, char **array)
{
	trim_newline_from_map(map);
	if (validate_map_lines(map) != 0)
	{
		ft_putendl_fd("Error\nMap not valid", 2);
		free_array(map);
		free_array(array);
		exit(EXIT_FAILURE);
	}
	return (map);
}

char	**make_and_validate_rectangular_map(char **map, char **array)
{
	char	**rectangular_map;

	rectangular_map = make_map_rectangular(map);
	if (!rectangular_map)
	{
		ft_putendl_fd("Error\nFailed to make map rectangular", 2);
		free_array(map);
		free_array(array);
		exit(EXIT_FAILURE);
	}
	if (!validate_rectangular_map(rectangular_map))
	{
		ft_putendl_fd("Error\nMap is not rectangular", 2);
		free_array(rectangular_map);
		free_array(map);
		free_array(array);
		exit(EXIT_FAILURE);
	}
	free_array(map);
	return (rectangular_map);
}

char	**extract_and_validate_map(char **array, int start_index)
{
	char	**map;
	char	**rectangular_map;

	map = extract_and_validate_initial_map(array, start_index);
	map = trim_and_validate_map_lines(map, array);
	rectangular_map = make_and_validate_rectangular_map(map, array);
	return (rectangular_map);
}
