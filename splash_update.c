/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:32:50 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/22 17:42:55 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	update_menu_anim(t_mlx *splash)
{
	void	*map_nbr_img;
	void	*menu_img;

	map_nbr_img = splash->ms[splash->map_selected];
	menu_img = splash->ms[splash->selected + 10];
	if (splash->selected == 0)
	{
		mlx_put_image_to_window(splash->mlx, splash->win, menu_img, 0, 0);
		mlx_put_image_to_window(splash->mlx, splash->win, map_nbr_img, 0, 0);
	}
	else
		mlx_put_image_to_window(splash->mlx, splash->win, menu_img, 0, 0);
}

void	game_load(t_mlx *splash)
{
	handle_close_event_splash(splash, 1);
	load_game(splash->map_selected, splash);
}

void	splash_state(t_mlx *splash)
{
	void	*current_img;

	if (splash->going_to_game == 0)
	{
		mlx_put_image_to_window(splash->mlx, splash->win, \
				splash->img_splash, 0, 0);
		update_menu_anim(splash);
		current_img = splash->pa[splash->current_frame];
		splash->current_frame = (splash->current_frame + 1) % 14;
		mlx_put_image_to_window(splash->mlx, splash->win, current_img, 0, 0);
	}
	else
	{
		mlx_put_image_to_window(splash->mlx, splash->win, \
				splash->gt[splash->trans], 0, 0);
		splash->trans++;
		if (splash->trans > 14)
			game_load(splash);
	}
}

int	update_splash(t_mlx *splash)
{
	static int	animation_counter = 0;
	static int	animation_delay = 1300;

	if (animation_counter % animation_delay == 0)
	{
		splash_state(splash);
	}
	animation_counter++;
	return (0);
}
