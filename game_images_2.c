/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_images_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:46:04 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/08 18:30:46 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	game_images10(t_game *game)
{
	game->o_d = xf(game->mlx, "s/omd.xpm", &(game->w), &(game->h));
	game->par[0] = xf(game->mlx, "s/P/i1R.png.xpm", &(game->w), &(game->h));
	game->par[1] = xf(game->mlx, "s/P/i2R.png.xpm", &(game->w), &(game->h));
	game->par[2] = xf(game->mlx, "s/P/i3R.png.xpm", &(game->w), &(game->h));
	game->par[3] = xf(game->mlx, "s/P/i4R.png.xpm", &(game->w), &(game->h));
	game->pal[0] = xf(game->mlx, "s/P/i1L.png.xpm", &(game->w), &(game->h));
	game->pal[1] = xf(game->mlx, "s/P/i2L.png.xpm", &(game->w), &(game->h));
	game->pal[2] = xf(game->mlx, "s/P/i3L.png.xpm", &(game->w), &(game->h));
	game->pal[3] = xf(game->mlx, "s/P/i4L.png.xpm", &(game->w), &(game->h));
	game->p_a_r[0] = xf(game->mlx, "s/P/a1R.png.xpm", &(game->w), &(game->h));
	game->p_a_r[1] = xf(game->mlx, "s/P/a2R.png.xpm", &(game->w), &(game->h));
	game->p_a_r[2] = xf(game->mlx, "s/P/a3R.png.xpm", &(game->w), &(game->h));
	game->p_a_r[3] = xf(game->mlx, "s/P/a4R.png.xpm", &(game->w), &(game->h));
	game->p_a_r[4] = xf(game->mlx, "s/P/a5R.png.xpm", &(game->w), &(game->h));
	game->p_a_l[0] = xf(game->mlx, "s/P/a1L.png.xpm", &(game->w), &(game->h));
	game->p_a_l[1] = xf(game->mlx, "s/P/a2L.png.xpm", &(game->w), &(game->h));
	game->p_a_l[2] = xf(game->mlx, "s/P/a3L.png.xpm", &(game->w), &(game->h));
	game->p_a_l[3] = xf(game->mlx, "s/P/a4L.png.xpm", &(game->w), &(game->h));
	game->p_a_l[4] = xf(game->mlx, "s/P/a5L.png.xpm", &(game->w), &(game->h));
	game->e360[0] = xf(game->mlx, "s/sp/360/sp00.xpm", &(game->w), &(game->h));
	game->e360[1] = xf(game->mlx, "s/sp/360/sp01.xpm", &(game->w), &(game->h));
	game->e360[2] = xf(game->mlx, "s/sp/360/sp02.xpm", &(game->w), &(game->h));
	game->e360[3] = xf(game->mlx, "s/sp/360/sp03.xpm", &(game->w), &(game->h));
	game_images11(game);
}

void	game_images09(t_game *game)
{
	game->e22[0] = xf(game->mlx, "s/sp/22/sp04.xpm", &(game->w), &(game->h));
	game->e22[1] = xf(game->mlx, "s/sp/22/sp05.xpm", &(game->w), &(game->h));
	game->e22[2] = xf(game->mlx, "s/sp/22/sp06.xpm", &(game->w), &(game->h));
	game->e22[3] = xf(game->mlx, "s/sp/22/sp07.xpm", &(game->w), &(game->h));
	game->e45[0] = xf(game->mlx, "s/sp/45/sp08.xpm", &(game->w), &(game->h));
	game->e45[1] = xf(game->mlx, "s/sp/45/sp09.xpm", &(game->w), &(game->h));
	game->e45[2] = xf(game->mlx, "s/sp/45/sp10.xpm", &(game->w), &(game->h));
	game->e45[3] = xf(game->mlx, "s/sp/45/sp11.xpm", &(game->w), &(game->h));
	game->e67[0] = xf(game->mlx, "s/sp/67/sp12.xpm", &(game->w), &(game->h));
	game->e67[1] = xf(game->mlx, "s/sp/67/sp13.xpm", &(game->w), &(game->h));
	game->e67[2] = xf(game->mlx, "s/sp/67/sp14.xpm", &(game->w), &(game->h));
	game->e67[3] = xf(game->mlx, "s/sp/67/sp15.xpm", &(game->w), &(game->h));
	game->e90[0] = xf(game->mlx, "s/sp/90/sp16.xpm", &(game->w), &(game->h));
	game->e90[1] = xf(game->mlx, "s/sp/90/sp17.xpm", &(game->w), &(game->h));
	game->e90[2] = xf(game->mlx, "s/sp/90/sp18.xpm", &(game->w), &(game->h));
	game->e90[3] = xf(game->mlx, "s/sp/90/sp19.xpm", &(game->w), &(game->h));
	game->e112[0] = xf(game->mlx, "s/sp/112/sp20.xpm", &(game->w), &(game->h));
	game->e112[1] = xf(game->mlx, "s/sp/112/sp21.xpm", &(game->w), &(game->h));
	game->e112[2] = xf(game->mlx, "s/sp/112/sp22.xpm", &(game->w), &(game->h));
	game->e112[3] = xf(game->mlx, "s/sp/112/sp23.xpm", &(game->w), &(game->h));
	game->e135[0] = xf(game->mlx, "s/sp/135/sp24.xpm", &(game->w), &(game->h));
	game->e135[1] = xf(game->mlx, "s/sp/135/sp25.xpm", &(game->w), &(game->h));
	game->e135[2] = xf(game->mlx, "s/sp/135/sp26.xpm", &(game->w), &(game->h));
	game->e135[3] = xf(game->mlx, "s/sp/135/sp27.xpm", &(game->w), &(game->h));
	game_images10(game);
}

void	game_images08(t_game *game)
{
	game->e157[0] = xf(game->mlx, "s/sp/157/sp28.xpm", &(game->w), &(game->h));
	game->e157[1] = xf(game->mlx, "s/sp/157/sp29.xpm", &(game->w), &(game->h));
	game->e157[2] = xf(game->mlx, "s/sp/157/sp30.xpm", &(game->w), &(game->h));
	game->e157[3] = xf(game->mlx, "s/sp/157/sp31.xpm", &(game->w), &(game->h));
	game->e180[0] = xf(game->mlx, "s/sp/180/sp32.xpm", &(game->w), &(game->h));
	game->e180[1] = xf(game->mlx, "s/sp/180/sp33.xpm", &(game->w), &(game->h));
	game->e180[2] = xf(game->mlx, "s/sp/180/sp34.xpm", &(game->w), &(game->h));
	game->e180[3] = xf(game->mlx, "s/sp/180/sp35.xpm", &(game->w), &(game->h));
	game->e202[0] = xf(game->mlx, "s/sp/202/sp36.xpm", &(game->w), &(game->h));
	game->e202[1] = xf(game->mlx, "s/sp/202/sp37.xpm", &(game->w), &(game->h));
	game->e202[2] = xf(game->mlx, "s/sp/202/sp38.xpm", &(game->w), &(game->h));
	game->e202[3] = xf(game->mlx, "s/sp/202/sp39.xpm", &(game->w), &(game->h));
	game->e225[0] = xf(game->mlx, "s/sp/225/sp40.xpm", &(game->w), &(game->h));
	game->e225[1] = xf(game->mlx, "s/sp/225/sp41.xpm", &(game->w), &(game->h));
	game->e225[2] = xf(game->mlx, "s/sp/225/sp42.xpm", &(game->w), &(game->h));
	game->e225[3] = xf(game->mlx, "s/sp/225/sp43.xpm", &(game->w), &(game->h));
	game->e247[0] = xf(game->mlx, "s/sp/247/sp44.xpm", &(game->w), &(game->h));
	game->e247[1] = xf(game->mlx, "s/sp/247/sp45.xpm", &(game->w), &(game->h));
	game->e247[2] = xf(game->mlx, "s/sp/247/sp46.xpm", &(game->w), &(game->h));
	game->e247[3] = xf(game->mlx, "s/sp/247/sp47.xpm", &(game->w), &(game->h));
	game->e270[0] = xf(game->mlx, "s/sp/270/sp48.xpm", &(game->w), &(game->h));
	game->e270[1] = xf(game->mlx, "s/sp/270/sp49.xpm", &(game->w), &(game->h));
	game->e270[2] = xf(game->mlx, "s/sp/270/sp50.xpm", &(game->w), &(game->h));
	game->e270[3] = xf(game->mlx, "s/sp/270/sp51.xpm", &(game->w), &(game->h));
	game_images09(game);
}

void	game_images07(t_game *game)
{
	game->e292[0] = xf(game->mlx, "s/sp/292/sp52.xpm", &(game->w), &(game->h));
	game->e292[1] = xf(game->mlx, "s/sp/292/sp53.xpm", &(game->w), &(game->h));
	game->e292[2] = xf(game->mlx, "s/sp/292/sp54.xpm", &(game->w), &(game->h));
	game->e292[3] = xf(game->mlx, "s/sp/292/sp55.xpm", &(game->w), &(game->h));
	game->e315[0] = xf(game->mlx, "s/sp/315/sp56.xpm", &(game->w), &(game->h));
	game->e315[1] = xf(game->mlx, "s/sp/315/sp57.xpm", &(game->w), &(game->h));
	game->e315[2] = xf(game->mlx, "s/sp/315/sp58.xpm", &(game->w), &(game->h));
	game->e315[3] = xf(game->mlx, "s/sp/315/sp59.xpm", &(game->w), &(game->h));
	game->e337[0] = xf(game->mlx, "s/sp/337/sp60.xpm", &(game->w), &(game->h));
	game->e337[1] = xf(game->mlx, "s/sp/337/sp61.xpm", &(game->w), &(game->h));
	game->e337[2] = xf(game->mlx, "s/sp/337/sp62.xpm", &(game->w), &(game->h));
	game->e337[3] = xf(game->mlx, "s/sp/337/sp63.xpm", &(game->w), &(game->h));
	game->o_a[0] = xf(game->mlx, "s/om/m000.xpm", &(game->w), &(game->h));
	game->o_a[1] = xf(game->mlx, "s/om/m001.xpm", &(game->w), &(game->h));
	game->o_a[2] = xf(game->mlx, "s/om/m002.xpm", &(game->w), &(game->h));
	game->o_a[3] = xf(game->mlx, "s/om/m003.xpm", &(game->w), &(game->h));
	game->o_a[4] = xf(game->mlx, "s/om/m004.xpm", &(game->w), &(game->h));
	game->o_a[5] = xf(game->mlx, "s/om/m005.xpm", &(game->w), &(game->h));
	game->o_a[6] = xf(game->mlx, "s/om/m006.xpm", &(game->w), &(game->h));
	game->o_a[7] = xf(game->mlx, "s/om/m007.xpm", &(game->w), &(game->h));
	game->o_a[8] = xf(game->mlx, "s/om/m008.xpm", &(game->w), &(game->h));
	game->o_a[9] = xf(game->mlx, "s/om/m009.xpm", &(game->w), &(game->h));
	game->o_a[10] = xf(game->mlx, "s/om/m010.xpm", &(game->w), &(game->h));
	game->o_a[11] = xf(game->mlx, "s/om/m011.xpm", &(game->w), &(game->h));
	game_images08(game);
}

void	game_images06(t_game *game)
{
	game->o_a[12] = xf(game->mlx, "s/om/m012.xpm", &(game->w), &(game->h));
	game->o_a[13] = xf(game->mlx, "s/om/m013.xpm", &(game->w), &(game->h));
	game->o_a[14] = xf(game->mlx, "s/om/m014.xpm", &(game->w), &(game->h));
	game->o_a[15] = xf(game->mlx, "s/om/m015.xpm", &(game->w), &(game->h));
	game->o_a[16] = xf(game->mlx, "s/om/m016.xpm", &(game->w), &(game->h));
	game->o_a[17] = xf(game->mlx, "s/om/m017.xpm", &(game->w), &(game->h));
	game->o_a[18] = xf(game->mlx, "s/om/m018.xpm", &(game->w), &(game->h));
	game->o_a[19] = xf(game->mlx, "s/om/m019.xpm", &(game->w), &(game->h));
	game->o_a[20] = xf(game->mlx, "s/om/m020.xpm", &(game->w), &(game->h));
	game->o_a[21] = xf(game->mlx, "s/om/m021.xpm", &(game->w), &(game->h));
	game->o_a[22] = xf(game->mlx, "s/om/m022.xpm", &(game->w), &(game->h));
	game->o_a[23] = xf(game->mlx, "s/om/m023.xpm", &(game->w), &(game->h));
	game->o_a[24] = xf(game->mlx, "s/om/m024.xpm", &(game->w), &(game->h));
	game->o_a[25] = xf(game->mlx, "s/om/m025.xpm", &(game->w), &(game->h));
	game->o_a[26] = xf(game->mlx, "s/om/m026.xpm", &(game->w), &(game->h));
	game->o_a[27] = xf(game->mlx, "s/om/m027.xpm", &(game->w), &(game->h));
	game->o_a[28] = xf(game->mlx, "s/om/m028.xpm", &(game->w), &(game->h));
	game->o_a[29] = xf(game->mlx, "s/om/m029.xpm", &(game->w), &(game->h));
	game->o_a[30] = xf(game->mlx, "s/om/m030.xpm", &(game->w), &(game->h));
	game->o_a[31] = xf(game->mlx, "s/om/m031.xpm", &(game->w), &(game->h));
	game->o_a[32] = xf(game->mlx, "s/om/m032.xpm", &(game->w), &(game->h));
	game->o_a[33] = xf(game->mlx, "s/om/m033.xpm", &(game->w), &(game->h));
	game->o_a[34] = xf(game->mlx, "s/om/m034.xpm", &(game->w), &(game->h));
	game->o_a[35] = xf(game->mlx, "s/om/m035.xpm", &(game->w), &(game->h));
	game_images07(game);
}
