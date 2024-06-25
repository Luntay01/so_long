/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:22:22 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/22 17:15:28 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	opt_images_1(t_mlx *options)
{
	int	w;
	int	h;

	options->gt[7] = xf(options->mlx, "s/os/31_music.xpm", &w, &h);
	options->gt[8] = xf(options->mlx, "s/os/31_main_menu.xpm", &w, &h);
	options->gt[9] = xf(options->mlx, "s/os/40_difficulty.xpm", &w, &h);
	options->gt[10] = xf(options->mlx, "s/os/40_music.xpm", &w, &h);
	options->gt[11] = xf(options->mlx, "s/os/40_main_menu.xpm", &w, &h);
	options->gt[12] = xf(options->mlx, "s/E/es_quit.xpm", &w, &h);
	options->gt[13] = xf(options->mlx, "s/E/es_quit.xpm", &w, &h);
	options->ms[0] = xf(options->mlx, "s/os/10_main_menu.xpm", &w, &h);
	options->ms[1] = xf(options->mlx, "s/os/11_main_menu.xpm", &w, &h);
	options->ms[2] = xf(options->mlx, "s/os/20_main_menu.xpm", &w, &h);
	options->ms[3] = xf(options->mlx, "s/os/21_main_menu.xpm", &w, &h);
	options->ms[4] = xf(options->mlx, "s/os/30_main_menu.xpm", &w, &h);
	options->ms[5] = xf(options->mlx, "s/os/31_main_menu.xpm", &w, &h);
	options->ms[6] = xf(options->mlx, "s/os/40_main_menu.xpm", &w, &h);
	options->ms[7] = xf(options->mlx, "s/os/41_main_menu.xpm", &w, &h);
	options->ms[8] = xf(options->mlx, "s/E/g_quit.xpm", &w, &h);
	options->ms[9] = xf(options->mlx, "s/E/i_level.xpm", &w, &h);
	options->ms[10] = xf(options->mlx, "s/E/i_menu.xpm", &w, &h);
	options->ms[11] = xf(options->mlx, "s/E/i_quit.xpm", &w, &h);
	options->ms[12] = xf(options->mlx, "s/E/i_menu.xpm", &w, &h);
	options->ms[13] = xf(options->mlx, "s/E/i_quit.xpm", &w, &h);
}

void	init_images_options(t_mlx *options)
{
	int	w;
	int	h;

	options->pa[0] = xf(options->mlx, "s/os/10_difficulty.xpm", &w, &h);
	options->pa[1] = xf(options->mlx, "s/os/10_music.xpm", &w, &h);
	options->pa[2] = xf(options->mlx, "s/os/10_main_menu.xpm", &w, &h);
	options->pa[3] = xf(options->mlx, "s/os/11_difficulty.xpm", &w, &h);
	options->pa[4] = xf(options->mlx, "s/os/11_music.xpm", &w, &h);
	options->pa[5] = xf(options->mlx, "s/os/11_main_menu.xpm", &w, &h);
	options->pa[6] = xf(options->mlx, "s/os/20_difficulty.xpm", &w, &h);
	options->pa[7] = xf(options->mlx, "s/os/20_music.xpm", &w, &h);
	options->pa[8] = xf(options->mlx, "s/os/20_main_menu.xpm", &w, &h);
	options->pa[9] = xf(options->mlx, "s/os/41_difficulty.xpm", &w, &h);
	options->pa[10] = xf(options->mlx, "s/os/41_music.xpm", &w, &h);
	options->pa[11] = xf(options->mlx, "s/os/41_main_menu.xpm", &w, &h);
	options->pa[12] = xf(options->mlx, "s/E/es_quit.xpm", &w, &h);
	options->pa[13] = xf(options->mlx, "s/E/es_quit.xpm", &w, &h);
	options->gt[0] = xf(options->mlx, "s/os/21_difficulty.xpm", &w, &h);
	options->gt[1] = xf(options->mlx, "s/os/21_music.xpm", &w, &h);
	options->gt[2] = xf(options->mlx, "s/os/21_main_menu.xpm", &w, &h);
	options->gt[3] = xf(options->mlx, "s/os/30_difficulty.xpm", &w, &h);
	options->gt[4] = xf(options->mlx, "s/os/30_music.xpm", &w, &h);
	options->gt[5] = xf(options->mlx, "s/os/30_main_menu.xpm", &w, &h);
	options->gt[6] = xf(options->mlx, "s/os/31_difficulty.xpm", &w, &h);
	opt_images_1(options);
}
