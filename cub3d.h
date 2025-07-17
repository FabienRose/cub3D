/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:31:59 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/16 22:32:40 by fmixtur          ###   ########.ch       */
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
# include "parsing/parsing.h"
# include "conversion/conversion.h"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define PI 3.14159265358979323846

typedef struct s_config
{
	char	*no_texture;
	char	*so_texture;
	char	*ea_texture;
	char	*we_texture;
	int		floor_color;
	int		ceiling_color;
}	t_config;
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

typedef struct s_parsing_data
{
	char		**file_array;
	char		**map;
	char		**config_lines;
	int			map_start_index;
	t_config	config;
}	t_parsing_data;

//----parsing_init.c----
int				initialize_parsing_data(t_parsing_data *parsing,
					char *filename);
void			free_parsing_data(t_parsing_data *parsing);

//----parsing_init_utils.c----
int				extract_all_textures(t_parsing_data *parsing);
int				extract_config_data(t_parsing_data *parsing);
int				load_and_parse_config(t_parsing_data *parsing);
int				load_and_validate_map(t_parsing_data *parsing);

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			square_size;
	t_player	player;
	t_config	config;
	char		**map;
	float		move_speed;
	float		rot_speed;
	int			cell_size;
	int			minimap_cell_size;
	t_img		textures[4];
	int			texture_width;
	int			texture_height;
}	t_game;

#endif 