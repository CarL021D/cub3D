#ifndef CUB3D_H
# define CUB3D_H

#include <mlx.h>
#include <unsitd.h>
#include <stdlib.h>
#include <math.h>
#include <cstdint.h>
#include <stdbool.h>

#define MAP_WIDTH 24 
#define MAP_HEIGHT 24
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 640

#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_ROTATE_LEFT 97
#define KEY_ROTATE_RIGHT 100
#define ROT_SPEED 0.1

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	void		*img[4];
}	t_mlx;

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


typedef struct s_data
{
	int			*map[2];
	int			map_width;
	int			map_height;
	int			screen_width;
	int			screen_height;

}	t_data;

typedef struct s_rayC
{
	double		cameraX;
	int			hit;
	int			side;
	int			lineHeight;
	double		perpWallDist;
	double		wallX;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	int			stepX;
	int			stepY;
	int			drawStart;
	int			drawEnd;

}	t_rayC;

	void	game_init();

	int		rayCast(t_rayC * rayC);
	void	caluclate_ray_dist(t_rayC *rayC);
	void	ray_dist_init(t_rayC *rayC);
	void	dda(t_rayC *rayC);
	void	calculate_step_and_side_dist(t_rayC *rayC);
	void	member_init(t_rayC *rayC);

	bool	move_forward(t_rayC *rayC, int keycode);
	bool	move_backward(t_rayC *rayC, int keycode);
	bool	move_left(t_rayC *rayC, int keycode);
	bool	move_right(t_rayC *rayC, int keycode);
	bool	rotate_left(t_rayC *rayC, int keycode);
	bool	rotate_right(t_rayC *rayC, int keycode);
	int     keys_handler(int key, t_mlx *mlx);










#endif