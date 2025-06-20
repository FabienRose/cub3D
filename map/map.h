/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 22:23:56 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/20 17:44:57 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../cub3d.h"

typedef struct s_color
{
	int r;
	int g;
	int b;
} t_color;

typedef struct s_map_config
{
	//player position 
	int		player_x;
	int		player_y;
	//N, S, E, W
	char	player_dir;
	//map 
	char	**map;
	int		map_heigth;
	int		map_width;
	//texture
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	t_color	floor_color;
	t_color	ceiling_color;
} t_map_config;



//----map.c----
int			validate_map(t_map_config *config);

//----map_utils.c----
char		**load_cub_file(char *filename);
int			check_extension(char *filename);

//----validator.c----
int			is_player_char(char c);
int			is_valid_map_char(char c);
int			check_surroundings(char **map, int x, int y);

#endif 