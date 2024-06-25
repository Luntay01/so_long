/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:55:17 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/22 15:41:32 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	wall_here(int keycode, t_game *game)
{
	if (keycode == 2)
	{
		if (game->map[game->pp + 1].tile == '1')
		{
			game->facing_r = 1;
			return (0);
		}
	}
	if (keycode == 0)
	{
		if (game->map[game->pp - 1].tile == '1')
		{
			game->facing_r = 0;
			return (0);
		}
	}
	if (keycode == 1)
		if (game->map[game->pp + game->map_width].tile == '1')
			return (0);
	if (keycode == 13)
		if (game->map[game->pp - game->map_width].tile == '1')
			return (0);
	return (1);
}

void	handle_collectable(t_game *game)
{
	game->old_men--;
	game->attack_on = 1;
	game->map[game->pp].tile = 'c';
}

void	handle_end(t_game *game)
{
	if (game->old_men > 0)
		return ;
	game->win_game = 1;
	game->current_frame = 0;
}

int	process_key_game(int keycode, t_game *game)
{
	if (wall_here(keycode, game) == 0)
		return (0);
	if (keycode == 53)
		handle_close_event_game(game, 0);
	if (keycode == 0)
	{
		game->pp--;
		game->facing_r = 0;
	}
	if (keycode == 2)
	{
		game->pp++;
		game->facing_r = 1;
	}
	if (keycode == 1)
		game->pp += game->map_width;
	if (keycode == 13)
		game->pp -= game->map_width;
	game->player_steps++;
	if (game->map[game->pp].tile == 'C')
		handle_collectable(game);
	if (game->map[game->pp].tile == 'E')
		handle_end(game);
	return (0);
}

int	keyboard_event_game(int keycode, t_game *game)
{
	process_key_game(keycode, game);
	return (0);
}
