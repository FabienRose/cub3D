/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:25:09 by diana             #+#    #+#             */
/*   Updated: 2025/07/02 23:06:37 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_config_data(t_config *cfg)
{
	printf("=== CONFIGURATION DATA ===\n");
	printf("North texture: %s\n", get_north_texture(cfg));
	printf("South texture: %s\n", get_south_texture(cfg));
	printf("West texture: %s\n", get_west_texture(cfg));
	printf("East texture: %s\n", get_east_texture(cfg));
	printf("Floor color: %d (0x%06x)\n", get_floor_color(cfg), get_floor_color(cfg));
	printf("Ceiling color: %d (0x%06x)\n", get_ceiling_color(cfg), get_ceiling_color(cfg));
	printf("===========================\n");
}