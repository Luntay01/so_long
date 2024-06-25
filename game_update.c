/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:59:13 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/23 19:05:42 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	update_player(t_game *game)
{
	void	*img;

	if (game->attack_on == 1)
	{
		if (game->facing_r == 0)
			img = game->p_a_l[game->current_frame];
		else
			img = game->p_a_r[game->current_frame];
		game->current_frame = (game->current_frame + 1) % 5;
		if (game->current_frame >= 4)
			game->attack_on = 0;
	}
	else
	{
		if (game->facing_r == 0)
			img = game->pal[game->current_frame];
		else
			img = game->par[game->current_frame];
		game->current_frame = (game->current_frame + 1) % 4;
	}
	mlx_put_image_to_window(game->mlx, game->win, \
			img, game->map[game->pp].pos_x, game->map[game->pp].pos_y);
}

void	update_lantern(t_game *game)
{
	void	*img;

	if (game->old_men > 0)
		return ;
	img = game->la[game->lantern_frame];
	game->lantern_frame = (game->lantern_frame + 1) % 19;
	mlx_put_image_to_window(game->mlx, game->win, img, \
			game->map[game->end_pos].pos_x, game->map[game->end_pos].pos_y);
}

void	run_winning(t_game *game)
{
	void	*img;
	int		i;

	i = 0;
	img = game->e_a[game->current_frame];
	game->current_frame = (game->current_frame + 1) % 26;
	if (game->current_frame < 11)
		mlx_put_image_to_window(game->mlx, game->win, img, \
				game->map[game->end_pos].pos_x, game->map[game->end_pos].pos_y);
	else
		mlx_put_image_to_window(game->mlx, game->win, img, \
				game->map[game->end_pos].pos_x - 128, \
				game->map[game->end_pos].pos_y - 128);
	if (game->current_frame == 25)
	{
		while (i < 1000)
		{
			put_background(game);
			i++;
		}
		handle_close_event_game(game, 1);
		run_end(game->mlx, game->map_nbr, 1, game->difficulty);
	}
}

int	update_game(t_game *game)
{
	static int	animation_counter = 0;
	static int	animation_delay = 1200;
	char		*steps_str;

	if (animation_counter % animation_delay == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		put_background(game);
		update_enemies(game);
		if (game->win_game == 0)
		{
			steps_str = mod_ft_itoa(game->player_steps);
			update_player(game);
			update_lantern(game);
			mlx_string_put(game->mlx, game->win, 10, (game->map_height * 128)
				- 20, 0xFFFFFF, "EFFICIENCY  ");
			mlx_string_put(game->mlx, game->win, 80, (game->map_height * 128)
				- 20, 0xFFFFFF, steps_str);
			free(steps_str);
		}
		else
			run_winning(game);
	}
	animation_counter++;
	return (0);
}
