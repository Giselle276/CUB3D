/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 02:17:30 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/29 12:47:54 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_dir_vars(t_game *game, int cx, int cy, t_line *l)
{
	l->end_x = cx + (int)(game->dir_x * 15);
	l->end_y = cy + (int)(game->dir_y * 15);
	l->dx = abs(l->end_x - cx);
	l->dy = abs(l->end_y - cy);
	l->sx = -1;
	l->sy = -1;
	if (cx < l->end_x)
		l->sx = 1;
	if (cy < l->end_y)
		l->sy = 1;
	l->err = l->dx - l->dy;
}

void	draw_minimap_dir(t_game *game, int cx, int cy)
{
	t_line	l;
	int		e2;

	init_dir_vars(game, cx, cy, &l);
	while (1)
	{
		mini_put_pixel(&game->img, cx, cy, 0x39FF14);
		if (cx == l.end_x && cy == l.end_y)
			break ;
		e2 = 2 * l.err;
		if (e2 > -l.dy)
		{
			l.err -= l.dy;
			cx += l.sx;
		}
		if (e2 < l.dx)
		{
			l.err += l.dx;
			cy += l.sy;
		}
	}
}
