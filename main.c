/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:33:05 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/22 17:11:29 by diana            ###   ########.fr       */
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

//extract the map from the file.cub
int main(int argc, char **argv)
{
    t_node *lines;
    char **array;
    int start_index;
	char **map;

    if (argc != 2)
    {
        fprintf(stderr, "Uso: ./parser archivo.cub\n");
        return (1);
    }

    lines = read_file_to_list(argv[1]);
    if (!lines)
        return (1);

    array = linked_list_to_array(lines);
    free_linked_list(lines);

    if (!array)
        return (1);

    start_index = find_map_start(array);
    if (start_index == -1)
    {
        free_array(array);
        return (1);
    }
	map = extract_map(array, start_index);
	if (!map)
	{
   		free_array(array);
   		return (1);
	}
	printf("Contenido del mapa aislado:\n");
	for (int i = 0; map[i]; i++)
    	printf("%s\n", map[i]);
	
    free_array(map);
    return (0);
}

