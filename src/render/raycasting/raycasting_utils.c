/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 01:53:13 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/29 12:14:21 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_deltas(double ray_dir_x, double ray_dir_y,
						double *delta_x, double *delta_y)
{
	if (fabs(ray_dir_x) < 1e-6)
		ray_dir_x = 1e-6;
	if (fabs(ray_dir_y) < 1e-6)
		ray_dir_y = 1e-6;
	if (ray_dir_x == 0)
		*delta_x = 1e30;
	else
		*delta_x = fabs(1 / ray_dir_x);
	if (ray_dir_y == 0)
		*delta_y = 1e30;
	else
		*delta_y = fabs(1 / ray_dir_y);
}

void	init_steps(t_game *game, double ray_dir_x, double ray_dir_y,
						t_dda *dda)
{
	if (ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_x = (game->pos_x - dda->map_x) * dda->delta_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_x = (dda->map_x + 1.0 - game->pos_x) * dda->delta_x;
	}
	if (ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_y = (game->pos_y - dda->map_y) * dda->delta_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_y = (dda->map_y + 1.0 - game->pos_y) * dda->delta_y;
	}
}

void	step_ray(t_dda *dda, int *side)
{
	if (dda->side_x < dda->side_y)
	{
		dda->side_x += dda->delta_x;
		dda->map_x += dda->step_x;
		*side = 0;
	}
	else
	{
		dda->side_y += dda->delta_y;
		dda->map_y += dda->step_y;
		*side = 1;
	}
}

int	check_hit(t_game *game, t_dda *dda, int *hit)
{
	char	cell;

	cell = game->cfg->map[dda->map_y][dda->map_x];
	if (cell == '1')
	{
		*hit = 1;
		return (1);
	}
	return (0);
}
