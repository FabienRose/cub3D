/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:14:11 by diana             #+#    #+#             */
/*   Updated: 2025/06/20 17:37:16 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || is_player_char(c));
}

int	check_surroundings(char **map, int x, int y)
{
	if (x == 0 || y == 0 || !map[y][x] || !map[y + 1] || x >= (int)ft_strlen(map[y]))
		return (0);
	if (map[y][x] == '0' || is_player_char(map[y][x]))
	{
		if (map[y - 1][x] == ' ' || map[y + 1][x] == ' ' ||
			map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
			return (0);
	}
	return (1);
}
