/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:34:10 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/30 18:34:12 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check_boarders(char *s)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] != '1')
			return (1);
		i++;
	}
	i++;
	while (s[--len] != '\n')
	{
		if (s[len] != '1')
			return (1);
	}
	len -= i - 1;
	while (len / i > 0)
	{
		if (s[len - 2] != '1' || s[len] != '1')
			return (1);
		len -= i;
	}
	return (0);
}

int	check_two_of(char *s)
{
	int	two_of;
	int	at_leased;

	two_of = 0;
	at_leased = 0;
	while (*s != '\0')
	{
		if (*s == 'P' || *s == 'E')
			two_of++;
		if (*s == 'C')
			at_leased++;
		s++;
	}
	if (two_of > 2 || at_leased == 0 || two_of < 2)
		return (1);
	return (0);
}

int	check_map_error(char *s, t_map *map, t_game *game)
{
	if (check_two_of(s) == 1)
	{
		write (1, "Error\neither has double of E or P or its missing\n", 49);
		return (1);
	}
	if (game->map_width == game->map_height)
	{
		write (1, "Error\nmap is square?\n", 21);
	}
	if (check_boarders(s) == 1)
	{
		write (1, "Error\nthe map boarder is not correct\n", 37);
		return (1);
	}
	if (check_valid_path(map, game) == 1)
	{
		write (1, "Error\nthe path is invalid\n", 26);
		return (1);
	}
	return (0);
}
