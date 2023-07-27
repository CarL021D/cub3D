#include "inc/cub3d.h"@

int     main(int ac, char **av)
{
	t_mlx	mlx;	
	t_data	data;
	t_rayC	rayC;

//	check_map_error();
	game_init(&data, &rayC);

	mlx_loop_hook(mlx->mlx_ptr,);

	//raycast starts here

	uint32_t    x;
	x = 0;
	while (x < MAP_WIDTH)
	{
		rayC.cameraX = 2 * x / double(MAP_WIDTH) - 1;
		rayC.dirX = rayC.dirX + rayC.planeX * rayC.cameraX;
		rayC.dirY = rayC.dirY + rayC.planeY * rayC.cameraX;
		rayC.mapX = (int)(rayC.posX);
		rayC.mapY = (int)(rayC.posY);
		if (rayC.rayDirX == 0)
			rayC.deltaDistX = 1e30;
		else
			rayC.deltaDistX = fabs(1 / rayC.rayDirX);
		if (rayC.rayDirY == 0)
			rayC.deltaDistY = 1e30;
		else
			rayC.deltaDistY = fabs(1 / rayC.rayDirY);
	}



	// rayCulate step
	if (rayC.rayDirX < 0)
	{
		rayC.stepX = -1;
		rayC.sideDistX = (rayC.posX - rayC.mapX) * rayC.deltaDistX;
	}
	else
	{
		rayC.stepX = 1;
		rayC.sideDistX = (rayC.mapX + 1.0 - rayC.posX) * rayC.deltaDistX;
	}
	if (rayC.rayDirY < 0)
	{
		rayC.stepY = -1;
		rayC.sideDistY = (rayC.posY - rayC.mapY) * rayC.deltaDistY;
	}
	else
	{
		rayC.stepY = 1;
		cacl.sideDistY = (rayC.mapY + 1.0 - rayC.posY) * rayC.deltaDistY;
	}



	// Perform DDA
	while (rayC.hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (rayC.sideDistX < rayC.sideDistY)
		{
			rayC.sideDistX += rayC.deltaDistX;
			rayC.mapX += rayC.stepX;
			rayC.side = 0;
		}
		else
		{
			rayC.sideDistY += rayC.deltaDistY;
			rayC.mapY += rayC.stepY;
			rayC.side = 1;
		}
		//Check if ray has hit a wall
		if (rayC.map[rayC.mapX][rayC.mapY] > 0)
			rayC.hit = 1;
	}



	//perform DDA
	while (rayC.hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (rayC.sideDistX < rayC.sideDistY)
		{
			rayC.sideDistX += rayC.deltaDistX;
			rayC.mapX += rayC.stepX;
		  	rayC.side = 0;
		}
		else
		{
			rayC.sideDistY += rayC.deltaDistY;
		  	rayC.mapY += rayC.stepY;
		  	rayC.side = 1;
		}
		//Check if ray has hit a wall
		if (rayC.worldMap[rayC.mapX][rayC.mapY] > 0)
			rayC.hit = 1;
	}



	if(rayC.side == 0)
		rayC.perpWallDist = (rayC.sideDistX - rayC.deltaDistX);
	else
		rayC.perpWallDist = (rayC.sideDistY - rayC.deltaDistY);
	//Calculate height of line to draw on screen
	rayC.lineHeight = (int)(MAP_HEIGHT / rayC.perpWallDist);

	//calculate lowest and highest pixel to fill in current stripe
	rayC.drawStart = -rayC.lineHeight / 2 + MAP_HEIGHT / 2;
	if(rayC.drawStart < 0)
		rayC.drawStart = 0;
	rayC.drawEnd = rayC.lineHeight / 2 + MAP_HEIGHT / 2;
	if(rayC.drawEnd >= MAP_HEIGHT)
		rayC.drawEnd = MAP_HEIGHT - 1;



	// caluclate draw end start
	if (rayC.side == 0)
		rayC.perpWallDist = (rayC.sideDistX - rayC.deltaDistX);
	else
		rayC.perpWallDist = (rayC.sideDistY - rayC.deltaDistY);
	//rayCulate height of line to draw on screen
	rayC.lineHeight = (int)(MAP_HEIGHT / rayC.perpWallDist);

	//rayCulate lowest and highest pixel to fill in current stripe
	rayC.drawStart = -(rayC.lineHeight) / 2 + MAP_HEIGHT / 2;
	if (rayC.drawStart < 0)
		rayC.drawStart = 0;
	rayC.drawEnd = rayC.lineHeight / 2 + MAP_HEIGHT / 2;
	if(rayC.drawEnd >= MAP_HEIGHT)
		rayC.drawEnd = MAP_HEIGHT - 1;


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