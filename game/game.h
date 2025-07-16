/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 23:27:58 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/16 22:10:08 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../cub3d.h"

typedef struct s_player			t_player;
typedef struct s_img			t_img;
typedef struct s_config			t_config;
typedef struct s_game_map		t_game_map;
typedef struct s_parsing_data	t_parsing_data;

int		game_init(t_game *game, t_parsing_data *parsing);
int		load_textures(t_game *game);
int		game_loop(void *param);
void	game_move_up(t_game *game);
void	game_move_down(t_game *game);
void	game_move_left(t_game *game);
void	game_move_right(t_game *game);
void	game_movement(t_game *game);

#endif