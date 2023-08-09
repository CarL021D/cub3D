#include "inc/cub3d.h"

bool	move_forward(t_rayC *rayC, int keycode)
{
	if (keycode != KEY_UP)
		return (false);
	// 0.1 by default value to maybe change
	if (rayC.map[int(rayC.posX + rayC.dirX * ROT_SPEED)]
		[int(rayC.posY)] == 0)
			rayC.posX += rayC.dirX * ROT_SPEED;
	if(rayC.map[int(rayC.posX)]
		[int(rayC.posY + rayC.dirY * ROT_SPEED)] == 0)	
			rayC.posY += rayC.dirY * ROT_SPEED;
    return (true);
}

bool	move_backward(t_rayC *rayC, int keycode)
{
	if (keycode != KEY_DOWN)
		return (false);
	if(rayC.map[int(rayC.posX - rayC.dirX * ROT_SPEED)]
		[int(rayC.posY)] == O)
			rayC.posX -= rayC.dirX * ROT_SPEED;
	if(rayC.map[int(rayC.posX)]
		[int(rayC.posY - rayC.dirY * ROT_SPEED)] == 0)
  			rayC.posY -= rayC.dirY * ROT_SPEED;
    return (true);
}

bool	move_left(t_rayC *rayC, int keycode)
{
	if (keycode != KEY_LEFT)
		return (false);
	// 0.1 by default value to maybe change
	if (rayC.map[int(rayC.posX + rayC.planeX * ROT_SPEED)]
		[int(rayC.posY)] == 0)
			rayC.posX += rayC.planeX * ROT_SPEED;
	if(rayC.map[int(rayC.posX)]
		[int(rayC.posY + rayC.planeY * ROT_SPEED)] == 0)	
			rayC.posY += rayC.planeY * ROT_SPEED;
    return (true);
}

bool	move_right(t_rayC *rayC, int keycode)
{
	if (keycode != KEY_RIGHT)
		return (false);
	if(rayC.map[int(rayC.posX - rayC.planeX * ROT_SPEED)]
		[int(rayC.posY)] == O)
			rayC.posX -= rayC.planeX * ROT_SPEED;
	if(rayC.map[int(rayC.posX)]
		[int(rayC.posY - rayC.planeY * ROT_SPEED)] == 0)
  			rayC.posY -= rayC.planeY * ROT_SPEED;
    return (true);
}
