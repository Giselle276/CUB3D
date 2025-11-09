/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:59:05 by claudia           #+#    #+#             */
/*   Updated: 2025/10/25 11:34:26 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_and_error(char **lines, const char *msg)
{
	if (lines)
		free_split(lines);
	printf("%s\n", msg);
	return (-1);
}

int	ft_print_error(char *error)
{
	printf("%s\n", error);
	return (-1);
}

void	free_split(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_cfg(t_config *cfg)
{
	int	i;

	i = 0;
	if (cfg->tex_no)
		free(cfg->tex_no);
	if (cfg->tex_so)
		free(cfg->tex_so);
	if (cfg->tex_we)
		free(cfg->tex_we);
	if (cfg->tex_ea)
		free(cfg->tex_ea);
	if (cfg->map)
	{
		while (cfg->map[i])
		{
			free(cfg->map[i]);
			i++;
		}
		free(cfg->map);
	}
}
