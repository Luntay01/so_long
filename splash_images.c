/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:23:46 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/22 17:24:48 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	init_transition_images(t_mlx *splash)
{
	int	w;
	int	h;

	splash->gt[0] = xf(splash->mlx, "s/tr/transitions_00.xpm", &w, &h);
	splash->gt[1] = xf(splash->mlx, "s/tr/transitions_01.xpm", &w, &h);
	splash->gt[2] = xf(splash->mlx, "s/tr/transitions_02.xpm", &w, &h);
	splash->gt[3] = xf(splash->mlx, "s/tr/transitions_03.xpm", &w, &h);
	splash->gt[4] = xf(splash->mlx, "s/tr/transitions_04.xpm", &w, &h);
	splash->gt[5] = xf(splash->mlx, "s/tr/transitions_05.xpm", &w, &h);
	splash->gt[6] = xf(splash->mlx, "s/tr/transitions_06.xpm", &w, &h);
	splash->gt[7] = xf(splash->mlx, "s/tr/transitions_07.xpm", &w, &h);
	splash->gt[8] = xf(splash->mlx, "s/tr/transitions_08.xpm", &w, &h);
	splash->gt[9] = xf(splash->mlx, "s/tr/transitions_08.xpm", &w, &h);
	splash->gt[10] = xf(splash->mlx, "s/tr/transitions_08.xpm", &w, &h);
	splash->gt[11] = xf(splash->mlx, "s/tr/transitions_08.xpm", &w, &h);
	splash->gt[12] = xf(splash->mlx, "s/tr/transitions_08.xpm", &w, &h);
	splash->gt[13] = xf(splash->mlx, "s/tr/transitions_08.xpm", &w, &h);
}

void	init_menu_images(t_mlx *splash)
{
	int	w;
	int	h;

	splash->ms[0] = xf(splash->mlx, "s/menu/m0.xpm", &w, &h);
	splash->ms[1] = xf(splash->mlx, "s/menu/m1.xpm", &w, &h);
	splash->ms[2] = xf(splash->mlx, "s/menu/m2.xpm", &w, &h);
	splash->ms[3] = xf(splash->mlx, "s/menu/m3.xpm", &w, &h);
	splash->ms[4] = xf(splash->mlx, "s/menu/m4.xpm", &w, &h);
	splash->ms[5] = xf(splash->mlx, "s/menu/m5.xpm", &w, &h);
	splash->ms[6] = xf(splash->mlx, "s/menu/m6.xpm", &w, &h);
	splash->ms[7] = xf(splash->mlx, "s/menu/m7.xpm", &w, &h);
	splash->ms[8] = xf(splash->mlx, "s/menu/m8.xpm", &w, &h);
	splash->ms[9] = xf(splash->mlx, "s/menu/m9.xpm", &w, &h);
	splash->ms[10] = xf(splash->mlx, "s/menu/mmap.xpm", &w, &h);
	splash->ms[11] = xf(splash->mlx, "s/menu/mstart.xpm", &w, &h);
	splash->ms[12] = xf(splash->mlx, "s/menu/moptions.xpm", &w, &h);
	splash->ms[13] = xf(splash->mlx, "s/menu/mquit.xpm", &w, &h);
	init_transition_images(splash);
}

void	init_images(t_mlx *splash)
{
	int	w;
	int	h;

	splash->img_splash = xf(splash->mlx, "s/splash.xpm", &w, &h);
	splash->pa[0] = xf(splash->mlx, "s/pa/pfl01.xpm", &w, &h);
	splash->pa[1] = xf(splash->mlx, "s/pa/pfl02.xpm", &w, &h);
	splash->pa[2] = xf(splash->mlx, "s/pa/pfl03.xpm", &w, &h);
	splash->pa[3] = xf(splash->mlx, "s/pa/pfl04.xpm", &w, &h);
	splash->pa[4] = xf(splash->mlx, "s/pa/pfl05.xpm", &w, &h);
	splash->pa[5] = xf(splash->mlx, "s/pa/pfl06.xpm", &w, &h);
	splash->pa[6] = xf(splash->mlx, "s/pa/pfl07.xpm", &w, &h);
	splash->pa[7] = xf(splash->mlx, "s/pa/pfl08.xpm", &w, &h);
	splash->pa[8] = xf(splash->mlx, "s/pa/pfl09.xpm", &w, &h);
	splash->pa[9] = xf(splash->mlx, "s/pa/pfl10.xpm", &w, &h);
	splash->pa[10] = xf(splash->mlx, "s/pa/pfl11.xpm", &w, &h);
	splash->pa[11] = xf(splash->mlx, "s/pa/pfl12.xpm", &w, &h);
	splash->pa[12] = xf(splash->mlx, "s/pa/pfl13.xpm", &w, &h);
	splash->pa[13] = xf(splash->mlx, "s/pa/pfl14.xpm", &w, &h);
	init_menu_images(splash);
}
