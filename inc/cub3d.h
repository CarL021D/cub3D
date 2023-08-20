#ifndef CUB3D_H
# define CUB3D_H

#include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

#define MAP_WIDTH 24 
#define MAP_HEIGHT 24
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define ROTATE_LEFT_KEY 97
#define ROTATE_RIGHT_KEY 100
#define ROT_SPEED 0.1

typedef struct s_tex
{
	void *img_ptr;       // Pointer to the loaded image
	char *data;          // Pointer to the pixel data
	int width;           // Width of the texture
	int height;          // Height of the texture
	int bits_per_pixel;  // Bits per pixel for the texture
	int size_line;       // Bytes per line in the texture
	int endian;          // Endianness information
}	t_tex;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	void		*img[4];
}	t_mlx;

typedef struct s_data
{
	t_mlx		*mlx;
	t_tex		*tex;
	char		**map;
	// int			*map[2];
	int			map_width;
	int			map_height;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
}	t_data;

typedef struct s_rayC
{
	double		cameraX;
	int			hit;
	int			side;
	int			lineHeight;
	double		perpWallDist;
	double		wallX;
	int			color;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	int			stepX;
	int			stepY;
	double		rayDirX;
	double		rayDirY;
	int			drawStart;
	int			drawEnd;

}	t_rayC;

	void	game_init(t_data *data);
	int		run_rayCast(t_data * data);
	void	draw_rays(t_rayC *rayC, t_tex *tex);
	void	get_textX(t_data *data,t_rayC *rayC);
	void	get_wallX(t_data *data, t_rayC *rayC);
	void	ray_dist_init(t_rayC *rayC);
	void	dda(t_data *data, t_rayC *rayC);
	void	init_step_and_side_dist(t_data *data, t_rayC *rayC);
	void	member_init(t_data *data, t_rayC *rayC, int x);
	bool	move_forward(t_data *data, int keycode);
	bool	move_backward(t_data *data, int keycode);
	bool	move_left(t_data *data, int keycode);
	bool	move_right(t_data *data, int keycode);
	bool	rotate_left(t_data *data, int keycode);
	bool	rotate_right(t_data *data, int keycode);
	int     keys_handler(int key, t_data *data);

#endif