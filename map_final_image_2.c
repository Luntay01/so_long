/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_final_image_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:41:20 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/22 18:41:49 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_wall_surrounds_6(int p, t_map *map, t_game *game)
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
	if (l == T_TRUE && t == T_TRUE && r == T_FALSE && b == T_TRUE)
		map[p].img = xf(game->mlx, "s/b/0L0T0B.xpm", &(game->w), &(game->h));
	if (l == T_FALSE && t == T_FALSE && r == T_TRUE && b == T_FALSE)
		map[p].img = xf(game->mlx, "s/b/0R.xpm", &(game->w), &(game->h));
	if (l == T_FALSE && t == T_TRUE && r == T_FALSE && b == T_FALSE)
		map[p].img = xf(game->mlx, "s/b/0T.xpm", &(game->w), &(game->h));
}

void	check_wall_surrounds_5(int p, t_map *map, t_game *game)
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
	if (l == T_TRUE && t == T_FALSE && r == T_FALSE && b == T_FALSE)
		map[p].img = xf(game->mlx, "s/b/0L.xpm", &(game->w), &(game->h));
	if (l == T_TRUE && t == T_FALSE && r == T_FALSE && b == T_TRUE)
		map[p].img = xf(game->mlx, "s/b/0L0B.xpm", &(game->w), &(game->h));
	if (l == T_TRUE && t == T_FALSE && r == T_TRUE && b == T_TRUE)
		map[p].img = xf(game->mlx, "s/b/0L0B0R.xpm", &(game->w), &(game->h));
}

void	check_wall_surrounds_4(int p, t_map *map, t_game *game)
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
	if (l == T_FALSE && t == T_TRUE && r == T_FALSE && b == T_TRUE)
		map[p].img = xf(game->mlx, "s/b/0T0B.xpm", &(game->w), &(game->h));
	if (l == T_FALSE && t == T_TRUE && r == T_TRUE && b == T_TRUE)
		map[p].img = xf(game->mlx, "s/b/0T0B0R.xpm", &(game->w), &(game->h));
	if (l == T_FALSE && t == T_TRUE && r == T_TRUE && b == T_FALSE)
		map[p].img = xf(game->mlx, "s/b/0T0R.xpm", &(game->w), &(game->h));
}

void	check_wall_surrounds_3(int p, t_map *map, t_game *game)
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
	if (l == T_FALSE && t == T_FALSE && r == T_FALSE && b == T_TRUE)
		map[p].img = xf(game->mlx, "s/b/0B.xpm", &(game->w), &(game->h));
	if (l == T_FALSE && t == T_FALSE && r == T_TRUE && b == T_TRUE)
		map[p].img = xf(game->mlx, "s/b/0B0R.xpm", &(game->w), &(game->h));
}

void	check_wall_surrounds_2(int p, t_map *map, t_game *game)
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
	if (l == T_TRUE && t == T_FALSE && r == T_TRUE && b == T_FALSE)
		map[p].img = xf(game->mlx, "s/b/0L0R.xpm", &(game->w), &(game->h));
	if (l == T_TRUE && t == T_TRUE && r == T_FALSE && b == T_FALSE)
		map[p].img = xf(game->mlx, "s/b/0L0T.xpm", &(game->w), &(game->h));
}
