/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:59:49 by claudia           #+#    #+#             */
/*   Updated: 2025/10/25 13:33:15 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*allocate_row(int width)
{
	int		j;
	char	*row;

	row = malloc(width + 1);
	if (!row)
		return (NULL);
	j = 0;
	while (j < width)
	{
		row[j] = ' ';
		j++;
	}
	row[width] = '\0';
	return (row);
}

static void	free_map_partial(char **map, int rows)
{
	while (rows-- > 0)
		free(map[rows]);
	free(map);
}

int	allocate_map(t_config *cfg)
{
	int	i;

	if (!cfg || cfg->map_height <= 0 || cfg->map_width <= 0)
		return (-1);
	cfg->map = malloc(sizeof(char *) * (cfg->map_height + 1));
	if (!cfg->map)
		return (-1);
	i = 0;
	while (i < cfg->map_height)
	{
		cfg->map[i] = allocate_row(cfg->map_width);
		if (!cfg->map[i])
		{
			free_map_partial(cfg->map, i);
			cfg->map = NULL;
			return (-1);
		}
		i++;
	}
	cfg->map[cfg->map_height] = NULL;
	return (0);
}

int	fill_map(char **map_lines, t_config *cfg)
{
	int	i;
	int	j;

	if (!cfg || !cfg->map || !map_lines)
		return (-1);
	i = 0;
	while (i < cfg->map_height && map_lines[i])
	{
		j = 0;
		while (map_lines[i][j] && j < cfg->map_width)
		{
			cfg->map[i][j] = map_lines[i][j];
			j++;
		}
		i++;
	}
	cfg->map[i] = NULL;
	return (0);
}
