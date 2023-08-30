#include "../../inc/cub3d.h"

bool	rotate_left(t_data *data, int keycode)
{
	double	oldDirX;
	double	oldPlaneX;

	if (keycode != ROTATE_LEFT_KEY)
		return (false);
	 //both camera direction and camera plane must be rotated
	oldDirX = data->dirX;
	data->dirX = data->dirX * cos(-ROT_SPEED) - data->dirY * sin(-ROT_SPEED);
	data->dirY = oldDirX * sin(-ROT_SPEED) + data->dirY * cos(-ROT_SPEED);
	oldPlaneX = data->planeX;
	data->planeX = data->planeX * cos(-ROT_SPEED) - data->planeY * sin(-ROT_SPEED);
	data->planeY = oldPlaneX * sin(-ROT_SPEED) + data->planeY * cos(-ROT_SPEED);
	return (true);
}

bool	rotate_right(t_data *data, int keycode)
{
	double oldDirX;
	double oldPlaneX;

	if (keycode != ROTATE_RIGHT_KEY)
		return (false);
	oldDirX = data->dirX;
	data->dirX = data->dirX * cos(ROT_SPEED) - data->dirY * sin(ROT_SPEED);
	data->dirY = oldDirX * sin(ROT_SPEED) + data->dirY * cos(ROT_SPEED);
	oldPlaneX = data->planeX;
	data->planeX = data->planeX * cos(ROT_SPEED) - data->planeY * sin(ROT_SPEED);
	data->planeY = oldPlaneX * sin(ROT_SPEED) + data->planeY * cos(ROT_SPEED);
	return (true);
}