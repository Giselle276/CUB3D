/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:24:34 by cgil              #+#    #+#             */
/*   Updated: 2025/10/25 14:29:41 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_cell(t_game *game, double x, double y)
{
	int		map_x;
	int		map_y;
	char	cell;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0
		|| map_y >= game->cfg->map_height
		|| map_x >= game->cfg->map_width)
		return (0);
	cell = game->cfg->map[map_y][map_x];
	if (cell == '1' || cell == 'D')
		return (0);
	return (1);
}

void	strafe_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->pos_x - game->plane_x * MOVE_SPEED;
	new_y = game->pos_y - game->plane_y * MOVE_SPEED;
	if (is_valid_cell(game, new_x, game->pos_y))
		game->pos_x = new_x;
	if (is_valid_cell(game, game->pos_x, new_y))
		game->pos_y = new_y;
}

void	strafe_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->pos_x + game->plane_x * MOVE_SPEED;
	new_y = game->pos_y + game->plane_y * MOVE_SPEED;
	if (is_valid_cell(game, new_x, game->pos_y))
		game->pos_x = new_x;
	if (is_valid_cell(game, game->pos_x, new_y))
		game->pos_y = new_y;
}
