/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:07:54 by diana             #+#    #+#             */
/*   Updated: 2025/07/09 17:16:04 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	exit_with_message(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		exit_with_message("Use: ./parser file.cub");
	if (!ends_with_cub(argv[1]))
		exit_with_message("Error\nThe file should end with .cub");
}

char	**load_file_to_array(char *filename)
{
	t_node	*lines;
	char	**array;

	lines = read_file_to_list(filename);
	if (!lines)
		exit(EXIT_FAILURE);
	if (!validate_unique_keys(lines))
	{
		ft_putendl_fd("Error\nInvalid or duplicate keys in the file .cub", 2);
		free_list(lines);
		exit(EXIT_FAILURE);
	}
	array = linked_list_to_array(lines);
	free_list(lines);
	if (!array)
		exit(EXIT_FAILURE);
	return (array);
}

int	get_map_start_index(char **array)
{
	int	index;

	if (!parse_map(array))
	{
		ft_putendl_fd("Error\nRequired keys are missing or one is invalid.", 2);
		free_array(array);
		exit(EXIT_FAILURE);
	}
	index = find_map_start(array);
	if (index == -1)
	{
		ft_putendl_fd("Error\nThe start of the map was not found.", 2);
		free_array(array);
		exit(EXIT_FAILURE);
	}
	return (index);
}
