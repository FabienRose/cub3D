/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 22:24:03 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/22 16:34:14 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"
//estas son las funciones propuestas por chato pero que no funcionan del todo
//function to find where the map start
int is_map_line(const char *line)
{
    int i = 0;

    while (line[i])
    {
        if (line[i] == '1' || line[i] == '0' ||
            line[i] == 'N' || line[i] == 'S' ||
            line[i] == 'E' || line[i] == 'W' ||
            line[i] == ' ')
            i++;
        else
            return (0);
    }
    return (1);
}
int starts_with_map_char(const char *line)
{
    while (*line == ' ' || *line == '\t')
        line++;
    return (*line == '1' || *line == '0');
}

//function that returns where the map start
int find_map_start(char **array)
{
    int i = 0;
    int map_started = 0;

    while (array[i])
    {
        if (!map_started && starts_with_map_char(array[i]))
        {
            map_started = 1;
            return i;
        }

        if (map_started && array[i][0] == '\0')
        {
            fprintf(stderr, "Error: mapa interrumpido por línea vacía\n");
            return -1;
        }

        i++;
    }

    fprintf(stderr, "Error: no se encontró el mapa\n");
    return -1;
}

void free_array(char **array)
{
    int i = 0;

    if (!array)
        return;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}

/*
int	validate_map(t_map *map, t_map_config *config)//porque map? si deberia ser **lines no? estructura
{
	int	player_found = 0;
	int	y = -1;
	int	x;

	while (map->lines[++y])
	{
		x = -1;
		while (map->lines[y][++x])
		{
			char c = map->lines[y][x];
			if (!is_valid_map_char(c))
				return (0);
			if (is_player_char(c))
			{
				if (player_found)
					return (0);
				player_found = 1;
				config->player_x = x;
				config->player_y = y;
				config->player_dir = c;
			}
			if (!check_surroundings(map, x, y))
				return (0);
		}
	}
	return (player_found);
}
*/