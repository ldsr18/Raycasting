#ifndef CUB3D_H
#define CUB3D_H

#define WIDTH 1280
#define HEIGHT 720
#define BLOCK 64
#define DEBUG 1

#include "../includes/minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

# define W	122
# define S	115
# define A	113
# define D	100
# define LEFT			65361
# define RIGHT			65363

# define KEY_Q			97
# define KEY_ESC		65307

# define PI 3.14159265359

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;

	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;

	bool	left_rotate;
	bool	right_rotate;
}	t_player;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;

	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	t_player	player;

	char	**map;
}	t_game;

void	init_player(t_player *player);
int		key_press(int keycode, t_player *player);
int		key_release(int keycode, t_player *player);
void	move_player(t_player *player);

#endif