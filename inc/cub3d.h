#ifndef CUB3D_H
# define CUB3D_H

#include <unsitd.h>
#include <stdlib.h>
#include <math.h>
#include <cstdint.h>
#include <stdbool.h>

#define MAP_WIDTH 24 
#define MAP_HEIGHT 24
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT

#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_LEFT 123
#define KEY_RIGHT 124

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	void		*img[4];
}	t_mlx;


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






#endif