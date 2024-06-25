/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:33:17 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/08 13:33:41 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;

	mlx = mlx_init();
	*argv = NULL;
	if (argc == 1)
		run_intro(mlx);
	else
		run_game(argv[1], mlx, 0, 1);
}
