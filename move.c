/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:49:52 by tadey             #+#    #+#             */
/*   Updated: 2018/02/15 13:53:58 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	move_up(t_game *game)
{
	if (game->game_map[(int)(game->player_x + game->initdir_x *
				game->speed)][(int)game->player_y] == 0)
		game->player_x += game->initdir_x * game->speed;
	if (game->game_map[(int)game->player_x][(int)(game->player_y +
				game->initdir_y * game->speed)] == 0)
		game->player_y += game->initdir_y * game->speed;
}

void	move_down(t_game *game)
{
	if (game->game_map[(int)(game->player_x - game->initdir_x *
				game->speed)][(int)game->player_y] == 0)
		game->player_x -= game->initdir_x * game->speed;
	if (game->game_map[(int)game->player_x][(int)(game->player_y -
				game->initdir_y * game->speed)] == 0)
		game->player_y -= game->initdir_y * game->speed;
}

void	move_left(t_game *game)
{
	game->old = game->initdir_x;
	game->initdir_x = game->initdir_x * cos(-game->rotation) -
		game->initdir_y * sin(-game->rotation);
	game->initdir_y = game->old * sin(-game->rotation) +
		game->initdir_y * cos(-game->rotation);
	game->old = game->plane_x;
	game->plane_x = game->plane_x * cos(-game->rotation) -
		game->plane_y * sin(-game->rotation);
	game->plane_y = game->old * sin(-game->rotation) +
		game->plane_y * cos(-game->rotation);
}

void	move_right(t_game *game)
{
	game->old = game->initdir_x;
	game->initdir_x = game->initdir_x * cos(game->rotation) -
		game->initdir_y * sin(game->rotation);
	game->initdir_y = game->old * sin(game->rotation) +
		game->initdir_y * cos(game->rotation);
	game->old = game->plane_x;
	game->plane_x = game->plane_x * cos(game->rotation) -
		game->plane_y * sin(game->rotation);
	game->plane_y = game->old * sin(game->rotation) +
		game->plane_y * cos(game->rotation);
}
