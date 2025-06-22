/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:07:31 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/22 13:08:13 by fmixtur          ###   ########.ch       */
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

int key_press(int keycode, void *param)
{
	t_game *game = (t_game *)param;
	if (keycode == XK_w)
	{
		game->player.key_up = 1;
		ft_putstr_fd("W",1);
	}
	else if (keycode == XK_s)
		game->player.key_down = 1;
	else if (keycode == XK_a)
		game->player.key_left = 1;
	else if (keycode == XK_d)
		game->player.key_right = 1;
	else if (keycode == XK_Left)
		game->player.left_rotate = 1;
	else if (keycode == XK_Right)
		game->player.right_rotate = 1;
	else if (keycode == XK_Escape)
		exit(0);
	return (0);
}

int key_release(int keycode, void *param)
{
	t_game *game = (t_game *)param;
	if (keycode == XK_w)
		game->player.key_up = 0;
	else if (keycode == XK_s)
		game->player.key_down = 0;
	else if (keycode == XK_a)
		game->player.key_left = 0;
	else if (keycode == XK_d)
		game->player.key_right = 0;
	else if (keycode == XK_Left)
		game->player.left_rotate = 0;
	else if (keycode == XK_Right)
		game->player.right_rotate = 0;
	return (0);
}

void	setup_hooks(void *win_ptr, t_game *game)
{
	mlx_hook(win_ptr, 17, 0, handle_window_close, NULL);
	mlx_hook(win_ptr, 2, 1L << 0, key_press, game);
	mlx_hook(win_ptr, 3, 1L << 1, key_release, game);
}
