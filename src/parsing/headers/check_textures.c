/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:43:49 by cgil              #+#    #+#             */
/*   Updated: 2025/11/09 14:43:51 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	assign_texture(char **target, char *path)
{
	if (*target)
		return (-1);
	*target = ft_strdup(path);
	if (!*target)
		return (-1);
	return (0);
}

static int	save_textures(t_config *cfg, char *coord, char *path)
{
	if (ft_strncmp(coord, "NO", 3) == 0)
		return (assign_texture(&cfg->tex_no, path));
	else if (ft_strncmp(coord, "SO", 3) == 0)
		return (assign_texture(&cfg->tex_so, path));
	else if (ft_strncmp(coord, "WE", 3) == 0)
		return (assign_texture(&cfg->tex_we, path));
	else if (ft_strncmp(coord, "EA", 3) == 0)
		return (assign_texture(&cfg->tex_ea, path));
	else
		return (-1);
}

int	check_texture(char *line, t_config *cfg)
{
	char	**split;
	int		fd;
	int		ret;

	split = ft_split(line, ' ');
	if (!split || !split[0] || !split[1] || split[2])
		return (free_split(split), -1);
	if (validate_file(split[1]) == -1)
	{
		return (free_and_error(split, "Error\nInvalid file extension"));
	}
	fd = open(split[1], O_RDONLY);
	if (fd < 0)
	{
		free_split(split);
		return (ft_print_error("Error\nTexture doesn't exist"));
	}
	close(fd);
	ret = save_textures(cfg, split[0], split[1]);
	free_split(split);
	if (ret == -1)
		return (free_and_error(NULL, "Error\nDuplicate texture identifier"));
	return ((ret));
}
