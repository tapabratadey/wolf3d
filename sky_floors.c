/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_floors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:17:16 by tadey             #+#    #+#             */
/*   Updated: 2018/02/15 14:20:47 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	draw_sky(t_game *game)
{
	int x;
	int sky_end;

	x = 0;
	while (x < 500)
	{
		sky_end = 0;
		while (sky_end < 500)
		{
			mlx_pixel_put(game->mlx, game->window, x, sky_end, 0x87CEFA);
			sky_end++;
		}
		x++;
	}
}

void	draw_floor(t_game *game)
{
	int x;
	int floor_height;

	x = 0;
	while (x < 500)
	{
		floor_height = 250;
		while (floor_height < 500)
		{
			mlx_pixel_put(game->mlx, game->window, x, floor_height, 0x006400);
			floor_height++;
		}
		x++;
	}
}
