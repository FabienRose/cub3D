/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_getters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:22:36 by diana             #+#    #+#             */
/*   Updated: 2025/07/09 16:51:41 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_north_texture(t_config *cfg)
{
	if (!cfg)
		return (NULL);
	return (cfg->no_texture);
}

char	*get_south_texture(t_config *cfg)
{
	if (!cfg)
		return (NULL);
	return (cfg->so_texture);
}

char	*get_west_texture(t_config *cfg)
{
	if (!cfg)
		return (NULL);
	return (cfg->we_texture);
}

char	*get_east_texture(t_config *cfg)
{
	if (!cfg)
		return (NULL);
	return (cfg->ea_texture);
}

int	get_floor_color(t_config *cfg)
{
	if (!cfg)
		return (-1);
	return (cfg->floor_color);
}
