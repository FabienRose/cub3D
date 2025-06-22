/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:26:56 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/22 19:23:38 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#define _USE_MATH_DEFINES
#include <math.h>
#define M_PI 3.14159265358979323846
#include "cub3d.h"

char *test_map[] = {
	"1111111111",
	"10000S0011",
	"1010100101",
	"1001100101",
	"1000000001",
	"1001100101",
	"1111111111",
	NULL
};

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	game->img.img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->img.data = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.sl, &game->img.endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

int find_and_init_player(char **map, int cell_size, t_game *game)
{
	int i = 0;
	int j;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'E' || map[i][j] == 'W')
			{
				player_init(j * cell_size, i * cell_size, game);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int game_loop(void *param)
{
	t_game *game = (t_game *)param;
	float move_speed = 2.0f;
	float rot_speed = 0.05f;
	int cell_size = WINDOW_WIDTH / 32;
	int i, j;

	// Movement logic
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

	// Draw the map
	i = 0;
	while (test_map[i])
	{
		j = 0;
		while (test_map[i][j])
		{
			if (test_map[i][j] == '1')
				draw_square(j * cell_size, i * cell_size, game, cell_size, 0xAAAAAA);
			j++;
		}
		i++;
	}
	// Draw the player
	draw_square((int)game->player.x, (int)game->player.y, game, 10, 0x00FF00);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	(void)argv;
	int cell_size = WINDOW_WIDTH / 32;
	init_game(&game);
	find_and_init_player(test_map, cell_size, &game);
	setup_hooks(game.win, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
