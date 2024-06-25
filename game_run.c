/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:55:57 by kmordaun          #+#    #+#             */
/*   Updated: 2023/09/14 14:41:17 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	assign_values_2(t_game *game)
{
	game->w = 0;
	game->h = 0;
	game->current_frame = 0;
	game->becoming_frame = 0;
	game->enemy_frame = 0;
	game->attack_on = 0;
	game->old_man_frame = 0;
	game->lantern_frame = 0;
	game->angle = 0;
	game->speed = 0;
}

void	assign_values(t_game *game, void *mlx, int map_selected, int difficulty)
{
	game->enemy = NULL;
	game->map = NULL;
	game->player_steps = 0;
	game->most_eff = 0;
	game->map_nbr = map_selected;
	game->facing_r = 1;
	game->win_game = 0;
	game->map_height = 0;
	game->old_men = 0;
	game->num_enemies = 0;
	game->max_enemies = 0;
	game->gnl_str = NULL;
	game->mlx = mlx;
	game_images01(game);
	assign_values_2(game);
	if (difficulty == 1)
		game->difficulty = 10;
	else
		game->difficulty = difficulty;
}
/*
void	run_game(char *filename, void *mlx, int map_selected, int difficulty)
{
	t_game	game;

	assign_values(&game, mlx, map_selected, difficulty);
	if (create_map(filename, &game) == 1)
		return ;
	game.win = mlx_new_window(game.mlx, 128 * game.map_width, \
			128 * game.map_height, "ANOTHER DAY ANOTHER DOLLAR!!");
	mlx_hook(game.win, 17, 0, handle_close_event_game, &game);
	if (game.win_game == 0)
		mlx_hook(game.win, 2, 1l << 0, keyboard_event_game, &game);
	mlx_loop_hook(game.mlx, update_game, &game);
	mlx_loop(game.mlx);
}
*/

void	play_music(t_game *game)
{
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
		printf("SDL initialization failed: %s\n", SDL_GetError());
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		printf("SDL_mixer initialization failed: %s\n", Mix_GetError());
	game->music = Mix_LoadMUS("sound/stabwound8bitwav.wav");
	if (game->music == NULL)
		printf("Error loading music file: %s\n", Mix_GetError());
}

void	run_game(char *filename, void *mlx, int map_selected, int difficulty)
{
	t_game	game;

	assign_values(&game, mlx, map_selected, difficulty);
	if (create_map(filename, &game) == 1)
	{
		printf("\nlooks like that map is fucked");
		return ;
	}
	play_music(&game);
	if ((game.difficulty % 10) == 1)
		Mix_PlayMusic(game.music, -1);
	game.win = mlx_new_window(game.mlx, 128 * game.map_width, \
			128 * game.map_height, "ANOTHER DAY ANOTHER DOLLAR!!");
	mlx_hook(game.win, 17, 0, handle_close_event_game, &game);
	if (game.win_game == 0)
		mlx_hook(game.win, 2, 1l << 0, keyboard_event_game, &game);
	mlx_loop_hook(game.mlx, update_game, &game);
	mlx_loop(game.mlx);
}
