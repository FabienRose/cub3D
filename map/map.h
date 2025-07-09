/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:30:12 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/08 00:30:23 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../conversion/conversion.h"
# include "../parsing/parsing.h"
# include <stdio.h>

typedef struct s_file_content
{
        char    **config_lines;
        char    **map_lines;
}       t_file_content;

typedef struct s_flags
{
        int     no;
        int     so;
        int     we;
        int     ea;
        int     f;
        int     c;
}       t_flags;

typedef struct s_flood_data
{
        char    **map;
        int             width;
        int             height;
}                       t_flood_data;

typedef struct s_game_map
{
        char            **map_data;
        int             width;
        int             height;
}       t_game_map;

//----map_dimensions.c----
t_game_map      *init_game_map(char **map_data);
int                     get_map_height(char **map);
int                     get_map_width(char **map);
char            get_map_cell(t_game_map *game_map, int x, int y);
void            free_game_map(char **map);

//----espaces_and_empty.c----
int                     is_line_empty_or_spaces_only(const char *line);
int                     count_non_empty_lines(char **array, int start_index);
char            *ft_strtrim_whitespace(const char *s);

//----extract_config_line.c----
char            **allocate_config_array(int count);
void            free_config_on_failure(char **config, int j);
char            **fill_config_array(char **config, char **array, int start_index);
char            **allocate_and_fill_config(char **array, int start_index, \
                        int count);
char            **extract_config_lines(char **array, int start_index);

//----extract_map.c----
char            **extract_map(char **array, int start);

//----make_rectangular.c----
char            **make_map_rectangular(char **map);

//----debug_map.c----
void            print_map_debug(char **map, char *title);

//----validate_leaks.c----
int                     validate_no_leaks(char **map);

//----validate_rectangular.c----
int                     validate_rectangular_map(char **map);

//----main_utils_2.c----
char            **get_config_lines(char **array, char **map, int start_index);
t_config        *parse_config_data(char **config, char **map, char **array);
void            free_config_data(t_config *data);

//----main_utils.c----
void            exit_with_message(char *msg);
void            check_args(int argc, char **argv);
char            **load_file_to_array(char *filename);
int                     get_map_start_index(char **array);
char            **extract_and_validate_map(char **array, int start_index);

//----map_utils.c----
void            free_array(char **array);
void            free_map(char **map);
int                     is_valid_component(char *str);

//----map.c----
int                     find_map_start(char **array);
int                     starts_with_map_char(const char *line);
int                     is_map_line(const char *line);
int                     validate_map_lines(char **map);

//----rgb_utils.c----
int                     validate_rgb_format(char *line);

//----rgb.c----
int                     rgb_to_int(char *rgb_str);

//----utils.c----
char            **copy_map(char **map);

//----validate_utils.c----
int                     ends_with_cub(const char *filename);
int                     check_and_set_flag(const char *line, t_flags *flags);
int                     all_flags_set(t_flags *flags);
int                     is_valid_key(const char *line);
int                     is_unrecognized_key(const char *line);

//----validate_key_extension.c----
int                     validate_unique_keys(t_node *list);

//----validate_map_utils.c----
int                     is_first_char_valid(char *line, int *i);
int                     is_last_char_valid(char *line, int i);
int                     is_line_closed(char *line);
int                     has_wall_boundaries(char *line);
int                     check_empty_lines(char **map);

//----validate_map.c----
int                     count_players(char **map);
int                     check_top_and_bottom_closed(char **map, int line_count);
int                     check_side_boundaries(char **map, int line_count);
int                     check_player_count(char **map);
int                     validate_map(char **map);

//----validate_irregular_map.c----
int                     validate_irregular_map_borders(char **map);
int                     validate_surrounded_spaces(char **map);

//----validate_utils.c----
int                     ends_with_cub(const char *filename);
int                     check_and_set_flag(const char *line, t_flags *flags);
int                     all_flags_set(t_flags *flags);
int                     is_valid_key(const char *line);
int                     is_unrecognized_key(const char *line);

//----collision.c----
int                     is_wall(t_game_map *game_map, int x, int y);
int                     is_position_valid(t_game_map *game_map, double x, double y);
int                     can_move_to(t_game_map *game_map, double new_x, double new_y);
int                     move_player(t_game_map *game_map, double new_x, double new_y);

#endif 