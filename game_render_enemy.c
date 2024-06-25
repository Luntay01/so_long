/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_enemy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:06:23 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/22 15:37:32 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	*angled_enemies2(t_game *game, int index)
{
	if (index == 12)
		return (game->e180);
	if (index == 13)
		return (game->e202);
	if (index == 14)
		return (game->e225);
	if (index == 15)
		return (game->e247);
	return (NULL);
}

void	*angled_enemies(t_game *game, int index)
{
	if (index == 0)
		return (game->e270);
	if (index == 1)
		return (game->e292);
	if (index == 2)
		return (game->e315);
	if (index == 3)
		return (game->e337);
	if (index == 4)
		return (game->e360);
	if (index == 5)
		return (game->e22);
	if (index == 6)
		return (game->e45);
	if (index == 7)
		return (game->e67);
	if (index == 8)
		return (game->e90);
	if (index == 9)
		return (game->e112);
	if (index == 10)
		return (game->e135);
	if (index == 11)
		return (game->e157);
	return (angled_enemies2(game, index));
}

void	render_enemies(t_game *game)
{
	int		i;
	int		index;
	float	rotation;
	int		f;
	void	*enemy_images[16];

	f = 4;
	i = 0;
	while (i < 16)
	{
		enemy_images[i] = angled_enemies(game, i);
		i++;
	}
	i = 0;
	while (i < game->num_enemies)
	{
		rotation = game->enemy[i].rotation;
		index = ((int)((rotation + 11.25f) / 22.5f)) % 16;
		mlx_put_image_to_window(game->mlx, game->win,
			((void**)(enemy_images[index]))[game->enemy[i].current_frame % f],
			game->enemy[i].pos_x, game->enemy[i].pos_y);
		i++;
	}
}
