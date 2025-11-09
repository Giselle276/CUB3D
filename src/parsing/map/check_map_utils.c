/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:57:59 by claudia           #+#    #+#             */
/*   Updated: 2025/10/21 18:28:52 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_up(char **map, int i, int j)
{
	int	x;

	x = i - 1;
	while (x >= 0 && j < (int)ft_strlen(map[x]))
	{
		if (map[x][j] == ' ')
			return (0);
		if (map[x][j] == '1')
			return (1);
		x--;
	}
	return (0);
}

int	check_down(char **map, int i, int j)
{
	int	x;

	x = i + 1;
	while (map[x] && j < (int)ft_strlen(map[x]))
	{
		if (map[x][j] == ' ')
			return (0);
		if (map[x][j] == '1')
			return (1);
		x++;
	}
	return (0);
}

int	check_left(char **map, int i, int j)
{
	int	y;

	y = j - 1;
	while (y >= 0)
	{
		if (map[i][y] == ' ')
			return (0);
		if (map[i][y] == '1')
			return (1);
		y--;
	}
	return (0);
}

int	check_right(char **map, int i, int j)
{
	int	y;

	y = j + 1;
	while (y < (int)ft_strlen(map[i]))
	{
		if (map[i][y] == ' ')
			return (0);
		if (map[i][y] == '1')
			return (1);
		y++;
	}
	return (0);
}
