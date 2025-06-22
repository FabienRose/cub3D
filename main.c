/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:36:21 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/22 13:38:43 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#define _USE_MATH_DEFINES
#include <math.h>
#define M_PI 3.14159265358979323846
#include "cub3d.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	game->img.img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->img.data = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.sl, &game->img.endian);
	player_init(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

int game_loop(void *param)
{
	t_game *game = (t_game *)param;
	float move_speed = 2.0f;
	float rot_speed = 0.05f;

	if (game->player.key_up)
	{
		game->player.x += cosf(game->player.angle) * move_speed;
		game->player.y += sinf(game->player.angle) * move_speed;
	}
	if (game->player.key_down)
	{
		game->player.x -= cosf(game->player.angle) * move_speed;
		game->player.y -= sinf(game->player.angle) * move_speed;
	}
	if (game->player.key_left)
	{
		game->player.x += cosf(game->player.angle - M_PI / 2) * move_speed;
		game->player.y += sinf(game->player.angle - M_PI / 2) * move_speed;
	}
	if (game->player.key_right)
	{
		game->player.x += cosf(game->player.angle + M_PI / 2) * move_speed;
		game->player.y += sinf(game->player.angle + M_PI / 2) * move_speed;
	}
	if (game->player.left_rotate)
		game->player.angle -= rot_speed;
	if (game->player.right_rotate)
		game->player.angle += rot_speed;

	ft_bzero(game->img.data, WINDOW_WIDTH * WINDOW_HEIGHT * (game->img.bpp / 8));
	draw_square((int)game->player.x, (int)game->player.y, game, 0x00FF00);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

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
	init_game(&game);
	setup_hooks(game.win, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
