/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:45:13 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/22 17:46:47 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	key_limit(int keycode, t_mlx *splash)
{
	if (splash->selected == 0)
		if (keycode == 13)
			return (0);
	if (splash->selected >= 3)
		if (keycode == 1)
			return (0);
	if (keycode == 0 || keycode == 2)
	{
		if (splash->selected != 0)
			return (0);
		if (keycode == 2 && splash->map_selected >= 9)
			return (0);
		if (keycode == 0 && splash->map_selected <= 0)
			return (0);
	}
	return (1);
}

void	load_game(int selected, t_mlx *splash)
{
	if (selected == 0)
		run_game("maps/0.ber", splash->mlx, selected, splash->difficulty);
	if (selected == 1)
		run_game("maps/1.ber", splash->mlx, selected, splash->difficulty);
	if (selected == 2)
		run_game("maps/2.ber", splash->mlx, selected, splash->difficulty);
	if (selected == 3)
		run_game("maps/3.ber", splash->mlx, selected, splash->difficulty);
	if (selected == 4)
		run_game("maps/4.ber", splash->mlx, selected, splash->difficulty);
	if (selected == 5)
		run_game("maps/5.ber", splash->mlx, selected, splash->difficulty);
	if (selected == 6)
		run_game("maps/6.ber", splash->mlx, selected, splash->difficulty);
	if (selected == 7)
		run_game("maps/7.ber", splash->mlx, selected, splash->difficulty);
	if (selected == 8)
		run_game("maps/8.ber", splash->mlx, selected, splash->difficulty);
	if (selected == 9)
		run_game("maps/9.ber", splash->mlx, selected, splash->difficulty);
}

int	process_key_splash(int keycode, t_mlx *splash)
{
	if (key_limit(keycode, splash) == 0)
		return (0);
	if (keycode == 53)
		handle_close_event_splash(splash, 0);
	if (keycode == 0)
		splash->map_selected--;
	if (keycode == 2)
		splash->map_selected++;
	if (keycode == 1)
		splash->selected++;
	if (keycode == 13)
		splash->selected--;
	if (keycode == 36 && splash->selected == 1)
		splash->going_to_game = 1;
	if (keycode == 36 && splash->selected == 2)
	{
		handle_close_event_splash(splash, 1);
		run_options(splash->mlx, splash->difficulty);
	}
	if (keycode == 36 && splash->selected == 3)
		handle_close_event_splash(splash, 0);
	return (0);
}

int	keyboard_event_splash(int keycode, t_mlx *splash)
{
	process_key_splash(keycode, splash);
	return (0);
}
