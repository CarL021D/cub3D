#include "../../inc/cub3d.h"

bool	move_forward(t_data *data, int keycode)
{
	if (keycode != KEY_UP)
		return (false);
	
	printf("up\n\n");
	printf("posX [%lf]\n\n", data->posX);
	printf("posY [%lf]\n\n", data->posY);
	// 0.1 by default value to maybe change
	if (data->map[(int)(data->posX + data->dirX * ROT_SPEED)]
		[(int)(data->posY)] == 0)
			data->posX += data->dirX * ROT_SPEED;
	if(data->map[(int)(data->posX)]
		[(int)(data->posY + data->dirY * ROT_SPEED)] == 0)	
			data->posY += data->dirY * ROT_SPEED;
    return (true);
}

bool	move_backward(t_data *data, int keycode)
{
	if (keycode != KEY_DOWN)
		return (false);

	printf("back\n\n");
	printf("posX [%lf]\n\n", data->posX);
	printf("posY [%lf]\n\n", data->posY);

	if(data->map[(int)(data->posX - data->dirX * ROT_SPEED)]
		[(int)(data->posY)] == 0)
			data->posX -= data->dirX * ROT_SPEED;
	if(data->map[(int)(data->posX)]
		[(int)(data->posY - data->dirY * ROT_SPEED)] == 0)
  			data->posY -= data->dirY * ROT_SPEED;
    return (true);
}

bool	move_left(t_data *data, int keycode)
{
	if (keycode != KEY_LEFT)
		return (false);
	printf("left\n\n");
	
	// 0.1 by default value to maybe change
	if (data->map[(int)(data->posX + data->planeX * ROT_SPEED)]
		[(int)(data->posY)] == 0)
			data->posX += data->planeX * ROT_SPEED;
	if(data->map[(int)(data->posX)]
		[(int)(data->posY + data->planeY * ROT_SPEED)] == 0)	
			data->posY += data->planeY * ROT_SPEED;
    return (true);
}

bool	move_right(t_data *data, int keycode)
{
	if (keycode != KEY_RIGHT)
		return (false);

	printf("right\n\n");

	if(data->map[(int)(data->posX - data->planeX * ROT_SPEED)]
		[(int)(data->posY)] == 0)
			data->posX -= data->planeX * ROT_SPEED;
	if(data->map[(int)(data->posX)]
		[(int)(data->posY - data->planeY * ROT_SPEED)] == 0)
  			data->posY -= data->planeY * ROT_SPEED;
    return (true);
}
