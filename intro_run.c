/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:21:34 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/23 19:47:03 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_intro_memory(t_mlx *intro)
{
	int	i;

	i = 0;
	mlx_destroy_image(intro->mlx, intro->img_splash);
	while (i < 47)
	{
		mlx_destroy_image(intro->mlx, intro->pl[i]);
		if (i > 32)
			mlx_destroy_image(intro->mlx, intro->pa[i]);
		i++;
	}
}

int	handle_close_event_intro(t_mlx *intro)
{
	intro->param = 1;
	mlx_destroy_window(intro->mlx, intro->win);
	return (0);
}

int	keyboard_event_intro(int keycode, t_mlx *intro)
{
	keycode = 0;
	handle_close_event_intro(intro);
	run_splash(intro->mlx, 1);
	return (keycode);
}

void	run_intro(void *mlx)
{
	t_mlx	intro;
	int		loop_status;

	loop_status = 1;
	intro.mlx = mlx;
	init_images_intro(&intro);
	intro.win = mlx_new_window(intro.mlx, 1280, 768, \
			"ANOTHER DAY! ANOTHER DOLLAR!");
	while (loop_status)
	{
		mlx_hook(intro.win, 17, 0, handle_close_event_intro, &intro);
		mlx_hook(intro.win, 2, 1l << 0, keyboard_event_intro, &intro);
		mlx_loop_hook(intro.mlx, update_intro, &intro);
		mlx_loop(intro.mlx);
		if (intro.param == 1)
			loop_status = 0;
	}
	handle_intro_memory(&intro);
}
