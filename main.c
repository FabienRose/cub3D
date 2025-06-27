/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:33:05 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/27 20:50:50 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./cub3D <map.cub>\n", 2);
		return (1);
	}
	if (!check_extension(argv[1]))
	{
		ft_putstr_fd("Error\nMap file must have .cub extension\n", 2);
		return (1);
	}
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	if (!data.win)
	{
		free(data.mlx);
		return (1);
	}
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
*/

//IMPORTANTE SIEMPRE EJECUTAR VALIDATE UNIQUE KEYS ANTES DE ENTRAR A PARSE CONFIG
int main(int argc, char **argv)
{
    t_node *lines;
    char **array;
    int start_index;
    char **map;
    char **config;
    t_config *config_data;

    if (argc != 2)
    {
        ft_putendl_fd("Uso: ./parser archivo.cub", 2);
        return (1);
    }

    if (!ends_with_cub(argv[1]))
    {
        ft_putendl_fd("Error\nEl archivo debe terminar en .cub", 2);
        return (1);
    }

    lines = read_file_to_list(argv[1]);
    if (!lines)
        return (1);

    if (!validate_unique_keys(lines))
    {
        ft_putendl_fd("Error\nClaves inválidas o duplicadas en el archivo .cub", 2);
        free_list(lines);
        return (1);
    }

    if (!parse_map(lines))
    {
        ft_putendl_fd("Fallo el parseo.", 2);
        free_list(lines);
        return (1);
    }
    ft_putendl_fd("Configuración válida", 1);

    array = linked_list_to_array(lines);
    free_list(lines);
    if (!array)
        return (1);
    start_index = find_map_start(array);
    if (start_index == -1)
    {
        free_array(array);
        return (1);
    }

    ft_putendl_fd("extrae el mapa", 1);

    map = extract_map(array, start_index);
    if (!map)
    {
        free_array(array);
        return (1);
    }

    config = extract_config_lines(array, start_index);
    if (!config)
    {
        free_array(array);
        free_array(map);
        return (1);
    }

    ft_putendl_fd("extrae las lineas de config", 1);

    config_data = parse_config(config);
    if (!config_data)
    {
        printf("Error: configuración inválida\n");
        free_array(array);
        free_array(config);
        free_array(map);
        return (1);
    }
    
    printf("Configuración válida\n");
    ft_putendl_fd("llega a imprimir las lineas?", 1);
    printf("Texturas:\n");
    printf("NO: %s\n", config_data->no_texture);
    printf("SO: %s\n", config_data->so_texture);
    printf("EA: %s\n", config_data->ea_texture);
    printf("WE: %s\n", config_data->we_texture);
    printf("Floor: %i\n", config_data->floor_color);
    printf("Ceiling: %i\n", config_data->ceiling_color);

    free_array(array);
    free_array(config);
    free_array(map);
    free(config_data->no_texture);
    free(config_data->so_texture);
    free(config_data->ea_texture);
    free(config_data->we_texture);
    free(config_data);

    return (0);
}
