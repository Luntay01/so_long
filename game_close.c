/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:21:56 by kmordaun          #+#    #+#             */
/*   Updated: 2023/09/14 14:39:30 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	cleanup_memory_3(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 19)
		mlx_destroy_image(game->mlx, game->la[i]);
}

void	cleanup_memory_2(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(game->mlx, game->par[i]);
		mlx_destroy_image(game->mlx, game->pal[i]);
		mlx_destroy_image(game->mlx, game->e360[i]);
		mlx_destroy_image(game->mlx, game->e22[i]);
		mlx_destroy_image(game->mlx, game->e45[i]);
		mlx_destroy_image(game->mlx, game->e67[i]);
		mlx_destroy_image(game->mlx, game->e90[i]);
		mlx_destroy_image(game->mlx, game->e112[i]);
		mlx_destroy_image(game->mlx, game->e135[i]);
		mlx_destroy_image(game->mlx, game->e157[i]);
		mlx_destroy_image(game->mlx, game->e180[i]);
		mlx_destroy_image(game->mlx, game->e202[i]);
		mlx_destroy_image(game->mlx, game->e225[i]);
		mlx_destroy_image(game->mlx, game->e247[i]);
		mlx_destroy_image(game->mlx, game->e270[i]);
		mlx_destroy_image(game->mlx, game->e292[i]);
		mlx_destroy_image(game->mlx, game->e315[i]);
		mlx_destroy_image(game->mlx, game->e337[i]);
		i++;
	}
}

void	cleanup_memory(t_game *game)
{
	int	i;

	i = -1;
	cleanup_memory_2(game);
	cleanup_memory_3(game);
	while (++i < 5)
	{
		mlx_destroy_image(game->mlx, game->p_a_r[i]);
		mlx_destroy_image(game->mlx, game->p_a_l[i]);
	}
	i = -1;
	while (++i < 25)
	{
		mlx_destroy_image(game->mlx, game->b_e[i]);
		mlx_destroy_image(game->mlx, game->e_a[i]);
	}
	i = -1;
	while (++i < 122)
		mlx_destroy_image(game->mlx, game->o_a[i]);
	mlx_destroy_image(game->mlx, game->o_d);
	mlx_destroy_image(game->mlx, game->e_a[25]);
	free(game->enemy);
	free(game->map);
}
/*
int	handle_close_event_game(t_game *game, int screen)
{
	cleanup_memory(game);
	mlx_destroy_window(game->mlx, game->win);
	if (screen == 1)
		return (0);
	exit(0);
}
*/

int	handle_close_event_game(t_game *game, int screen)
{
	cleanup_memory(game);
	Mix_HaltMusic();
	Mix_FreeMusic(game->music);
	Mix_CloseAudio();
	SDL_Quit();
	mlx_destroy_window(game->mlx, game->win);
	if (screen == 1)
		return (0);
	exit(0);
}
