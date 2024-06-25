/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:18:55 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/24 18:24:29 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
/*
char	*mod_strjoin(char const *str1, char const *str2)
{
	int		i;
	int		j;
	char	*str;

	str = (char *)malloc(ft_strlen((char *)str1) + ft_strlen((char *)str2) + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (str1[++j])
		str[++i] = str1[j];
	j = -1;
	while (str2[++j])
		str[++i] = str2[j];
	str[++i] = '\0';
	return (str);
}
*/
int	assign_tile(int i, char s, t_map *map, t_game *game)
{
	if (s == '0')
		map[i].tile = '0';
	if (s == '1')
		map[i].tile = '1';
	if (s == 'P')
	{
		map[i].tile = 'P';
		game->pp = i;
	}
	if (s == 'C')
	{
		map[i].tile = 'C';
		game->old_men++;
	}
	if (s == 'E')
	{
		map[i].tile = 'E';
		game->end_pos = i;
	}
	if (s != '0' && s != '1' && s != 'P' && s != 'C' && s != 'E')
	{
		write(1, "Error\nmap doesnt have one of these 01PCE", 40);
		return (1);
	}
	return (0);
}

int	assign_positions(char *s, t_map *map)
{
	int	i;
	int	j;
	int	pos_y;

	i = 0;
	j = 0;
	pos_y = 0;
	while (*s)
	{
		if (*s != '\n')
		{
			map[i].pos_x = j * 128;
			map[i].pos_y = pos_y;
			map[i].visited = 0;
			i++;
			j++;
		}
		else
		{
			j = 0;
			pos_y += 128;
		}
		s++;
	}
	return (0);
}

int	construct_map(char *s, t_map *map, t_game *game)
{
	int	i;

	i = 0;
	assign_positions(s, map);
	while (*s != '\0')
	{
		if (*s != '\n')
		{
			if (assign_tile(i, *s, map, game) == 1)
				return (1);
			i++;
		}
		s++;
	}
	return (0);
}

int	create_map(char *filename, t_game *game)
{
	game->fd = open(filename, O_RDONLY);
	if (!game->fd)
		return (1);
	game->gnl_line = get_next_line(game->fd);
	game->map_width = ft_strlen(game->gnl_line) - 1;
	while ((game->gnl_line != NULL))
	{
		game->gnl_temp = mod_strjoin(game->gnl_str, game->gnl_line);
		game->gnl_str = game->gnl_temp;
		game->map_height = game->map_height + 1;
		free(game->gnl_line);
		game->gnl_line = get_next_line(game->fd);
	}
	close(game->fd);
	if (game->gnl_str[ft_strlen(game->gnl_str) - 1] == '\n')
		game->gnl_str[ft_strlen(game->gnl_str) - 1] = '\0';
	game->map = malloc(game->map_height * game->map_width * (sizeof(t_map)));
	if (!game->map || construct_map(game->gnl_str, game->map, game) == 1 || \
			check_map_error(game->gnl_str, game->map, game) == 1)
		return (1);
	free(game->gnl_str);
	finalize_map(game->map, game);
	return (0);
}
