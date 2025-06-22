/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:01:36 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/22 13:01:36 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
#define HOOKS_H

# include "../cub3d.h"

typedef struct s_game	t_game;

void setup_hooks(void *win_ptr, t_game *game);
int handle_window_close(void *param);
int handle_escape(int keycode, void *param);
int key_press(int keycode, void *param);
int key_release(int keycode, void *param);


#endif