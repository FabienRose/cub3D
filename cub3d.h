/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:51:32 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/28 22:52:43 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "map/map.h"
# include "player/player.h"
# include "hooks/hooks.h"
# include "render/render.h"
# include "game/game.h"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define PI 3.14159265358979323846

typedef struct s_img
{
	void	*img;
	int		bpp;
	int		sl;
	int		endian;
	char	*data;
}	t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	int		key_up;
	int		key_down;
	int		key_left;
	int		key_right;
	int		left_rotate;
	int		right_rotate;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	player;
	char		**map;
	float		move_speed;
	float		rot_speed;
	int			cell_size;
}	t_game;

#endif 