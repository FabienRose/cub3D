/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:31:47 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/19 10:31:47 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
#define HOOKS_H

# include "../cub3d.h"

void setup_hooks(void *win_ptr);
int handle_window_close(void *param);
int handle_escape(int keycode, void *param);


#endif // HOOKS_H 