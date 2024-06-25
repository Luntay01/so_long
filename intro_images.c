/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:13:32 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/08 18:35:35 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images_3(t_mlx *intro)
{
	int	w;
	int	h;

	intro->pl[42] = xf(intro->mlx, "s/i/i42.xpm", &w, &h);
	intro->pl[43] = xf(intro->mlx, "s/i/i43.xpm", &w, &h);
	intro->pl[44] = xf(intro->mlx, "s/i/i44.xpm", &w, &h);
	intro->pl[45] = xf(intro->mlx, "s/i/i45.xpm", &w, &h);
	intro->pl[46] = xf(intro->mlx, "s/i/i46.xpm", &w, &h);
}

void	images_2(t_mlx *intro)
{
	int	w;
	int	h;

	intro->pl[21] = xf(intro->mlx, "s/i/i21.xpm", &w, &h);
	intro->pl[22] = xf(intro->mlx, "s/i/i22.xpm", &w, &h);
	intro->pl[23] = xf(intro->mlx, "s/i/i23.xpm", &w, &h);
	intro->pl[24] = xf(intro->mlx, "s/i/i24.xpm", &w, &h);
	intro->pl[25] = xf(intro->mlx, "s/i/i25.xpm", &w, &h);
	intro->pl[26] = xf(intro->mlx, "s/i/i26.xpm", &w, &h);
	intro->pl[27] = xf(intro->mlx, "s/i/i27.xpm", &w, &h);
	intro->pl[28] = xf(intro->mlx, "s/i/i28.xpm", &w, &h);
	intro->pl[29] = xf(intro->mlx, "s/i/i29.xpm", &w, &h);
	intro->pl[30] = xf(intro->mlx, "s/i/i30.xpm", &w, &h);
	intro->pl[31] = xf(intro->mlx, "s/i/i31.xpm", &w, &h);
	intro->pl[32] = xf(intro->mlx, "s/i/i32.xpm", &w, &h);
	intro->pl[33] = xf(intro->mlx, "s/i/i33.xpm", &w, &h);
	intro->pl[34] = xf(intro->mlx, "s/i/i34.xpm", &w, &h);
	intro->pl[35] = xf(intro->mlx, "s/i/i35.xpm", &w, &h);
	intro->pl[36] = xf(intro->mlx, "s/i/i36.xpm", &w, &h);
	intro->pl[37] = xf(intro->mlx, "s/i/i37.xpm", &w, &h);
	intro->pl[38] = xf(intro->mlx, "s/i/i38.xpm", &w, &h);
	intro->pl[39] = xf(intro->mlx, "s/i/i39.xpm", &w, &h);
	intro->pl[40] = xf(intro->mlx, "s/i/i40.xpm", &w, &h);
	intro->pl[41] = xf(intro->mlx, "s/i/i41.xpm", &w, &h);
	images_3(intro);
}

void	images_1(t_mlx *intro)
{
	int	w;
	int	h;

	intro->pl[0] = xf(intro->mlx, "s/i/i00.xpm", &w, &h);
	intro->pl[1] = xf(intro->mlx, "s/i/i01.xpm", &w, &h);
	intro->pl[2] = xf(intro->mlx, "s/i/i02.xpm", &w, &h);
	intro->pl[3] = xf(intro->mlx, "s/i/i03.xpm", &w, &h);
	intro->pl[4] = xf(intro->mlx, "s/i/i04.xpm", &w, &h);
	intro->pl[5] = xf(intro->mlx, "s/i/i05.xpm", &w, &h);
	intro->pl[6] = xf(intro->mlx, "s/i/i06.xpm", &w, &h);
	intro->pl[7] = xf(intro->mlx, "s/i/i07.xpm", &w, &h);
	intro->pl[8] = xf(intro->mlx, "s/i/i08.xpm", &w, &h);
	intro->pl[9] = xf(intro->mlx, "s/i/i09.xpm", &w, &h);
	intro->pl[10] = xf(intro->mlx, "s/i/i10.xpm", &w, &h);
	intro->pl[11] = xf(intro->mlx, "s/i/i11.xpm", &w, &h);
	intro->pl[12] = xf(intro->mlx, "s/i/i12.xpm", &w, &h);
	intro->pl[13] = xf(intro->mlx, "s/i/i13.xpm", &w, &h);
	intro->pl[14] = xf(intro->mlx, "s/i/i14.xpm", &w, &h);
	intro->pl[15] = xf(intro->mlx, "s/i/i15.xpm", &w, &h);
	intro->pl[16] = xf(intro->mlx, "s/i/i16.xpm", &w, &h);
	intro->pl[17] = xf(intro->mlx, "s/i/i17.xpm", &w, &h);
	intro->pl[18] = xf(intro->mlx, "s/i/i18.xpm", &w, &h);
	intro->pl[19] = xf(intro->mlx, "s/i/i19.xpm", &w, &h);
	intro->pl[20] = xf(intro->mlx, "s/i/i20.xpm", &w, &h);
	images_2(intro);
}

void	init_images_intro(t_mlx *intro)
{
	int	w;
	int	h;

	intro->img_splash = xf(intro->mlx, "s/omd.xpm", &w, &h);
	intro->pa[0] = xf(intro->mlx, "s/om/m016.xpm", &w, &h);
	intro->pa[1] = xf(intro->mlx, "s/om/m017.xpm", &w, &h);
	intro->pa[2] = xf(intro->mlx, "s/om/m018.xpm", &w, &h);
	intro->pa[3] = xf(intro->mlx, "s/om/m019.xpm", &w, &h);
	intro->pa[4] = xf(intro->mlx, "s/om/m020.xpm", &w, &h);
	intro->pa[5] = xf(intro->mlx, "s/om/m021.xpm", &w, &h);
	intro->pa[6] = xf(intro->mlx, "s/om/m022.xpm", &w, &h);
	intro->pa[7] = xf(intro->mlx, "s/om/m023.xpm", &w, &h);
	intro->pa[8] = xf(intro->mlx, "s/om/m024.xpm", &w, &h);
	intro->pa[9] = xf(intro->mlx, "s/om/m025.xpm", &w, &h);
	intro->pa[10] = xf(intro->mlx, "s/om/m026.xpm", &w, &h);
	intro->pa[11] = xf(intro->mlx, "s/om/m027.xpm", &w, &h);
	intro->pa[12] = xf(intro->mlx, "s/om/m028.xpm", &w, &h);
	intro->pa[13] = xf(intro->mlx, "s/om/m029.xpm", &w, &h);
	intro->selected = 100;
	intro->current_frame = 0;
	intro->going_to_game = 0;
	images_1(intro);
}
