/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:14:11 by diana             #+#    #+#             */
/*   Updated: 2025/06/21 15:06:27 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"
/*
int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || is_player_char(c));
}

int	check_surroundings(t_map *map, int x, int y)
{
	char **lines = map->lines;

	if (x <= 0 || y <= 0 || y >= map->heigth - 1 || x >= (int)ft_strlen(lines[y]) - 1)
		return (0);

	if (lines[y][x] == '0' || is_player_char(lines[y][x]))
	{
		if (lines[y - 1][x] == ' ' || lines[y + 1][x] == ' ' ||
			lines[y][x - 1] == ' ' || lines[y][x + 1] == ' ')
			return (0);
	}
	return (1);
}
*/
