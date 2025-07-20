/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 01:04:33 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/21 01:04:33 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	initialize_parsing_data(t_parsing_data *parsing, char *filename)
{
	ft_bzero(parsing, sizeof(t_parsing_data));
	parsing->file_array = load_file_to_array(filename);
	if (!parsing->file_array)
		return (0);
	parsing->map_start_index = get_map_start_index(parsing->file_array);
	if (parsing->map_start_index == -1)
		return (0);
	if (!load_and_parse_config(parsing))
		return (0);
	if (!load_and_validate_map(parsing))
		return (0);
	return (1);
}

void	free_parsing_data(t_parsing_data *parsing)
{
	if (parsing->config_lines)
		free_array(parsing->config_lines);
	if (parsing->file_array)
		free_array(parsing->file_array);
	if (parsing->map)
		free_array(parsing->map);
	free_config_data(&parsing->config);
}
