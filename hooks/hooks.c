/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:16:35 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/20 12:20:22 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include <stdlib.h>
#include <X11/keysym.h>

int	handle_window_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	handle_escape(int keycode, void *param)
{
	(void)param;
	if (keycode == XK_Escape)
		exit(0);
	return (0);
}

int	handle_movement(int keycode, void *param)
{
	(void)param;
	if(keycode == XK_w)
	{
		ft_putstr_fd("TEST OK\n", 1);
	}
	return (0);
}

void	setup_hooks(void *win_ptr)
{
	mlx_hook(win_ptr, 17, 0, handle_window_close, NULL);
	mlx_hook(win_ptr, 2, 1L << 0, handle_escape, NULL);
	mlx_key_hook(win_ptr, handle_movement, NULL);
}
