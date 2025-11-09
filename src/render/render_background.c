/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:29:52 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/25 18:38:29 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_half(t_img *img, int color, int start_y, int end_y)
{
	int	x;
	int	y;

	y = start_y;
	while (y < end_y)
	{
		x = 0;
		while (x < WIN_W)
		{
			put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_background(t_img *img, int ceiling, int floor)
{
	draw_half(img, ceiling, 0, WIN_H / 2);
	draw_half(img, floor, WIN_H / 2, WIN_H);
}
