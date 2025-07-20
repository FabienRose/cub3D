/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:02:08 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/19 16:02:17 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**get_config_lines(char **array, int start_index)
{
	char	**config;

	config = extract_config_lines(array, start_index);
	if (!config)
	{
		return (NULL);
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
