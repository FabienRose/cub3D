/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_leaks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:00:00 by diana             #+#    #+#             */
/*   Updated: 2025/07/02 20:29:57 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	flood_fill(t_flood_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->width || y >= data->height)
		return ;
	if (data->map[y][x] == '1' || data->map[y][x] == 'X')
		return ;
	data->map[y][x] = 'X';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}

static int	find_player_pos(char **map, int *px, int *py)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'E' || map[i][j] == 'W')
			{
				*px = j;
				*py = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_remaining_zeros(char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == '0')
			{
				printf("Error: Leak detected at position (%d,%d)\n", j, i);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	perform_flood_fill(char **map_copy)
{
	t_flood_data	data;
	int				px;
	int				py;
	int				height;

	if (!find_player_pos(map_copy, &px, &py))
		return (0);
	height = 0;
	while (map_copy[height])
		height++;
	data.map = map_copy;
	data.width = ft_strlen(map_copy[0]);
	data.height = height;
	flood_fill(&data, px, py);
	return (1);
}

int	validate_no_leaks(char **map)
{
	char	**map_copy;
	int		result;

	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	if (!perform_flood_fill(map_copy))
	{
		free_array(map_copy);
		return (0);
	}
	result = check_remaining_zeros(map_copy);
	free_array(map_copy);
	return (result);
}
