/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:36:19 by tadey             #+#    #+#             */
/*   Updated: 2018/02/15 13:40:38 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	fill_color(t_game *game)
{
	game->color = 0;
	if (game->game_map[game->map_x][game->map_y] == 1)
		game->color = RED;
	if (game->game_map[game->map_x][game->map_y] == 2)
		game->color = BROWN;
	if (game->game_map[game->map_x][game->map_y] == 3)
		game->color = BLUE;
	if (game->game_map[game->map_x][game->map_y] == 4)
		game->color = TAN;
	if (game->side == 1)
		game->color = game->color / 2;
	while (game->start < game->end)
		mlx_pixel_put(game->mlx, game->window,
				game->x, game->start++, game->color);
	game_time(game);
}
