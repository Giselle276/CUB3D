/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:03:00 by claudia           #+#    #+#             */
/*   Updated: 2025/10/22 11:24:32 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rm_empty_lines(char **lines);

int	parse_cub(char *map, t_config *cfg)
{
	char	**lines;
	int		map_start;

	lines = read_all_lines(map);
	if (!lines)
		return (free_and_error(NULL, "Error\nincorrect map\n"));
	rm_empty_lines(lines);
	if (handle_headers(lines, cfg, &map_start) == -1)
	{
		free_split(lines);
		return (-1);
	}
	if (handle_map(lines, cfg, map_start) == -1)
	{
		free_split(lines);
		return (-1);
	}
	free_split(lines);
	return (0);
}

static int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static void	rm_empty_lines(char **lines)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (lines[i])
	{
		if (!is_line_empty(lines[i]))
			lines[j++] = lines[i];
		else
			free(lines[i]);
		i++;
	}
	lines[j] = NULL;
}

static int	count_lines(const char *file)
{
	int		fd;
	int		cont;
	char	*line;

	cont = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		cont++;
		line = get_next_line(fd);
	}
	close(fd);
	return (cont);
}

char	**read_all_lines(char *map)
{
	int		fd;
	int		i;
	char	*line;
	char	**lines;
	int		len;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = malloc(sizeof(char *) * (count_lines(map) + 1));
	if (!lines)
		return (close(fd), NULL);
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len && line[len - 1] == '\n')
			line[len - 1] = '\0';
		lines[i++] = line;
		line = get_next_line(fd);
	}
	lines[i] = NULL;
	close(fd);
	return (lines);
}
