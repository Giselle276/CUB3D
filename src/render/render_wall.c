/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:30:46 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/26 00:46:46 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_tex_line(t_game *game, int x, t_drawinfo *d)
{
	int		y;
	int		tex_y;
	int		distance;
	char	*pixel;
	int		color;

	y = d->draw_start;
	while (y < d->draw_end)
	{
		distance = y * 256 - WIN_H * 128 + d->line_height * 128;
		tex_y = (distance * game->tex[d->tex_num].height)
			/ d->line_height / 256;
		tex_y = clamp_tex_coord(tex_y, game->tex[d->tex_num].height);
		pixel = game->tex[d->tex_num].addr
			+ (tex_y * game->tex[d->tex_num].line_len
				+ d->tex_x * (game->tex[d->tex_num].bpp / 8));
		color = *(int *)pixel;
		put_pixel(&game->img, x, y, color);
		y++;
	}
}

static void	draw_wall_texture(t_game *game, int x, t_drawinfo *d)
{
	d->wall_x -= floor(d->wall_x);
	d->tex_x = (int)(d->wall_x * (double)game->tex[d->tex_num].width);
	d->tex_x = clamp_tex_coord(d->tex_x, game->tex[d->tex_num].width);
	draw_tex_line(game, x, d);
}

void	draw_column(t_game *game, t_ray *ray, int x, t_raydir dir)
{
	t_drawinfo	d;

	d.line_height = (int)(WIN_H / ray->perp_dist);
	if (d.line_height > WIN_H * 10)
		d.line_height = WIN_H * 10;
	d.draw_start = -d.line_height / 2 + WIN_H / 2;
	if (d.draw_start < 0)
		d.draw_start = 0;
	d.draw_end = d.line_height / 2 + WIN_H / 2;
	if (d.draw_end >= WIN_H)
		d.draw_end = WIN_H - 1;
	if (ray->side_hit == 0)
		d.wall_x = game->pos_y + ray->perp_dist * dir.y;
	else
		d.wall_x = game->pos_x + ray->perp_dist * dir.x;
	d.tex_num = get_tex_num(ray, dir.x, dir.y);
	draw_wall_texture(game, x, &d);
}
