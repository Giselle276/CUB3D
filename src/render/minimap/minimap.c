/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:58:58 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/24 02:18:56 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_game *game)
{
	int	offset_x;
	int	offset_y;
	int	center_x;
	int	center_y;

	offset_x = 30;
	offset_y = WIN_H - MINIMAP_SIZE - 30;
	center_x = offset_x + MINIMAP_RADIUS;
	center_y = offset_y + MINIMAP_RADIUS;
	draw_minimap_circle(game, center_x, center_y);
	draw_minimap_player(game, center_x, center_y);
	draw_minimap_dir(game, center_x, center_y);
}
