/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:34:58 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/22 20:07:25 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	handle_options_memory(t_mlx *options)
{
	int	i;

	i = 0;
	while (i < 14)
	{
		mlx_destroy_image(options->mlx, options->pa[i]);
		mlx_destroy_image(options->mlx, options->gt[i]);
		mlx_destroy_image(options->mlx, options->ms[i]);
		i++;
	}
}

int	handle_close_event_options(t_mlx *options, int screen)
{
	handle_options_memory(options);
	mlx_destroy_window(options->mlx, options->win);
	if (screen == 1)
		return (0);
	exit(0);
}

int	key_limit_options(int keycode, t_mlx *options)
{
	if (options->selected == 0)
		if (keycode == 13)
			return (0);
	if (options->selected >= 2)
		if (keycode == 1)
			return (0);
	if (keycode == 0 || keycode == 2)
	{
		if (options->selected != 0 && options->selected != 1)
			return (0);
		if (options->selected == 0 && keycode == 2 && \
				(options->difficulty / 10) >= 4)
			return (0);
		if (options->selected == 0 && keycode == 0 && \
				(options->difficulty / 10) <= 1)
			return (0);
		if (options->selected == 1 && keycode == 2 && \
				(options->difficulty % 10) >= 1)
			return (0);
		if (options->selected == 1 && keycode == 0 && \
				(options->difficulty % 10) <= 0)
			return (0);
	}
	return (1);
}

int	process_key_options(int keycode, t_mlx *options)
{
	if (key_limit_options(keycode, options) == 0)
		return (0);
	if (keycode == 53)
		handle_close_event_options(options, 0);
	if (keycode == 0 && options->selected == 0)
		options->difficulty -= 10;
	if (keycode == 2 && options->selected == 0)
		options->difficulty += 10;
	if (keycode == 0 && options->selected == 1)
		options->difficulty--;
	if (keycode == 2 && options->selected == 1)
		options->difficulty++;
	if (keycode == 1)
		options->selected++;
	if (keycode == 13)
		options->selected--;
	if (keycode == 36 && options->selected == 2)
	{
		handle_close_event_options(options, 1);
		run_splash(options->mlx, options->difficulty);
	}
	return (0);
}

int	keyboard_event_options(int keycode, t_mlx *options)
{
	process_key_options(keycode, options);
	return (0);
}
