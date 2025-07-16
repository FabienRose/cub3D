/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:22:41 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/16 17:22:41 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	extract_all_textures(t_parsing_data *parsing)
{
	if (!extract_texture_by_prefix(parsing->config_lines, &parsing->config.no_texture, "NO "))
	{
		ft_putendl_fd("Error\nInvalid north texture", 2);
		return (0);
	}
	if (!extract_texture_by_prefix(parsing->config_lines, &parsing->config.so_texture, "SO "))
	{
		ft_putendl_fd("Error\nInvalid south texture", 2);
		return (0);
	}
	if (!extract_texture_by_prefix(parsing->config_lines, &parsing->config.we_texture, "WE "))
	{
		ft_putendl_fd("Error\nInvalid west texture", 2);
		return (0);
	}
	if (!extract_texture_by_prefix(parsing->config_lines, &parsing->config.ea_texture, "EA "))
	{
		ft_putendl_fd("Error\nInvalid east texture", 2);
		return (0);
	}
	return (1);
}

static int	extract_config_data(t_parsing_data *parsing)
{
	if (!initialize_config_data(&parsing->config))
	{
		ft_putendl_fd("Error\nConfig initialization failed", 2);
		return (0);
	}
	if (!extract_all_textures(parsing))
		return (0);
	if (!extract_colors(parsing->config_lines, &parsing->config))
	{
		ft_putendl_fd("Error\nInvalid colors", 2);
		return (0);
	}
	return (1);
}

int	initialize_parsing_data(t_parsing_data *parsing, char *filename)
{
	parsing->file_array = load_file_to_array(filename);
	if (!parsing->file_array)
		return (0);
	
	parsing->map_start_index = get_map_start_index(parsing->file_array);
	
	parsing->config_lines = get_config_lines(parsing->file_array, NULL, 
		parsing->map_start_index);
	if (!parsing->config_lines)
	{
		free_array(parsing->file_array);
		return (0);
	}
	
	if (!extract_config_data(parsing))
	{
		free_parsing_data(parsing);
		return (0);
	}
	
	parsing->map = extract_and_validate_map(parsing->file_array, 
		parsing->map_start_index);
	if (!parsing->map)
	{
		ft_putendl_fd("Error\nInvalid map", 2);
		free_parsing_data(parsing);
		return (0);
	}
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
