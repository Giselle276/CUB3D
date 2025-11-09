/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 02:16:11 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/24 02:23:55 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_circle_pixel(t_game *game, t_point c, t_point p)
{
	double	world_x;
	double	world_y;
	int		map_x;
	int		map_y;
	int		color;

	world_x = game->pos_x + (double)p.x / TILE_SIZE;
	world_y = game->pos_y + (double)p.y / TILE_SIZE;
	map_x = (int)world_x;
	map_y = (int)world_y;
	color = get_cell_color(game, map_x, map_y);
	mini_put_pixel(&game->img, c.x + p.x, c.y + p.y, color);
}

void	draw_minimap_circle(t_game *game, int cx, int cy)
{
	t_point	c;
	t_point	p;

	c.x = cx;
	c.y = cy;
	p.y = -MINIMAP_RADIUS;
	while (p.y < MINIMAP_RADIUS)
	{
		p.x = -MINIMAP_RADIUS;
		while (p.x < MINIMAP_RADIUS)
		{
			if ((p.x * p.x + p.y * p.y) < (MINIMAP_RADIUS * MINIMAP_RADIUS))
				draw_circle_pixel(game, c, p);
			p.x++;
		}
		p.y++;
	}
}
