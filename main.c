#include "inc/cub3d.h"@

int     main(int ac, char **av)
{
	t_mlx	mlx;	
	t_data	data;
	t_rayC	rayC;

//	check_map_error();
	game_init(&data, &rayC);

	mlx_loop_hook(mlx.mlx_ptr, );

	//raycast starts here





#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_ROTATE_LEFT 97
#define KEY_ROTATE_RIGHT 100
#define ROT_SPEED 0.1

	void	move_forward(t_rayC *rayC, int keycode)
	{
		if (keycode != KEY_UP)
			return ;
		// 0.1 by default value to maybe change
		if (rayC.map[int(rayC.posX + rayC.dirX * ROT_SPEED)]
			[int(rayC.posY)] == 0)
				rayC.posX += rayC.dirX * ROT_SPEED;
		if(rayC.map[int(rayC.posX)]
			[int(rayC.posY + rayC.dirY * ROT_SPEED)] == 0)	
				rayC.posY += rayC.dirY * ROT_SPEED;
	}

	void	move_backward(t_rayC *rayC, int keycode)
	{
		if (keycode != KEY_DOWN)
		if(rayC.map[int(rayC.posX - rayC.dirX * ROT_SPEED)]
			[int(rayC.posY)] == O)
				rayC.posX -= rayC.dirX * ROT_SPEED;
		if(rayC.map[int(rayC.posX)]
			[int(rayC.posY - rayC.dirY * ROT_SPEED)] == 0)
	  			rayC.posY -= rayC.dirY * ROT_SPEED;
	}

	void	rotate_left(t_rayC *rayC, int keycode)
	{
		 //both camera direction and camera plane must be rotated
		double oldDirX = rayC.dirX;
		rayC.dirX = rayC.dirX * cos(-rotSpeed) - rayC.dirY * sin(-rotSpeed);
		rayC.dirY = oldDirX * sin(-rotSpeed) + rayC.dirY * cos(-rotSpeed);
		rayC.oldPlaneX = planeX;
		planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
		planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);

	}

	void	rotate_right(t_rayC *rayC, int keycode)
	{
		double oldDirX = rayC.dirX;
		dirX = rayC.dirX * cos(rotSpeed) - rayC.dirY * sin(rotSpeed);
		rayC.dirY = oldDirX * sin(rotSpeed) + rayC.dirY * cos(rotSpeed);
		double oldPlaneX = rayC.planeX;
		rayC.planeX = rayC.planeX * cos(rotSpeed) - rayC.planeY * sin(rotSpeed);
		rayC.planeY = oldPlaneX * sin(rotSpeed) + rayC.planeY * cos(rotSpeed);

	}


}