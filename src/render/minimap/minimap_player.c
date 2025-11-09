/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 02:16:39 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/29 12:46:25 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap_player(t_game *game, int cx, int cy)
{
	int	x;
	int	y;

	y = -PLAYER_SIZE / 2;
	while (y < PLAYER_SIZE / 2)
	{
		x = -PLAYER_SIZE / 2;
		while (x < PLAYER_SIZE / 2)
		{
			mini_put_pixel(&game->img, cx + x, cy + y, 0x39FF14);
			x++;
		}
		y++;
	}
}
