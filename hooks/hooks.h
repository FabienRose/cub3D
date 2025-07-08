/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:23:39 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/08 10:27:11 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "../cub3d.h"

#ifdef __linux__
# include <X11/keysym.h>
# define KEY_W XK_w
# define KEY_A XK_a
# define KEY_S XK_s
# define KEY_D XK_d
# define KEY_LEFT XK_Left
# define KEY_RIGHT XK_Right
# define KEY_ESC XK_Escape
#else
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
#endif

typedef struct s_game	t_game;

void	hooks_setup(void *win_ptr, t_game *game);

#endif