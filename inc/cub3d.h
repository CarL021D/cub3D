#ifndef CUB3D_H
# define CUB3D_H

#include <unsitd.h>
#include <stdlib.h>
#include <math.h>
#include <cstdint.h>

#define MAP_WIDTH 24 
#define MAP_HEIGHT 24
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT


typedef struct s_map
{
	int			*map[2];
	int			map_width;
	int			map_height;
	int			screen_width;
	int			screen_height;

}	t_map;

typedef struct s_calcul
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

}	t_calcul;








#endif