/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_mapfile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:17:54 by claudia           #+#    #+#             */
/*   Updated: 2025/10/30 10:28:31 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len <= 4)
		return (-1);
	if (ft_strncmp(filename + len - 4, ".cub", 4) == 0
		|| ft_strncmp(filename + len - 4, ".xpm", 4) == 0)
		return (0);
	return (-1);
}

int	check_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}

int	validate_map(char *map)
{
	if (validate_file(map) == -1)
		return (ft_print_error("Error\nFile must have .cub extension"));
	if (check_open(map) == -1)
		return (ft_print_error("Error:\nCould not open file"));
	return (0);
}
