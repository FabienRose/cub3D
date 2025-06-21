/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:33:05 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/21 19:29:43 by diana            ###   ########.fr       */
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

//convierte linked list to array
int main(int argc, char **argv)
{
    t_node *lines_list;
    char **lines_array;
    int i = 0;

    if (argc != 2)
    {
        printf("Usage: ./parser map.cub\n");
        return (1);
    }

    lines_list = read_file_to_list(argv[1]);
    if (!lines_list)
    {
        fprintf(stderr, "Failed to read file\n");
        return (1);
    }

    lines_array = linked_list_to_array(lines_list);
    if (!lines_array)
    {
        free_linked_list(lines_list);
        fprintf(stderr, "Failed to convert to array\n");
        return (1);
    }
    while (lines_array[i])
    {
        printf("%s", lines_array[i]);
        i++;
    }
    free(lines_array); 
    free_linked_list(lines_list); 

    return 0;
}
