/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:37:19 by cgil              #+#    #+#             */
/*   Updated: 2025/10/25 13:37:21 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	set_player_if_found(char c, int i, int j, t_config *cfg)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		cfg->player_y = i;
		cfg->player_x = j;
		cfg->player_dir = c;
		return (1);
	}
	return (0);
}

int	validate_single_player(char **lines, t_config *cfg)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			player += set_player_if_found(lines[i][j], i, j, cfg);
			if (player > 1)
				return (ft_print_error("Error: more than one player found"));
			j++;
		}
		i++;
	}
	if (player < 1)
		return (ft_print_error("Error: no player found"));
	else if (player > 1)
		return (ft_print_error("Error: more than one player found"));
	return (0);
}

int	validate_map_chars(char **map_lines)
{
	int	i;
	int	j;

	i = 0;
	while (map_lines[i])
	{
		j = 0;
		while (map_lines[i][j])
		{
			if (map_lines[i][j] != '0' && map_lines[i][j] != '1' &&
				map_lines[i][j] != 'N' && map_lines[i][j] != 'S' &&
				map_lines[i][j] != 'W' && map_lines[i][j] != 'E' &&
				map_lines[i][j] != ' ' && map_lines[i][j] != '\t')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	count_map_size(char **lines, t_config *cfg)
{
	int	i;
	int	len;

	if (!lines || !cfg)
		return (-1);
	i = 0;
	cfg->map_width = 0;
	cfg->map_height = 0;
	while (lines[i])
	{
		len = 0;
		while (lines[i][len])
			len++;
		if (len > cfg->map_width)
			cfg->map_width = len;
		cfg->map_height++;
		i++;
	}
	if (cfg->map_height == 0 || cfg->map_width == 0)
		return (-1);
	return (0);
}
