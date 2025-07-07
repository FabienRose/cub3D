/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:29:15 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/07 09:56:29 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "mlx_linux/mlx.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <string.h> //quitar mas adelante
# include "libft/libft.h"
# include "map/map.h"
# include "player/player.h"
# include "hooks/hooks.h"
# include "render/render.h"
# include "game/game.h"
# include "parsing/parsing.h"
# include "conversion/conversion.h"

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

typedef struct s_data
{
	void	*mlx;
	void	*win;
}	t_data;

#endif 