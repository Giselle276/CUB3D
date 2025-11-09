/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:30:24 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/29 12:16:12 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_tex_num(t_ray *ray, double ray_dir_x, double ray_dir_y)
{
	if (ray->side_hit == 0)
	{
		if (ray_dir_x > 0)
			return (0);
		return (1);
	}
	if (ray_dir_y > 0)
		return (2);
	return (3);
}

int	clamp_tex_coord(int value, int max)
{
	if (value < 0)
		return (0);
	if (value >= max)
		return (max - 1);
	return (value);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_W || y >= WIN_H)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
