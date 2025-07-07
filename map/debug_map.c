/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:31:12 by diana             #+#    #+#             */
/*   Updated: 2025/07/02 16:44:04 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_map_debug(char **map, char *title)
{
	int	i;

	if (!map)
		return ;
	printf("\n=== %s ===\n", title);
	i = 0;
	while (map[i])
	{
		printf("Line %d (len=%zu): [%s]\n", i, ft_strlen(map[i]), map[i]);
		i++;
	}
	printf("=== End %s ===\n\n", title);
}