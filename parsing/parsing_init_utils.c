/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:44:00 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/21 00:44:00 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	extract_all_textures(t_parsing_data *parsing)
{
	if (!extract_texture_by_prefix(parsing->config_lines,
			&parsing->config.no_texture, "NO "))
	{
		ft_putendl_fd("Error\nInvalid north texture", 2);
		return (0);
	}
	if (!extract_texture_by_prefix(parsing->config_lines,
			&parsing->config.so_texture, "SO "))
	{
		ft_putendl_fd("Error\nInvalid south texture", 2);
		return (0);
	}
	if (!extract_texture_by_prefix(parsing->config_lines,
			&parsing->config.we_texture, "WE "))
	{
		ft_putendl_fd("Error\nInvalid west texture", 2);
		return (0);
	}
	if (!extract_texture_by_prefix(parsing->config_lines,
			&parsing->config.ea_texture, "EA "))
	{
		ft_putendl_fd("Error\nInvalid east texture", 2);
		return (0);
	}
	return (1);
}

int	extract_config_data(t_parsing_data *parsing)
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

int	load_and_parse_config(t_parsing_data *parsing)
{
	parsing->config_lines = get_config_lines(parsing->file_array,
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
	return (1);
}

int	load_and_validate_map(t_parsing_data *parsing)
{
	parsing->map = extract_and_validate_map(parsing->file_array,
			parsing->map_start_index);
	if (!parsing->map)
	{
		ft_putendl_fd("Error\nInvalid map", 2);
		return (0);
	}
	return (1);
}
