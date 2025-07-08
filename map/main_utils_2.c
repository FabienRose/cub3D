/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:08:42 by diana             #+#    #+#             */
/*   Updated: 2025/07/08 18:25:11 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**get_config_lines(char **array, char **map, int start_index)
{
	char	**config;

	config = extract_config_lines(array, start_index);
	if (!config)
	{
		free_array(map);
		free_array(array);
		exit(EXIT_FAILURE);
	}
	return (config);
}

t_config	*parse_config_data(char **config, char **map, char **array)
{
	t_config	*data;

	data = parse_config(config);
	if (!data)
	{
		ft_putendl_fd("Error\nInvalid configuration", 2);
		free_array(config);
		free_array(map);
		free_array(array);
		exit(EXIT_FAILURE);
	}
	return (data);
}

void	free_config_data(t_config *data)
{
	if (!data)
		return;
	free(data->no_texture);
	free(data->so_texture);
	free(data->ea_texture);
	free(data->we_texture);
	free(data);
}
