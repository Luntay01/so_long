/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:52:16 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/08 18:43:25 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	end_images_1(t_mlx *end)
{
	int	w;
	int	h;

	end->gt[7] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->gt[8] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->gt[9] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->gt[10] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->gt[11] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->gt[12] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->gt[13] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->ms[0] = xf(end->mlx, "s/E/ps_level.xpm", &w, &h);
	end->ms[1] = xf(end->mlx, "s/E/ps_menu.xpm", &w, &h);
	end->ms[2] = xf(end->mlx, "s/E/ps_quit.xpm", &w, &h);
	end->ms[3] = xf(end->mlx, "s/E/pa_level.xpm", &w, &h);
	end->ms[4] = xf(end->mlx, "s/E/pa_menu.xpm", &w, &h);
	end->ms[5] = xf(end->mlx, "s/E/pa_quit.xpm", &w, &h);
	end->ms[6] = xf(end->mlx, "s/E/g_level.xpm", &w, &h);
	end->ms[7] = xf(end->mlx, "s/E/g_menu.xpm", &w, &h);
	end->ms[8] = xf(end->mlx, "s/E/g_quit.xpm", &w, &h);
	end->ms[9] = xf(end->mlx, "s/E/i_level.xpm", &w, &h);
	end->ms[10] = xf(end->mlx, "s/E/i_menu.xpm", &w, &h);
	end->ms[11] = xf(end->mlx, "s/E/i_quit.xpm", &w, &h);
	end->ms[12] = xf(end->mlx, "s/E/i_menu.xpm", &w, &h);
	end->ms[13] = xf(end->mlx, "s/E/i_quit.xpm", &w, &h);
}

void	init_images_end(t_mlx *end)
{
	int	w;
	int	h;

	end->pa[0] = xf(end->mlx, "s/E/es_again.xpm", &w, &h);
	end->pa[1] = xf(end->mlx, "s/E/es_menu.xpm", &w, &h);
	end->pa[2] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->pa[3] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->pa[4] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->pa[5] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->pa[6] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->pa[7] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->pa[8] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->pa[9] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->pa[10] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->pa[11] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->pa[12] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->pa[13] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->gt[0] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->gt[1] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->gt[2] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->gt[3] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->gt[4] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->gt[5] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end->gt[6] = xf(end->mlx, "s/E/es_quit.xpm", &w, &h);
	end_images_1(end);
}
