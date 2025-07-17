/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:08:42 by diana             #+#    #+#             */
/*   Updated: 2025/07/09 14:47:53 by diana            ###   ########.fr       */
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

void	free_config_data(t_config *data)
{
	if (!data)
		return ;
	free(data->no_texture);
	free(data->so_texture);
	free(data->ea_texture);
	free(data->we_texture);
}

int	initialize_config_data(t_config *cfg)
{
	if (!cfg)
		return (0);
	cfg->no_texture = NULL;
	cfg->so_texture = NULL;
	cfg->ea_texture = NULL;
	cfg->we_texture = NULL;
	cfg->floor_color = -1;
	cfg->ceiling_color = -1;
	return (1);
}
