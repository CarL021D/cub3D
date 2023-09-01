#ifndef CUB3D_H
# define CUB3D_H

#include "../mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>




#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH 640
#define TEXT_HEIGHT 64

#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_LEFT 113
#define KEY_RIGHT 101
#define ROTATE_LEFT_KEY 97
#define ROTATE_RIGHT_KEY 100
#define ROT_SPEED 0.1

typedef struct s_tex
{
	void	*img;       // Pointer to the loaded image
	int		*addr;
	char	*path;	     // Pointer to the pixel data
	int		width;           // Width of the texture
	int		height;      // Height of the texture
	int		bpp;			// Bits per pixel for the texture
	int		size_line;      // Bytes per line in the texture
	int		endian;          // Endianness information
}	t_tex;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_tex		tex[4];
	char		**map;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;

	int			pixColor[SCREEN_HEIGHT][SCREEN_WIDTH];

	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	int		ceilingColor;
	int		floorColor;
	// int		wallColor;
	int		nb_data;
	char	*map_simple;

	int		*texture[4];

	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;

	int 	current_buffer;
	// double playerDir;

}	t_data;

typedef struct s_rayC
{
	double		cameraX;
	int			hit;
	int			side;
	int			lineHeight;
	double		perpWallDist;
	double		wallX;
	int			texX;
	int			texY;
	int			texNum;
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
	int		draw_on_screen(t_data * data);
	void	draw_rays(t_data *data, t_rayC *rayC, int x);
	void	get_wallX(t_data *data, t_rayC *rayC);	
	void	get_textX(t_rayC *rayC);

	// void	ray_dist_init(t_rayC *rayC);
	void	ray_dist_init(t_data *data, t_rayC *rayC);
	
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