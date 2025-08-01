/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diramire <diramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 01:07:14 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/22 11:29:36 by diramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	setup_game(t_game *game, t_parsing_data *parsing)
{
	game->config = parsing->config;
	game->map = parsing->map;
	game->move_speed = 5.0f;
	game->rot_speed = 0.05f;
	game->cell_size = 64;
	game->minimap_cell_size = WINDOW_WIDTH / 100;
	game->mlx = mlx_init();
}

void	cleanup_game(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = 0;
	while (i < 4)
	{
		if (game->textures[i].img && game->mlx)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		i++;
	}
	if (game->mlx)
	{
		if (game->img.img)
			mlx_destroy_image(game->mlx, game->img.img);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	game_init(t_game *game, t_parsing_data *parsing)
{
	ft_bzero(game, sizeof(t_game));
	setup_game(game, parsing);
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (!game->win)
		return (0);
	game->img.img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->img.img)
		return (0);
	game->img.data = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.sl, &game->img.endian);
	if (!game->img.data)
		return (0);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	if (!load_textures(game))
	{
		ft_putendl_fd("Error\nFailed to load textures", 2);
		return (0);
	}
	return (1);
}

int	game_loop(void *param)
{
	t_game	*game;
	int		px;
	int		py;

	game = (t_game *)param;
	game_movement(game);
	ft_bzero(game->img.data, WINDOW_WIDTH * WINDOW_HEIGHT
		* (game->img.bpp / 8));
	draw_background(game);
	cast_rays_3d(game);
	draw_map(game);
	game->square_size = game->minimap_cell_size;
	px = (game->player.x / game->cell_size) * game->minimap_cell_size;
	py = (game->player.y / game->cell_size) * game->minimap_cell_size;
	game->square_size = game->minimap_cell_size / 2;
	draw_square(px - game->square_size / 2, py - game->square_size / 2,
		game, 0x00FF00);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
