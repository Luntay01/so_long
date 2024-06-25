/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_final_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:49:11 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/22 18:46:26 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	check_open(char c)
{
	if (c == '0' || c == 'C' || c == 'P' || c == 'E')
		return ('0');
	return ('1');
}

void	check_wall_surrounds(int p, t_map *map, t_game *game)
{
	t_walls	l;
	t_walls	t;
	t_walls	r;
	t_walls	b;

	l = T_TRUE;
	t = T_TRUE;
	r = T_TRUE;
	b = T_TRUE;
	if (p < game->map_width || check_open(map[p - game->map_width].tile) != '0')
		t = T_FALSE;
	if (p >= (game->map_width * (game->map_height - 1)) - game->map_width || \
			check_open(map[p + game->map_width].tile) != '0')
		b = T_FALSE;
	if (p % game->map_width == 0 || check_open(map[p - 1].tile) != '0')
		l = T_FALSE;
	if ((p + 1) % game->map_width == 0 || check_open(map[p + 1].tile) != '0')
		r = T_FALSE;
	if (l == T_FALSE && t == T_FALSE && r == T_FALSE && b == T_FALSE)
		map[p].img = xf(game->mlx, "s/b/closed.xpm", &(game->w), &(game->h));
	if (l == T_TRUE && t == T_TRUE && r == T_TRUE && b == T_TRUE)
		map[p].img = xf(game->mlx, "s/b/open.xpm", &(game->w), &(game->h));
	if (l == T_TRUE && t == T_TRUE && r == T_TRUE && b == T_FALSE)
		map[p].img = xf(game->mlx, "s/b/0L0T0R.xpm", &(game->w), &(game->h));
}

void	finalize_map(t_map *map, t_game *game)
{
	int	i;

	i = 0;
	while (i < (game->map_width * game->map_height))
	{
		if (check_open(map[i].tile) == '0')
			map[i].img = xf(game->mlx, "s/b/groun.xpm", &(game->w), &(game->h));
		else
		{
			check_wall_surrounds(i, map, game);
			check_wall_surrounds_2(i, map, game);
			check_wall_surrounds_3(i, map, game);
			check_wall_surrounds_4(i, map, game);
			check_wall_surrounds_5(i, map, game);
			check_wall_surrounds_6(i, map, game);
		}
		i++;
	}
}
