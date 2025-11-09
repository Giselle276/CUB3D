/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:44:28 by cgil              #+#    #+#             */
/*   Updated: 2025/11/09 14:44:30 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	save_color(char id, t_config *cfg, int rgb[3])
{
	int	i;

	i = 0;
	if (id == 'F')
	{
		while (i < 3)
		{
			cfg->floor_rgb[i] = rgb[i];
			i++;
		}
	}
	else if (id == 'C')
	{
		while (i < 3)
		{
			cfg->ceiling_rgb[i] = rgb[i];
			i++;
		}
	}
	else
		return (ft_print_error("Error: Invalid color identifier"));
	return (0);
}

static int	validate_rgb_range(int rgb[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (ft_print_error("Error: RGB out of range"));
		i++;
	}
	return (0);
}

static int	is_valid_number(char *s)
{
	int	i;
	int	has_digit;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == ' ')
		i++;
	has_digit = 0;
	while (s[i] && ft_isdigit(s[i]))
	{
		has_digit = 1;
		i++;
	}
	if (!has_digit)
		return (0);
	while (s[i] == ' ')
		i++;
	if (s[i] != '\0')
		return (0);
	return (1);
}

static int	parse_color_line(char *line, int rgb[3])
{
	char	**split;
	int		i;

	i = 0;
	line++;
	while (*line == ' ')
		line++;
	split = ft_split(line, ',');
	if (!split)
		return (ft_print_error("Error: malloc failed"));
	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		return (free_and_error(split, "Error: Invalid RGB format" ));
	i = 0;
	while (i < 3)
	{
		if (!is_valid_number(split[i]))
			return (free_and_error(split, "Error: Invalid RGB value"));
		rgb[i] = ft_atoi(split[i]);
		i++;
	}
	free_split(split);
	return (0);
}

int	check_color(char *line, t_config *cfg)
{
	char	id;
	int		rgb[3];

	id = *line;
	if (parse_color_line(line, rgb) == -1)
		return (-1);
	if (validate_rgb_range(rgb) == -1)
		return (-1);
	if (save_color(id, cfg, rgb) == -1)
		return (-1);
	return (0);
}
