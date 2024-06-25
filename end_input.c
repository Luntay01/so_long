/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:52:16 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/23 19:45:25 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	key_limit_end(int keycode, t_mlx *end)
{
	if (end->selected == 0)
		if (keycode == 13)
			return (0);
	if (end->selected >= 2)
		if (keycode == 1)
			return (0);
	return (1);
}

void	load_game_from_end(int selected, t_mlx *end)
{
	if (selected == 0)
		run_game("maps/0.ber", end->mlx, 0, end->difficulty);
	if (selected == 1)
		run_game("maps/1.ber", end->mlx, 1, end->difficulty);
	if (selected == 2)
		run_game("maps/2.ber", end->mlx, 2, end->difficulty);
	if (selected == 3)
		run_game("maps/3.ber", end->mlx, 3, end->difficulty);
	if (selected == 4)
		run_game("maps/4.ber", end->mlx, 4, end->difficulty);
	if (selected == 5)
		run_game("maps/5.ber", end->mlx, 5, end->difficulty);
	if (selected == 6)
		run_game("maps/6.ber", end->mlx, 6, end->difficulty);
	if (selected == 7)
		run_game("maps/7.ber", end->mlx, 7, end->difficulty);
	if (selected == 8)
		run_game("maps/8.ber", end->mlx, 8, end->difficulty);
	if (selected == 9)
		run_game("maps/9.ber", end->mlx, 9, end->difficulty);
}

void	finished_end(t_mlx *end)
{
	if (end->map_selected >= 9)
	{
		write(1, "YOU ARE THE CHAMPION\n", 21);
		handle_close_event_end(end, 0);
	}
	else
	{
		handle_close_event_end(end, 1);
		load_game_from_end(end->map_selected + end->going_to_game, end);
	}
}

int	process_key_end(int keycode, t_mlx *end)
{
	if (key_limit_end(keycode, end) == 0)
		return (0);
	if (keycode == 53)
		handle_close_event_end(end, 0);
	if (keycode == 1)
		end->selected++;
	if (keycode == 13)
		end->selected--;
	if (keycode == 36 && end->selected == 0)
		finished_end(end);
	if (keycode == 36 && end->selected == 1)
	{
		handle_close_event_end(end, 1);
		run_splash(end->mlx, end->difficulty);
	}
	if (keycode == 36 && end->selected == 2)
		handle_close_event_end(end, 0);
	return (0);
}

int	keyboard_event_end(int keycode, t_mlx *end)
{
	process_key_end(keycode, end);
	return (0);
}
