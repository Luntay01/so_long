/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:55:16 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/08 18:52:53 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	end_state(t_mlx *end, int win)
{
	int	i;

	i = 0;
	end->going_to_game = win;
	while (i < 3)
	{
		if (win == 0)
			end->gt[i] = end->pa[i];
		if (win == 1 && (end->difficulty / 10) == 1)
			end->gt[i] = end->ms[i];
		if (win == 1 && (end->difficulty / 10) == 2)
			end->gt[i] = end->ms[i + 3];
		if (win == 1 && (end->difficulty / 10) == 3)
			end->gt[i] = end->ms[i + 6];
		if (win == 1 && (end->difficulty / 10) == 4)
			end->gt[i] = end->ms[i + 9];
		i++;
	}
}

int	update_end(t_mlx *end)
{
	static int	animation_counter = 0;
	static int	animation_delay = 1300;
	void		*current_img;

	if (animation_counter % animation_delay == 0)
	{
		mlx_clear_window(end->mlx, end->win);
		current_img = end->gt[end->selected];
		mlx_put_image_to_window(end->mlx, end->win, current_img, 0, 0);
	}
	animation_counter++;
	return (0);
}

void	init_end(t_mlx *end, void *mlx, int map_selected, int difficulty)
{
	end->selected = 0;
	end->map_selected = map_selected;
	end->difficulty = difficulty;
	end->mlx = mlx;
	end->win = mlx_new_window(end->mlx, 1280, 768, "");
	end->current_frame = 0;
}

int	run_end(void *mlx, int map_selected, int win, int difficulty)
{
	t_mlx	end;

	init_end(&end, mlx, map_selected, difficulty);
	init_images_end(&end);
	end_state(&end, win);
	mlx_hook(end.win, 17, 0, handle_close_event_end, &end);
	mlx_hook(end.win, 2, 1l << 0, keyboard_event_end, &end);
	mlx_loop_hook(end.mlx, update_end, &end);
	mlx_loop(end.mlx);
	return (0);
}
