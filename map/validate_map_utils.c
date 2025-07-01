/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:36:56 by diana             #+#    #+#             */
/*   Updated: 2025/07/01 09:58:27 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_first_char_valid(char *line, int *i)
{
	while (line[*i] == ' ' || line[*i] == '\n')
		(*i)++;
	if (line[*i] != '1')
	{
		printf("is_line_closed: first character is not '1' → '%c' \
		(ascii %d)\n", line[*i], line[*i]);
		return (0);
	}
	return (1);
}

int	is_last_char_valid(char *line, int i)
{
	while (i >= 0 && (line[i] == ' ' || line[i] == '\n'))
		i--;
	if (line[i] != '1')
	{
		printf("is_line_closed: last character is not '1' → '%c' \
		(ascii %d)\n", line[i], line[i]);
		return (0);
	}
	return (1);
}

int	is_line_closed(char *line)
{
	int	i;

	if (!line)
	{
		printf("unvalid map line\n");
		return (0);
	}
	i = 0;
	if (!is_first_char_valid(line, &i))
		return (0);
	while (line[i])
		i++;
	if (!is_last_char_valid(line, i - 1))
		return (0);
	return (1);
}

int	has_wall_boundaries(char *line)
{
	int	start;
	int	end;

	start = 0;
	if (!line)
	{
		printf("has_wall_boundaries: line not valid\n");
		return (0);
	}
	while (line[start] == ' ' || line[start] == '\n')
		start++;
	end = start;
	while (line[end])
		end++;
	end--;
	while (end >= 0 && (line[end] == ' ' || line[end] == '\n'))
		end--;
	if (line[start] != '1' || line[end] != '1')
		return (0);
	return (1);
}

int	check_empty_lines(char **map)
{
	int	i;
	int	empty_line_found;

	i = 0;
	empty_line_found = 0;
	while (map[i])
	{
		if (map[i][0] == '\0')
		{
			empty_line_found = 1;
		}
		else if (empty_line_found)
		{
			printf("Error: empty line on the map\n");
			return (0);
		}
		i++;
	}
	return (1);
}

/* la guardare para pruebas 
int	validate_map(char **map)
{
	int	i = 0;
	int	empty_line_found = 0;

	if (!map || !map[0])
	{
		printf("Error: the map is empty");
		return (0);
	}
	while (map[i])
	{
		if (map[i][0] == '\0')
			empty_line_found = 1;
		else if (empty_line_found)
		{
			printf("Error: empty line on the map");
			return (0);
		}
		i++;
	}

	// Depuración: líneas superior e inferior
	printf("Altura del mapa detectada = %d\n", i);
	printf("Contenido de map[0]: \"%s\"\n", map[0]);
	printf("Contenido de map[%d]: \"%s\"\n", i - 1, map[i - 1]);
	printf("ASCII de map[0]: ");
	print_ascii(map[0]);
	printf("ASCII de map[%d]: ", i - 1);
	print_ascii(map[i - 1]);

	// Validar muros arriba y abajo
	int top_closed = is_line_closed(map[0]);
	int bottom_closed = is_line_closed(map[i - 1]);

	printf("Resultado is_line_closed(map[0]) = %d\n", top_closed);
	printf("Resultado is_line_closed(map[%d]) = %d\n", i - 1, bottom_closed);

	if (!top_closed || !bottom_closed)
	{
		ft_putendl_fd("viene de validate_map/is_line_closed", 2);
		ft_putendl_fd("Error: el mapa no está cerrado por arriba o abajo", 2);
		return (0);
	}

	// Validar muros laterales
	for (int j = 0; j < i; j++)
	{
		if (!has_wall_boundaries(map[j]))
		{
			printf("viene de validate_map/has_wall_boundaries\n");
			printf("Línea fallida (map[%d]) = \"%s\"\n", j, map[j]);
			print_ascii(map[j]);
			ft_putendl_fd("Error: el mapa no está cerrado por los lados", 2);
			return (0);
		}
	}

	// Validar un único jugador
	int player_count = count_players(map);
	printf("Cantidad de jugadores encontrados = %d\n", player_count);
	if (player_count != 1)
	{
		printf("viene de validate_map/count_player\n");
		ft_putendl_fd("Error: debe haber exactamente un jugador (N, S, E o W)", 2);
		return (0);
	}

	return (1);
}
*/


