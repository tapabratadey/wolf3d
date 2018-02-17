/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 00:35:46 by tadey             #+#    #+#             */
/*   Updated: 2018/02/15 13:42:16 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

int		keyhook(int key, void *game)
{
	if (key == 53)
		exit(0);
	if (key == UP)
		key_up(game);
	if (key == DOWN)
		key_down(game);
	if (key == LEFT)
		key_left(game);
	if (key == RIGHT)
		key_right(game);
	printf("%d\n", key);
	return (0);
}

void	key_up(t_game *game)
{
	move_up(game);
	mlx_clear_window(game->mlx, game->window);
	draw_sky(game);
	draw_floor(game);
	raycast(game);
}

void	key_down(t_game *game)
{
	move_down(game);
	mlx_clear_window(game->mlx, game->window);
	draw_sky(game);
	draw_floor(game);
	raycast(game);
}

void	key_left(t_game *game)
{
	move_left(game);
	mlx_clear_window(game->mlx, game->window);
	draw_sky(game);
	draw_floor(game);
	raycast(game);
}

void	key_right(t_game *game)
{
	move_right(game);
	mlx_clear_window(game->mlx, game->window);
	draw_sky(game);
	draw_floor(game);
	raycast(game);
}