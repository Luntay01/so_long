/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:01:32 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/22 15:35:45 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	player_dead(t_game *game)
{
	handle_close_event_game(game, 1);
	run_end(game->mlx, game->map_nbr, 0, game->difficulty);
}

void	touch_player1(t_game *game)
{
	if ((game->enemy[game->e_i].pos_y - game->map[game->pp].pos_y) < 70 && \
		(game->enemy[game->e_i].pos_y - game->map[game->pp].pos_y) > 0)
		player_dead(game);
	if ((game->enemy[game->e_i].pos_y - game->map[game->pp].pos_y) > -70 && \
		(game->enemy[game->e_i].pos_y - game->map[game->pp].pos_y) < 0)
		player_dead(game);
}

void	touch_player2(t_game *game)
{
	if ((game->enemy[game->e_i].pos_y - game->map[game->pp].pos_y) < 70 && \
		(game->enemy[game->e_i].pos_y - game->map[game->pp].pos_y) > 0)
		player_dead(game);
	if ((game->enemy[game->e_i].pos_y - game->map[game->pp].pos_y) > -70 && \
		(game->enemy[game->e_i].pos_y - game->map[game->pp].pos_y) < 0)
		player_dead(game);
}

void	update_enemies_pos(t_game *game)
{
	game->e_i = 0;
	game->speed = 2.0f * (game->difficulty / 10);
	while (game->e_i < game->num_enemies)
	{
		game->angle = c_angle(game->enemy[game->e_i].pos_x, \
				game->enemy[game->e_i].pos_y, \
				game->map[game->pp].pos_x, game->map[game->pp].pos_y);
		game->enemy[game->e_i].pos_x += game->speed
			* cos(game->angle * M_PI / 180.0f);
		game->enemy[game->e_i].pos_y += game->speed
			* sin(game->angle * M_PI / 180.0f);
		game->enemy[game->e_i].rotation = game->angle;
		if ((game->enemy[game->e_i].pos_x - game->map[game->pp].pos_x) < 70 && \
				(game->enemy[game->e_i].pos_x - game->map[game->pp].pos_x) > 0)
		{
			touch_player1(game);
		}
		if ((game->enemy[game->e_i].pos_x - game->map[game->pp].pos_x) > -70 && \
				(game->enemy[game->e_i].pos_x - game->map[game->pp].pos_x) < 0)
		{
			touch_player2(game);
		}
		game->e_i++;
	}
}

void	update_enemies(t_game *game)
{
	int	i;

	i = 0;
	if (game->num_enemies < 1)
		return ;
	update_enemies_pos(game);
	while (i < game->num_enemies)
	{
		game->enemy[i].current_frame = (game->enemy[i].current_frame + 1) % 4;
		i++;
	}
	render_enemies(game);
}
