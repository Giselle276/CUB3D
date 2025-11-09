/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_headers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:45:14 by cgil              #+#    #+#             */
/*   Updated: 2025/11/09 14:45:20 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_map_line(char *line)
{
	int	j;

	j = 0;
	while (line[j] == ' ')
		j++;
	return (line[j] == '1' || line[j] == '0');
}

static int	is_texture_line(char *line)
{
	while (*line == ' ')
		line++;
	if (!ft_strncmp(line, "NO", 2) && line[2] == ' ')
		return (1);
	if (!ft_strncmp(line, "SO", 2) && line[2] == ' ')
		return (1);
	if (!ft_strncmp(line, "WE", 2) && line[2] == ' ')
		return (1);
	if (!ft_strncmp(line, "EA", 2) && line[2] == ' ')
		return (1);
	return (0);
}

static int	is_color_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if ((*line == 'F' || *line == 'C')
		&& (line[1] == ' ' || line[1] == '\t'))
		return (1);
	return (0);
}

int	handle_headers(char **lines, t_config *cfg, int *map_start)
{
	int	i;
	int	headers;

	i = 0;
	headers = 0;
	*map_start = -1;
	while (lines[i])
	{
		if (is_map_line(lines[i]))
		{
			*map_start = i;
			break ;
		}
		else if (check_headers(lines[i], cfg, &headers) == -1)
			return (-1);
		i++;
	}
	if (headers != 6)
		return (ft_print_error("Error\nInvalid headers"));
	if (*map_start == -1)
		return (ft_print_error("Error\nNo map found"));
	return (0);
}

int	check_headers(char *line, t_config *cfg, int *headers)
{
	if (is_texture_line(line))
	{
		if (check_texture(line, cfg) == -1)
			return (-1);
		(*headers)++;
	}
	else if (is_color_line(line))
	{
		if (check_color(line, cfg) == -1)
			return (-1);
		(*headers)++;
	}
	else
		return (ft_print_error("Error: Invalid Identifier"));
	return (0);
}
