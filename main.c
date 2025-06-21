/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:33:05 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/21 21:59:30 by diana            ###   ########.fr       */
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

//nos dice donde empieza el mapa 
int main(int argc, char **argv)
{
    t_node *list = NULL;
    char **lines;
    int map_start;

    if (argc != 2)
    {
        printf("Usage: ./parser map.cub\n");
        return (1);
    }

    list = read_file_to_list(argv[1]);
    lines = linked_list_to_array(list);
    map_start = find_map_start_index(lines);

    if (map_start >= 0)
        printf("El mapa empieza en la línea %d: %s\n", map_start, lines[map_start]);
    else
        printf("No se encontró mapa.\n");

    free_linked_list(list);
    free_array(lines);
    return (0);
}