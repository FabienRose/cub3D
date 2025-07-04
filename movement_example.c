/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_example.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:17:34 by diana             #+#    #+#             */
/*   Updated: 2025/07/04 14:17:45 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MOVE_SPEED 0.1

/* Ejemplo de cómo mover al jugador hacia adelante basado en su dirección actual */
void	move_forward(t_game_map *game_map)
{
	double	new_x;
	double	new_y;

	new_x = game_map->player.x + cos(game_map->player.dir) * MOVE_SPEED;
	new_y = game_map->player.y - sin(game_map->player.dir) * MOVE_SPEED;
	
	if (move_player(game_map, new_x, new_y))
		printf("Player moved to (%.2f, %.2f)\n", new_x, new_y);
	else
		printf("Movement blocked - wall or boundary detected\n");
}

/* Ejemplo de cómo mover al jugador hacia atrás */
void	move_backward(t_game_map *game_map)
{
	double	new_x;
	double	new_y;

	new_x = game_map->player.x - cos(game_map->player.dir) * MOVE_SPEED;
	new_y = game_map->player.y + sin(game_map->player.dir) * MOVE_SPEED;
	
	move_player(game_map, new_x, new_y);
}

/* Ejemplo de cómo mover al jugador hacia la izquierda (strafe) */
void	move_left(t_game_map *game_map)
{
	double	new_x;
	double	new_y;

	new_x = game_map->player.x + cos(game_map->player.dir + M_PI/2) * MOVE_SPEED;
	new_y = game_map->player.y - sin(game_map->player.dir + M_PI/2) * MOVE_SPEED;
	
	move_player(game_map, new_x, new_y);
}

/* Ejemplo de cómo mover al jugador hacia la derecha (strafe) */
void	move_right(t_game_map *game_map)
{
	double	new_x;
	double	new_y;

	new_x = game_map->player.x + cos(game_map->player.dir - M_PI/2) * MOVE_SPEED;
	new_y = game_map->player.y - sin(game_map->player.dir - M_PI/2) * MOVE_SPEED;
	
	move_player(game_map, new_x, new_y);
}