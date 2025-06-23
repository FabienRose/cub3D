/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 22:23:56 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/23 18:49:11 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct {
    char **config_lines;
    char **map_lines;
} t_file_content;

/*estas estructuras las puse para el primer commit que hice
typedef struct s_color
{
	int r;
	int g;
	int b;
} t_color;

typedef struct s_map
{
	char	**lines;
	int		heigth;
	int		width;
} t_map;

typedef struct s_map_config
{
	//player position 
	int		player_x;
	int		player_y;
	//N, S, E, W
	char	player_dir;
} t_map_config;
*/

//----map.c----
int			find_map_start(char **array);
int			starts_with_map_char(const char *line);
int			is_map_line(const char *line);
void		free_array(char **array);
//int			validate_map(t_map *map, t_map_config *config);

//----extract.c----
char		**extract_map(char **array, int start_index);

//----extract_config.c----
int			is_line_empty_or_spaces_only(const char *line);
char		**extract_config_lines(char **array, int start_index);

//----validator.c----
int			is_valid_component(char *str);
int			validate_rgb_format(char *line);
/*
//----map_utils.c----
char		**load_cub_file(char *filename);
int			check_extension(char *filename);

//----validator.c----
int			is_player_char(char c);
int			is_valid_map_char(char c);
int			check_surroundings(t_map *map, int x, int y);
*/

#endif 