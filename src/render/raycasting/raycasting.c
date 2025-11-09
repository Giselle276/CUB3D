/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:48:44 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/29 12:16:44 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_perform_dda(t_game *game, t_dda *dda, int *side)
{
	int	hit;
	int	map_w;
	int	map_h;

	map_h = 0;
	while (game->cfg->map[map_h])
		map_h++;
	map_w = ft_strlen(game->cfg->map[0]);
	hit = 0;
	while (!hit)
	{
		step_ray(dda, side);
		if (dda->map_x < 0 || dda->map_x >= map_w
			|| dda->map_y < 0 || dda->map_y >= map_h)
			break ;
		check_hit(game, dda, &hit);
	}
}

t_ray	cast_single_ray(t_game *game, double ray_dir_x, double ray_dir_y)
{
	t_dda	dda;
	t_ray	ray;
	int		side;

	dda.map_x = (int)game->pos_x;
	dda.map_y = (int)game->pos_y;
	init_deltas(ray_dir_x, ray_dir_y, &dda.delta_x, &dda.delta_y);
	init_steps(game, ray_dir_x, ray_dir_y, &dda);
	ft_perform_dda(game, &dda, &side);
	if (side == 0)
		ray.perp_dist = (dda.map_x - game->pos_x + (1 - dda.step_x) / 2.0)
			/ ray_dir_x;
	else
		ray.perp_dist = (dda.map_y - game->pos_y + (1 - dda.step_y) / 2.0)
			/ ray_dir_y;
	if (ray.perp_dist < 0.0001)
		ray.perp_dist = 0.0001;
	ray.side_hit = side;
	return (ray);
}
