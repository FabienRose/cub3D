/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 22:24:03 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/29 14:28:58 by diana            ###   ########.fr       */
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
            line[i] == ' ' || line[i] == '\n')
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
			printf("VIENE DE FIND_MAP_START");
            fprintf(stderr, "Error: mapa interrumpido por línea vacía\n");
            return -1;
        }
        i++;
    }
	printf("VIENE DE FIND_MAP_START");
    fprintf(stderr, "Error: no se encontró el mapa\n");
    return -1;
}

int	validate_map_lines(char **map)
{
	int	i;

	if (!map)
		return (1);
	i = 0;
	while (map[i])
	{
		if (!is_map_line(map[i]))
		{
			printf("VIENE DE VALIDATE_MAP");
			fprintf(stderr, "Error: línea %d del mapa contiene caracteres inválidos\n", i);
			return (1);
		}
		i++;
	}
	return (0);
}
