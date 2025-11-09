/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:15:12 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/29 12:18:29 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_dir_values(t_game *game, t_dir_vals values)
{
	game->dir_x = values.dir_x;
	game->dir_y = values.dir_y;
	game->plane_x = values.plane_x;
	game->plane_y = values.plane_y;
}

void	set_player_direction(t_game *game, char dir)
{
	t_dir_vals	values;

	if (dir == 'N')
		values = (t_dir_vals){0, -1, 0.66, 0};
	else if (dir == 'S')
		values = (t_dir_vals){0, 1, -0.66, 0};
	else if (dir == 'E')
		values = (t_dir_vals){1, 0, 0, 0.66};
	else if (dir == 'W')
		values = (t_dir_vals){-1, 0, 0, -0.66};
	else
	{
		values.dir_x = 0;
		values.dir_y = 0;
		values.plane_x = 0;
		values.plane_y = 0;
	}
	set_player_dir_values(game, values);
}

static int	load_single_texture(t_game *game, int index, char *path)
{
	game->tex[index].img = mlx_xpm_file_to_image(game->mlx, path,
			&game->tex[index].width, &game->tex[index].height);
	if (!game->tex[index].img)
		return (ft_print_error("Error: texture load failed"));
	game->tex[index].addr = mlx_get_data_addr(game->tex[index].img,
			&game->tex[index].bpp,
			&game->tex[index].line_len,
			&game->tex[index].endian);
	return (0);
}

int	load_textures(t_game *game)
{
	t_config	*cfg;
	int			i;
	char		*paths[4];

	cfg = game->cfg;
	paths[0] = cfg->tex_no;
	paths[1] = cfg->tex_so;
	paths[2] = cfg->tex_we;
	paths[3] = cfg->tex_ea;
	i = 0;
	while (i < 4)
	{
		if (load_single_texture(game, i, paths[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	init_game(t_game *game, t_config *cfg)
{
	game->cfg = cfg;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_print_error("Error\nMlx init failed"));
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "Cub3D");
	if (!game->win)
		return (ft_print_error("Error\nWindow creation failed"));
	game->img.img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bits_per_pixel, &game->img.line_length,
			&game->img.endian);
	game->pos_x = cfg->player_x;
	game->pos_y = cfg->player_y;
	set_player_direction(game, cfg->player_dir);
	mlx_hook(game->win, KeyPress, KeyPressMask, handle_key_press, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, handle_key_release, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, ft_update, game);
	if (load_textures(game) == -1)
		return (-1);
	return (0);
}
