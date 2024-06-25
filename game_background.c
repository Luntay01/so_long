/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:08:26 by kmordaun          #+#    #+#             */
/*   Updated: 2023/09/14 14:36:07 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	activate_enemy(t_game *game, int pos)
{
	int		new_max_enemies;
	int		i;
	t_enemy	*new_enemy;

	i = -1;
	if (game->num_enemies == game->max_enemies)
	{
		new_max_enemies = game->max_enemies + 10;
		new_enemy = (t_enemy *)malloc(new_max_enemies * sizeof(t_enemy));
		if (!new_enemy)
			return ;
		while (++i < game->num_enemies)
			new_enemy[i] = game->enemy[i];
		free(game->enemy);
		game->enemy = new_enemy;
		game->max_enemies = new_max_enemies;
	}
	game->enemy[game->num_enemies].pos_x = game->map[pos].pos_x;
	game->enemy[game->num_enemies].pos_y = game->map[pos].pos_y;
	game->enemy[game->num_enemies].rotation = 0.0f;
	game->enemy[game->num_enemies].current_frame = 0;
	game->num_enemies++;
}

void	update_old(t_game *game, int i)
{
	void	*img;

	img = game->b_e[game->becoming_frame];
	game->becoming_frame = (game->becoming_frame + 1) % 25;
	mlx_put_image_to_window(game->mlx, game->win,
		game->o_d, game->map[i].pos_x, game->map[i].pos_y);
	mlx_put_image_to_window(game->mlx, game->win, img,
		game->map[i].pos_x, game->map[i].pos_y);
	if (game->becoming_frame == 24)
	{
		game->map[i].tile = '0';
		game->becoming_frame = 0;
		activate_enemy(game, i);
	}
}

void	put_background(t_game *game)
{
	int			i;
	void		*img;
	static int	old_anim_counter;

	old_anim_counter = 0;
	i = 0;
	while (i < (game->map_width * game->map_height))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->map[i].img,
			game->map[i].pos_x, game->map[i].pos_y);
		if (game->map[i].tile == 'c')
			update_old(game, i);
		if (game->map[i].tile == 'C')
		{
			if (old_anim_counter % 11 == 0)
			{
				img = game->o_a[game->old_man_frame];
				game->old_man_frame = (game->old_man_frame + 1) % 122;
			}
			mlx_put_image_to_window(game->mlx, game->win, img,
				game->map[i].pos_x, game->map[i].pos_y);
		}
		i++;
	}
}
