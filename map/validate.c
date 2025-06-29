/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:36:56 by diana             #+#    #+#             */
/*   Updated: 2025/06/29 17:18:32 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_line_closed(char *line)
{
	int	i;

	if (!line)
	{
		printf("is_line_closed: línea nula\n");
		return (0);
	}

	// Saltar espacios y saltos de línea al inicio
	i = 0;
	while (line[i] == ' ' || line[i] == '\n')
		i++;

	// Primer carácter visible debe ser '1'
	if (line[i] != '1')
	{
		printf("is_line_closed: primer carácter no es '1' → '%c' (ascii %d)\n", line[i], line[i]);
		return (0);
	}

	// Ir al final
	while (line[i])
		i++;
	i--;

	// Saltar espacios y saltos de línea al final
	while (i >= 0 && (line[i] == ' ' || line[i] == '\n'))
		i--;

	// Último carácter visible debe ser '1'
	if (line[i] != '1')
	{
		printf("is_line_closed: último carácter no es '1' → '%c' (ascii %d)\n", line[i], line[i]);
		return (0);
	}

	return (1);
}


int has_wall_boundaries(char *line)
{
	int start = 0;
	int end;

	if (!line)
	{
		printf("has_wall_boundaries: línea nula\n");
		return (0);
	}

	// Saltar espacios al inicio
	while (line[start] == ' ' || line[start] == '\n')
		start++;

	// Encontrar final real de línea
	end = start;
	while (line[end])
		end++;
	end--;

	// Saltar espacios y \n al final
	while (end >= 0 && (line[end] == ' ' || line[end] == '\n'))
		end--;

	// Mostrar ASCII para depurar
	printf("Evaluando límites en línea: \"%s\"\n", line);
	printf("Primer carácter visible: '%c' (ascii %d)\n", line[start], line[start]);
	printf("Último carácter visible: '%c' (ascii %d)\n", line[end], line[end]);

	if (line[start] != '1' || line[end] != '1')
		return (0);

	return (1);
}


static int count_players(char **map)
{
	int i = 0, j, count = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'E' || map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}


static void	print_ascii(const char *str)
{
	int i = 0;
	while (str[i])
	{
		printf("%d ", (unsigned char)str[i]);
		i++;
	}
	printf("\n");
}

int	validate_map(char **map)
{
	int	i = 0;
	int	empty_line_found = 0;

	if (!map || !map[0])
	{
		printf("viene de validate_map/map\n");
		ft_putendl_fd("Error: el mapa está vacío", 2);
		return (0);
	}

	// Validar líneas vacías internas
	while (map[i])
	{
		if (map[i][0] == '\0')
			empty_line_found = 1;
		else if (empty_line_found)
		{
			printf("viene de validate_map/empty_line_found\n");
			ft_putendl_fd("Error: línea vacía dentro del mapa", 2);
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



