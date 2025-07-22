/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diramire <diramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:30:28 by diana             #+#    #+#             */
/*   Updated: 2025/07/22 11:37:14 by diramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_line_length_trimmed(char *line)
{
	int	len;

	if (!line)
		return (0);
	len = 0;
	while (line[len])
		len++;
	while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\n'))
		len--;
	return (len);
}

int	get_first_non_space_pos(char *line)
{
	int	i;

	if (!line)
		return (-1);
	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\n'))
		i++;
	return (i);
}

int	is_valid_map_neighbor(char **map, int x, int y)
{
	if (!map[y] || x < 0 || x >= (int)ft_strlen(map[y]))
		return (0);
	if (map[y][x] == '1' || map[y][x] == '0' || \
map[y][x] == 'N' || map[y][x] == 'S' || \
map[y][x] == 'E' || map[y][x] == 'W')
		return (1);
	return (0);
}
