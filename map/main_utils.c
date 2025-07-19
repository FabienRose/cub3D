/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:34:38 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/16 15:37:40 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("Use: ./cub3d file.cub", 2);
		return (0);
	}
	if (!ends_with_cub(argv[1]))
	{
		ft_putendl_fd("Error\nThe file should end with .cub", 2);
		return (0);
	}
	return (1);
}

char	**load_file_to_array(char *filename)
{
	t_node	*lines;
	char	**array;

	lines = read_file_to_list(filename);
	if (!lines)
		return (NULL);
	if (!validate_unique_keys(lines))
	{
		ft_putendl_fd("Error\nInvalid or duplicate keys in the file .cub", 2);
		free_list(lines);
		return (NULL);
	}
	array = linked_list_to_array(lines);
	free_list(lines);
	if (!array)
		return (NULL);
	return (array);
}

int	get_map_start_index(char **array)
{
	int	index;

	if (!parse_map(array))
	{
		ft_putendl_fd("Error\nRequired keys are missing or one is invalid.", 2);
		free_array(array);
		return (-1);
	}
	index = find_map_start(array);
	if (index == -1)
	{
		ft_putendl_fd("Error\nThe start of the map was not found.", 2);
		free_array(array);
		return (-1);
	}
	return (index);
}
