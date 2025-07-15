/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 07:59:57 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/15 07:59:57 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// 	char *map[] = {
// 	"1111111111",
// 	"1000000011",
// 	"1010110101",
// 	"1001100101",
// 	"1000000001",
// 	"10011N0101",
// 	"1111111111",
// 	NULL
// };

void	game_init(t_game *game)
{
	game->move_speed = 5.0f;
	game->rot_speed = 0.05f;
	game->cell_size = 64;
	game->minimap_cell_size = WINDOW_WIDTH / 100;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	game->img.img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->img.data = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.sl, &game->img.endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

int	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game_movement(game);
	ft_bzero(game->img.data, WINDOW_WIDTH * WINDOW_HEIGHT
		* (game->img.bpp / 8));
	draw_background(game);
	cast_rays_3d(game);
	draw_map(game);
	int px = (game->player.x / game->cell_size) * game->minimap_cell_size;
	int py = (game->player.y / game->cell_size) * game->minimap_cell_size;
	int psize = game->minimap_cell_size / 2;
	draw_square(px - psize / 2, py - psize / 2, game, psize, 0x00FF00);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
