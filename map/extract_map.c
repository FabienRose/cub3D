/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:13:46 by diana             #+#    #+#             */
/*   Updated: 2025/06/29 14:37:07 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* aparentemente para mas adelante
static char	**copy_and_clean_map(char **array, int start_index, int count)
{
	char	**map;
	int		i;

	map = malloc((count + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < count)
	{
		map[i] = ft_strdup(array[start_index + i]);
		if (!map[i])
		{
			free_array(map);
			return (NULL);
		}
		clean_line(map[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}*/

static int	count_map_lines(char **array, int start)
{
	int count = 0;
	while (array[start] && array[start][0] != '\0')
	{
		count++;
		start++;
	}
	return (count);
}

static void	fill_map(char **map, char **array, int start)
{
	int i = 0;
	while (array[start] && array[start][0] != '\0')
	{
		map[i] = ft_strdup(array[start]);
		i++;
		start++;
	}
	map[i] = NULL;
}

char	**extract_map(char **array, int start)
{
	int		lines;
	char	**map;

	ft_putendl_fd("Extrae el mapa", 1);
	lines = count_map_lines(array, start);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
	{
		ft_putendl_fd("Error: malloc fallo", 2);
		return (NULL);
	}
	fill_map(map, array, start);
	return (map);
}
