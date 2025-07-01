/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:33:05 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/01 16:29:07 by diana            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char		**array;
	char		**map;
	char		**config;
	int			start_index;
	t_config	*config_data;

	check_args(argc, argv);
	array = load_file_to_array(argv[1]);
	start_index = get_map_start_index(array);
	map = extract_and_validate_map(array, start_index);
	config = get_config_lines(array, map, start_index);
	config_data = parse_config_data(config, map, array);
	ft_putendl_fd("Configuración válida", 1);
	free_array(config);
	free_array(map);
	free_array(array);
	free_config_data(config_data);
	return (0);
}



/* version antes de crear funciones
//IMPORTANTE SIEMPRE EJECUTAR VALIDATE UNIQUE KEYS ANTES DE ENTRAR A PARSE CONFIG
int main(int argc, char **argv)
{
    t_node     *lines;
    char       **array;
    int         start_index;
    char       **map;
    char       **config;
    t_config   *config_data;

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

    // Paso 1: Leer archivo y guardar en lista enlazada
    lines = read_file_to_list(argv[1]);
    if (!lines)
        return (1);

    // Paso 2: Validar claves únicas y sin errores
    if (!validate_unique_keys(lines))
    {
        ft_putendl_fd("Error\nClaves inválidas o duplicadas en el archivo .cub", 2);
        free_list(lines);
        return (1);
    }

    // Paso 3: Convertir lista a array de strings
    array = linked_list_to_array(lines);
    free_list(lines);
    if (!array)
        return (1);

    // Paso 4: Validar formato general de configuración
    if (!parse_map(array))
    {
        ft_putendl_fd("Error\nFaltan claves obligatorias o alguna es inválida", 2);
        free_array(array);
        return (1);
    }
    ft_putendl_fd("Configuración básica válida", 1);

    // Paso 5: Encontrar índice de inicio del mapa
    start_index = find_map_start(array);
    if (start_index == -1)
    {
        ft_putendl_fd("Error\nNo se encontró el inicio del mapa", 2);
        free_array(array);
        return (1);
    }

    // Paso 6: Extraer el mapa
    ft_putendl_fd("Extrae el mapa main", 1);
    map = extract_map(array, start_index);
//meti aqui mensaje de depuracion xk tengo problemas con que dice que esta vacia la linea de arriba o abajo
	for (int i = 0; map[i]; i++)
	{
	printf("MAP[%d] = \"%s\"\n", i, map[i]);
	}
    if (!map || !validate_map(map))
    {
        free_map(map);
        return (0);
    }

//osea que con lo que primero modifico max se acepta el '\n' 
//pero luego se corta ??asi sirve asi que lo dejare 	
    trim_newline_from_map(map);
    printf("Índice inicio del mapa: %d\n", start_index);
    ft_putendl_fd("Contenido extraído del mapa:", 1);
    for (int i = 0; map[i]; i++)
        printf("Mapa línea %d: '%s'\n", i, map[i]);

    // Paso 7: Validar las líneas del mapa
    if (validate_map_lines(map) != 0)
    {
        ft_putendl_fd("Error\nMapa inválido", 2);
        free_array(map);
        free_array(array);
        return (1);
    }

    // Paso 8: Extraer líneas de configuración (antes del mapa)
    ft_putendl_fd("Extrae las líneas de configuración", 1);
    config = extract_config_lines(array, start_index);
    if (!config)
    {
        free_array(map);
        free_array(array);
        return (1);
    }

    // Paso 9: Parsear configuración a estructura
    config_data = parse_config(config);
    if (!config_data)
    {
        ft_putendl_fd("Error\nConfiguración inválida", 2);
        free_array(config);
        free_array(map);
        free_array(array);
        return (1);
    }

    // Paso 10: Éxito
    ft_putendl_fd("Configuración válida", 1);

    // Paso 11: Liberar memoria
    free_array(config);
    free_array(map);
    free_array(array);
    free(config_data->no_texture);
    free(config_data->so_texture);
    free(config_data->ea_texture);
    free(config_data->we_texture);
    free(config_data);

    return (0);
}*/

