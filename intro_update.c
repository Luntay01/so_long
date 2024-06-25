/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:26:08 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/22 16:55:49 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	plot_to_screen(t_mlx *intro)
{
	if (intro->going_to_game < 188)
	{
		mlx_put_image_to_window(intro->mlx, intro->win, \
				intro->pl[intro->going_to_game / 4], 0, 0);
		intro->going_to_game++;
	}
	else
		mlx_put_image_to_window(intro->mlx, intro->win, intro->pl[46], 0, 0);
}

int	update_intro(t_mlx *intro)
{
	static int	animation_counter = 0;
	static int	animation_delay = 1200;
	void		*current_img;

	if (animation_counter % animation_delay == 0)
	{
		mlx_clear_window(intro->mlx, intro->win);
		plot_to_screen(intro);
		current_img = intro->pa[intro->current_frame];
		if (intro->selected < 1100)
		{
			intro->current_frame = (intro->current_frame + 1) % 5;
			mlx_put_image_to_window(intro->mlx, intro->win, \
					current_img, intro->selected, 600);
			intro->selected += 5;
			if (intro->current_frame > 3)
				intro->selected -= 5;
		}
		else
			mlx_put_image_to_window(intro->mlx, intro->win, \
					intro->img_splash, intro->selected, 600);
	}
	animation_counter++;
	return (0);
}
