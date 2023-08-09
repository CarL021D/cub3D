#include "inc/cub3d.h"

bool	rotate_left(t_rayC *rayC, int keycode)
{
	if (keycode != KEY_ROT_LEFT)
		return (false);
	 //both camera direction and camera plane must be rotated
	double oldDirX = rayC.dirX;
	rayC.dirX = rayC.dirX * cos(-rotSpeed) - rayC.dirY * sin(-rotSpeed);
	rayC.dirY = oldDirX * sin(-rotSpeed) + rayC.dirY * cos(-rotSpeed);
	rayC.oldPlaneX = planeX;
	planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
	planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    return (true);

}

bool	rotate_right(t_rayC *rayC, int keycode)
{
	if (keycode != KEY_RIGHT)
		return (false);
	double oldDirX = rayC.dirX;
	dirX = rayC.dirX * cos(rotSpeed) - rayC.dirY * sin(rotSpeed);
	rayC.dirY = oldDirX * sin(rotSpeed) + rayC.dirY * cos(rotSpeed);
	double oldPlaneX = rayC.planeX;
	rayC.planeX = rayC.planeX * cos(rotSpeed) - rayC.planeY * sin(rotSpeed);
	rayC.planeY = oldPlaneX * sin(rotSpeed) + rayC.planeY * cos(rotSpeed);
    return (true);
}