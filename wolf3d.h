/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:38:48 by tadey             #+#    #+#             */
/*   Updated: 2018/02/15 14:51:50 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft/libft.h"
# include "./minilibx_macos_sierra/mlx.h"
# include <math.h>
# include <time.h>
# include <fcntl.h>

# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define WIDTH 500
# define HEIGHT 500
# define RED 0xff0000
# define GREEN 0x00ff00
# define BLUE 0x0000ff
# define WHITE 0xffffff
# define YELLOW 0xffff00
# define BLACK 0x000000
# define BROWN 0x8B4513
# define TAN 0xD2B48C
# define PINK 0xFF1493
# define UP 13
# define DOWN 1
# define LEFT 2
# define RIGHT 0

typedef struct	s_game
{
	int		map_x;
	int		map_y;
	double	side_x;
	double	side_y;
	double	new_side_x;
	double	new_side_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	initdir_x;
	double	initdir_y;
	double	plane_x;
	double	plane_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	wall_dist;
	double	player_x;
	double	player_y;
	void	*mlx;
	void	*window;
	clock_t	old_frame;
	clock_t	new_frame;
	double	speed;
	double	rotation;
	char	up;
	char	down;
	char	left;
	char	right;
	int		color;
	int		x;
	int		start;
	int		end;
	double	old;
	double	camera_x;	
	char 	*map;
	char	*s;
	int	**game_map;
}				t_game;

void	draw_sky(t_game *game);
void	draw_floor(t_game *game);
int		keyhook(int key, void *game);
void	raycast(t_game *game);
void	calc(t_game *game);
void	init(t_game *game);
void	algorithm (t_game *game);
void	calc_dist(t_game *game);
void	fill_color(t_game *game);
void	game_time(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	key_up(t_game *game);
void	key_down(t_game *game);
void	key_left(t_game *game);
void	key_right(t_game *game);
int		exit_hook(t_game *game);
int		read_map(int argc, char **argv, t_game *game);
void    check_map(t_game *game);
int		**create_game_map(t_game *game);
int	redraw(t_game *game);
#endif
