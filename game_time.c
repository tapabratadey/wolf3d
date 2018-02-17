/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:53:01 by tadey             #+#    #+#             */
/*   Updated: 2018/02/15 14:53:40 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	game_time(t_game *game)
{
	double frame_time;

	game->old_frame = game->new_frame;
	game->new_frame = clock();
	frame_time = (game->new_frame - game->old_frame) / 1000.0;
	game->speed = frame_time * 8.0;
	game->rotation = frame_time * 4.0;
}