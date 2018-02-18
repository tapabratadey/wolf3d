/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 22:04:20 by tadey             #+#    #+#             */
/*   Updated: 2018/02/16 22:21:31 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <fcntl.h>
#include <stdio.h>

int		error(char *str)
{
	ft_putstr(str);
	exit(0);
}

int		read_map(int argc, char **argv, t_game *game)
{
	char	buff[1152];

	game->fd = 0;
	game->result = 0;
	game->map = NULL;
	if (argc != 2)
		error("Usage: ./wolf3d map");
	game->file = argv[1];
	if (ft_strcmp(argv[1], "map"))
		error("File should be called: map");
	game->fd = open(game->file, O_RDONLY);
	game->result = read(game->fd, buff, 1152);
	if (game->result <= 0)
		error("Cannot read an empty file.");
	if (game->result != 1152)
		error("You're not authorized. You'll be reported.");
	if (game->map == NULL)
		game->map = ft_strdup(buff);
	check_map(game);
	return (0);
}

void	check_map(t_game *game)
{
	int i;

	i = 0;
	while (game->map && game->map[i])
	{
		if (!((game->map[i] >= '0' && game->map[i] <= '4')) ||
				game->map[i] == '\n')
		{
			ft_putstr("Invalid map\n");
			exit(0);
		}
		i += 2;
	}
}
