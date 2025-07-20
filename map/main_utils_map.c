/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 01:02:50 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/21 01:02:50 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**extract_and_validate_initial_map(char **array, int start_index)
{
	char	**map;

	map = extract_map(array, start_index);
	if (!map)
		return (NULL);
	if (!validate_map(map))
	{
		free_array(map);
		return (NULL);
	}
	return (map);
}

char	**trim_and_validate_map_lines(char **map)
{
	trim_newline_from_map(map);
	if (validate_map_lines(map) != 0)
	{
		ft_putendl_fd("Error\nMap not valid", 2);
		free_array(map);
		return (NULL);
	}
	return (map);
}

char	**make_and_validate_rectangular_map(char **map)
{
	char	**rectangular_map;

	rectangular_map = make_map_rectangular(map);
	if (!rectangular_map)
	{
		ft_putendl_fd("Error\nFailed to make map rectangular", 2);
		return (NULL);
	}
	if (!validate_rectangular_map(rectangular_map))
	{
		ft_putendl_fd("Error\nMap not rectangular", 2);
		free_array(rectangular_map);
		return (NULL);
	}
	return (rectangular_map);
}

char	**extract_and_validate_map(char **array, int start_index)
{
	char	**map;
	char	**rectangular_map;

	map = extract_and_validate_initial_map(array, start_index);
	if (!map)
		return (NULL);
	map = trim_and_validate_map_lines(map);
	if (!map)
		return (NULL);
	rectangular_map = make_and_validate_rectangular_map(map);
	return (rectangular_map);
}
