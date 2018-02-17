/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:54:12 by tadey             #+#    #+#             */
/*   Updated: 2018/02/15 14:23:06 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	raycast(t_game *game)
{
	game->x = 0;
	while ((double)game->x <= WIDTH)
	{
		game->camera_x = (2 * (double)game->x) / WIDTH - 1;
		game->ray_dir_x = game->initdir_x + game->plane_x * game->camera_x;
		game->ray_dir_y = game->initdir_y + game->plane_y * game->camera_x;
		calc(game);
		init(game);
		game->wall_dist = 0;
		game->hit = 0;
		game->side = 0;
		algorithm(game);
		calc_dist(game);
		fill_color(game);
		game->x++;
	}
}

void	calc(t_game *game)
{
	game->map_x = (int)game->player_x;
	game->map_y = (int)game->player_y;
	game->new_side_x = fabs(1 / game->ray_dir_x);
	game->new_side_y = fabs(1 / game->ray_dir_y);
}

void	init(t_game *game)
{
	if (game->ray_dir_x < 0)
	{
		game->step_x = -1;
		game->side_x = (game->player_x - game->map_x) * game->new_side_x;
	}
	else
	{
		game->step_x = 1;
		game->side_x = (game->map_x + 1.0 - game->player_x) * game->new_side_x;
	}
	if (game->ray_dir_y < 0)
	{
		game->step_y = -1;
		game->side_y = (game->player_y - game->map_y) * game->new_side_y;
	}
	else
	{
		game->step_y = 1;
		game->side_y = (game->map_y + 1.0 - game->player_y) * game->new_side_y;
	}
}

void	algorithm(t_game *game)
{
	while (game->hit == 0)
	{
		if (game->side_x < game->side_y)
		{
			game->side_x += game->new_side_x;
			game->map_x += game->step_x;
			game->side = 0;
		}
		else
		{
			game->side_y += game->new_side_y;
			game->map_y += game->step_y;
			game->side = 1;
		}
		if (game->game_map[game->map_x][game->map_y] > 0)
			game->hit = 1;
	}
	if (game->side == 0)
		game->wall_dist = (double)(game->map_x - game->player_x +
				(1 - game->step_x) / 2) / game->ray_dir_x;
	else
		game->wall_dist = (double)(game->map_y - game->player_y +
				(1 - game->step_y) / 2) / game->ray_dir_y;
}

void	calc_dist(t_game *game)
{
	int	line_height;

	game->start = 0;
	game->end = 0;
	line_height = (int)(HEIGHT / game->wall_dist);
	game->start = (-line_height / 2) + (HEIGHT / 2);
	if (game->start < 0)
		game->start = 0;
	game->end = (line_height / 2) + (HEIGHT / 2);
	if (game->end >= HEIGHT)
		game->end = HEIGHT - 1;
}
