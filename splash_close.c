/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:40:13 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/08 16:11:36 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	handle_splash_memory(t_mlx *splash)
{
	int	i;

	i = 0;
	mlx_destroy_image(splash->mlx, splash->img_splash);
	while (i < 14)
	{
		mlx_destroy_image(splash->mlx, splash->pa[i]);
		mlx_destroy_image(splash->mlx, splash->ms[i]);
		i++;
	}
}

int	handle_close_event_splash(t_mlx *splash, int screen)
{
	handle_splash_memory(splash);
	mlx_destroy_window(splash->mlx, splash->win);
	if (screen == 1)
		return (0);
	exit(0);
}
