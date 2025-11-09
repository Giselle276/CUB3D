/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:47:09 by claudia           #+#    #+#             */
/*   Updated: 2025/10/27 15:01:18 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_player(char player)
{
	if (player == 'N' || player == 'S' || player == 'W' || player == 'E')
		return (1);
	return (0);
}

static int	is_surrounded(char **map, int i, int j)
{
	if (!check_up(map, i, j))
		return (0);
	if (!check_down(map, i, j))
		return (0);
	if (!check_left(map, i, j))
		return (0);
	if (!check_right(map, i, j))
		return (0);
	return (1);
}

int	check_map(t_config *cfg)
{
	int	i;
	int	j;

	i = 0;
	while (cfg->map[i])
	{
		j = 0;
		while (cfg->map[i][j])
		{
			if (cfg->map[i][j] == '0' || is_player(cfg->map[i][j]))
			{
				if (!is_surrounded(cfg->map, i, j))
					return (ft_print_error("Error\nMap not closed or with "
							"invalid spaces"));
			}
			j++;
		}
		i++;
	}
	return (1);
}
