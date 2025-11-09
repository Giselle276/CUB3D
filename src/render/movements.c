/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:37:37 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/29 18:39:12 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->pos_x + game->dir_x * MOVE_SPEED;
	new_y = game->pos_y + game->dir_y * MOVE_SPEED;
	if (is_valid_cell(game, new_x, game->pos_y))
		game->pos_x = new_x;
	if (is_valid_cell(game, game->pos_x, new_y))
		game->pos_y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->pos_x - game->dir_x * MOVE_SPEED;
	new_y = game->pos_y - game->dir_y * MOVE_SPEED;
	if (is_valid_cell(game, new_x, game->pos_y))
		game->pos_x = new_x;
	if (is_valid_cell(game, game->pos_x, new_y))
		game->pos_y = new_y;
}

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir_x;
	old_plane_x = game->plane_x;
	game->dir_x = game->dir_x * cos(-ROT_SPEED) - game->dir_y * sin(-ROT_SPEED);
	game->dir_y = old_dir_x * sin(-ROT_SPEED) + game->dir_y * cos(-ROT_SPEED);
	game->plane_x = game->plane_x * cos(-ROT_SPEED)
		- game->plane_y * sin(-ROT_SPEED);
	game->plane_y = old_plane_x * sin(-ROT_SPEED)
		+ game->plane_y * cos(-ROT_SPEED);
}

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir_x;
	old_plane_x = game->plane_x;
	game->dir_x = game->dir_x * cos(ROT_SPEED) - game->dir_y * sin(ROT_SPEED);
	game->dir_y = old_dir_x * sin(ROT_SPEED) + game->dir_y * cos(ROT_SPEED);
	game->plane_x = game->plane_x * cos(ROT_SPEED)
		- game->plane_y * sin(ROT_SPEED);
	game->plane_y = old_plane_x * sin(ROT_SPEED)
		+ game->plane_y * cos(ROT_SPEED);
}
