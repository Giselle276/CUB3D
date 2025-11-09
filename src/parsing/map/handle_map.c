/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:14:40 by claudia           #+#    #+#             */
/*   Updated: 2025/10/30 10:37:27 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_map(char **lines, t_config *cfg, int map_start)
{
	if (validate_map_chars(lines + map_start) == -1)
		return (ft_print_error("Error\ninvalid chars found in map"));
	if (validate_single_player(lines + map_start, cfg) == -1)
		return (-1);
	if (count_map_size(lines + map_start, cfg) == -1)
		return (ft_print_error("Error\nEmpty map"));
	if (allocate_map(cfg) == -1)
		return (-1);
	if (fill_map(lines + map_start, cfg) == -1)
		return (-1);
	if (check_map(cfg) == -1)
		return (-1);
	return (0);
}
