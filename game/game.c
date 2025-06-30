/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 23:47:17 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/28 23:49:00 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	char *map[] = {
	"1111111111",
	"1000000011",
	"1010110101",
	"1001100101",
	"1000000001",
	"10011N0101",
	"1111111111",
	NULL
};

void	game_init(t_game *game)
{
	game->map = map;
	game->move_speed = 2.0f;
	game->rot_speed = 0.05f;
	game->cell_size = WINDOW_WIDTH / 32;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	game->img.img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->img.data = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.sl, &game->img.endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

int game_loop(void *param)
{
	t_game	*game;
	int		i;
	int		j;

	game = (t_game *)param;
	game_movement(game);
	ft_bzero(game->img.data, WINDOW_WIDTH * WINDOW_HEIGHT
		* (game->img.bpp / 8));
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				draw_square(j * game->cell_size, i * game->cell_size,
					game, game->cell_size, 0xAAAAAA);
			j++;
		}
		i++;
	}
	draw_square((int)game->player.x - 5, (int)game->player.y - 5, game, 10, 0x00FF00);
	cast_rays_90_degrees(game);
	char distance_str[50];
	//To remove
	sprintf(distance_str, "90-degree FOV rays cast");
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, distance_str);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
