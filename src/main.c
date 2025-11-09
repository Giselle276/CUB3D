/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:33:22 by cgil              #+#    #+#             */
/*   Updated: 2025/10/30 10:23:52 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game		game;
	t_config	cfg;

	ft_bzero(&cfg, sizeof(t_config));
	ft_bzero(&game, sizeof(t_game));
	if (ac != 2)
		return (ft_print_error("Error\nUse as: ./cub3d <map.cub>"));
	if (validate_map(av[1]) == -1)
		return (-1);
	if (parse_cub(av[1], &cfg) == -1)
	{
		free_cfg(&cfg);
		return (-1);
	}
	if (init_game(&game, &cfg) == -1)
		return (-1);
	render_frame(&game);
	mlx_loop(game.mlx);
	free_cfg(&cfg);
	return (0);
}
