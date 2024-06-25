/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:48:29 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/22 17:42:18 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	init_splash(t_mlx *splash, void *mlx, int difficulty)
{
	splash->selected = 0;
	splash->map_selected = 0;
	splash->going_to_game = 0;
	splash->trans = 0;
	splash->mlx = mlx;
	splash->win = mlx_new_window(splash->mlx, 1280, \
			768, "ANOTHER DAY! ANOTHER DOLLAR!");
	splash->current_frame = 0;
	splash->difficulty = difficulty;
}

int	run_splash(void *mlx, int difficulty)
{
	t_mlx	splash;

	init_splash(&splash, mlx, difficulty);
	init_images(&splash);
	mlx_put_image_to_window(splash.mlx, splash.win, splash.img_splash, 0, 0);
	mlx_hook(splash.win, 17, 0, handle_close_event_splash, &splash);
	mlx_hook(splash.win, 2, 1l << 0, keyboard_event_splash, &splash);
	mlx_loop_hook(splash.mlx, update_splash, &splash);
	mlx_loop(splash.mlx);
	return (0);
}
