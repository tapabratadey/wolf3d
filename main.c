/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:42:36 by tadey             #+#    #+#             */
/*   Updated: 2018/02/16 22:01:33 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

int		**create_game_map(t_game *game)
{
	int		**new;
	int		i;
	int		j;
	int		k;
	int		m;
	int		n;

	game->s = game->map;
	new = (int **)ft_memalloc(sizeof(int *) * MAP_HEIGHT);
	i = 0;
	j = 0;
	while (i < MAP_HEIGHT)
	{
		new[i] = (int *)ft_memalloc(sizeof(int) * MAP_WIDTH);
		k = 0;
		while (k < MAP_WIDTH)
		{
			new[i][k] = ft_atoi(&game->s[j]);
			j += 2;
			++k;
		}
		++i;
	}
	m = 0;
	while (m < 24)
	{
		n = 0;
		while (n < 23)
		{
			if (new[23][n] != 1 || new[0][n] != 1 || new[m][23] != 1 || new[m][0] != 1)
				error("You can't change the boundary.");
			n++;
		}
		m++;
	}
	return (new);
}

int		main(int argc, char **argv)
{
	t_game *game;

	game = (t_game*)malloc(sizeof(t_game));
	game->player_x = 22;
	game->player_y = 12;
	game->initdir_x = -1;
	game->initdir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0.66;
	game->mlx = mlx_init();
	read_map(argc, argv, game);
	game->window = mlx_new_window(game->mlx, 500, 500, "Wolf3d");
	game->game_map = create_game_map(game);
	draw_sky(game);
	draw_floor(game);
	raycast(game);
	mlx_hook(game->window, 2, 0, keyhook, game);
	mlx_hook(game->window, 17, 0, exit_hook, game);
	mlx_loop(game->mlx);
	return (0);
}
