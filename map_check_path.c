/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:52:15 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/23 14:13:04 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path(int pos, t_map *map, int target, int width)
{
	if (pos == target)
	{
		map[pos].visited = 2;
		return ;
	}
	if (map[pos].tile == '1' || map[pos].visited == 1)
		return ;
	map[pos].visited = 1;
	path(pos - width, map, target, width);
	path(pos + width, map, target, width);
	path(pos - 1, map, target, width);
	path(pos + 1, map, target, width);
}

void	unvisit_tile(t_map *map, t_game *game)
{
	int	i;

	i = 0;
	while (i < (game->map_width * game->map_height))
	{
		if (map[i].visited == 1)
			game->most_eff += 1;
		map[i].visited = 0;
		i++;
	}
}

int	check_valid_path(t_map *map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	path(game->pp, map, game->end_pos, game->map_width);
	if (map[game->end_pos].visited != 2)
		return (1);
	while (j < game->old_men)
	{
		if (map[i].tile == 'C')
		{
			unvisit_tile(map, game);
			path(game->pp, map, i, game->map_width);
			if (map[i].visited != 2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
