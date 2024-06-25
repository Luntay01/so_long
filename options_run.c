/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:38:00 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/22 17:23:07 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	*options_state(t_mlx *options)
{
	void	*img;

	if (options->difficulty == 10)
		img = options->pa[options->selected];
	if (options->difficulty == 11)
		img = options->pa[options->selected + 3];
	if (options->difficulty == 20)
		img = options->pa[options->selected + 6];
	if (options->difficulty == 41)
		img = options->pa[options->selected + 9];
	if (options->difficulty == 21)
		img = options->gt[options->selected];
	if (options->difficulty == 30)
		img = options->gt[options->selected + 3];
	if (options->difficulty == 31)
		img = options->gt[options->selected + 6];
	if (options->difficulty == 40)
		img = options->gt[options->selected + 9];
	return (img);
}

int	update_options(t_mlx *options)
{
	static int	animation_counter = 0;
	static int	animation_delay = 1300;
	void		*current_img;

	if (animation_counter % animation_delay == 0)
	{
		mlx_clear_window(options->mlx, options->win);
		current_img = options_state(options);
		mlx_put_image_to_window(options->mlx, options->win, current_img, 0, 0);
	}
	animation_counter++;
	return (0);
}

void	init_options(t_mlx *options, void *mlx, int difficulty)
{
	options->selected = 0;
	options->map_selected = 0;
	options->difficulty = difficulty;
	if (difficulty == 1)
		options->difficulty = 10;
	options->param = (difficulty % 10);
	options->mlx = mlx;
	options->win = mlx_new_window(options->mlx, 1280, \
			768, "ANOTHER DAY! ANOTHER DOLLAR!");
	options->current_frame = 0;
}

int	run_options(void *mlx, int difficulty)
{
	t_mlx	options;

	init_options(&options, mlx, difficulty);
	init_images_options(&options);
	mlx_hook(options.win, 17, 0, handle_close_event_options, &options);
	mlx_hook(options.win, 2, 1l << 0, keyboard_event_options, &options);
	mlx_loop_hook(options.mlx, update_options, &options);
	mlx_loop(options.mlx);
	return (0);
}
