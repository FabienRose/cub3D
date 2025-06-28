/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 22:23:56 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/28 16:33:50 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../conversion/conversion.h"

typedef struct {
    char **config_lines;
    char **map_lines;
} t_file_content;

typedef struct s_flags {
	int no;
	int so;
	int we;
	int ea;
	int f;
	int c;
}	t_flags;

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
int			validate_map_lines(char **map);
//temporal
void		print_map_ascii_codes(char **map);

//----map_utils.c----
void		free_array(char **array);

//----extract_map.c----
char		**extract_map(char **array, int start);

//----extract_config.c----
int			is_line_empty_or_spaces_only(const char *line);
char		**extract_config_lines(char **array, int start_index);

//----rgb.c----
int			is_valid_component(char *str);
int			validate_rgb_format(char *line);
int			create_rgb_color(int r, int g, int b);
char		*ft_strtrim_whitespace(const char *s);

//----validate_key_extension.c----
int			ends_with_cub(const char *filename);
int			check_and_set_flag(const char *line, t_flags *flags);
int			all_flags_set(t_flags *flags);
int			validate_unique_keys(t_node *list);


#endif 