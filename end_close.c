/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:46:34 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/08 14:49:20 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	handle_end_memory(t_mlx *end)
{
	int	i;

	i = 0;
	while (i < 14)
	{
		mlx_destroy_image(end->mlx, end->pa[i]);
		if (i > 2)
			mlx_destroy_image(end->mlx, end->gt[i]);
		mlx_destroy_image(end->mlx, end->ms[i]);
		i++;
	}
}

int	handle_close_event_end(t_mlx *end, int screen)
{
	handle_end_memory(end);
	mlx_destroy_window(end->mlx, end->win);
	if (screen == 1)
		return (0);
	exit(0);
}
