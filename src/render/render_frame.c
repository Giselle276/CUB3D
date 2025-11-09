/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:08:18 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/26 00:55:37 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_scene_column(t_game *g, int x)
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	t_ray		ray;
	t_raydir	dir;

	camera_x = 2 * x / (double)WIN_W - 1;
	ray_dir_x = g->dir_x + g->plane_x * camera_x;
	ray_dir_y = g->dir_y + g->plane_y * camera_x;
	ray = cast_single_ray(g, ray_dir_x, ray_dir_y);
	dir.x = ray_dir_x;
	dir.y = ray_dir_y;
	draw_column(g, &ray, x, dir);
}

void	render_frame(t_game *g)
{
	int	color_c;
	int	color_f;
	int	x;

	color_c = (g->cfg->ceiling_rgb[0] << 16)
		| (g->cfg->ceiling_rgb[1] << 8)
		| g->cfg->ceiling_rgb[2];
	color_f = (g->cfg->floor_rgb[0] << 16)
		| (g->cfg->floor_rgb[1] << 8)
		| g->cfg->floor_rgb[2];
	draw_background(&g->img, color_c, color_f);
	x = 0;
	while (x < WIN_W)
	{
		draw_scene_column(g, x);
		x++;
	}
	draw_minimap(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
}
