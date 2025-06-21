/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:29:15 by fmixtur           #+#    #+#             */
/*   Updated: 2025/06/21 15:33:17 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
//# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include "libft/libft.h"
//# include "map/map.h"
//# include "parsing/parsing.h"
# include "node/node.h"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720

typedef struct s_data
{
    void    *mlx;
    void    *win;
} t_data;

int     close_window(t_data *data);

#endif 