/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 02:15:09 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/29 18:18:11 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mini_put_pixel(t_img *img, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < WIN_W && y < WIN_H)
		put_pixel(img, x, y, color);
}

int	get_cell_color(t_game *game, int map_x, int map_y)
{
	char	cell;

	if (map_x < 0 || map_y < 0
		|| map_y >= game->cfg->map_height
		|| map_x >= game->cfg->map_width)
		return (0x05051A);
	cell = game->cfg->map[map_y][map_x];
	if (cell == '1')
		return (0x2F2545);
	if (cell == '0' || cell == ' ')
		return (0x7E7E7E);
	return (0x000000);
}
