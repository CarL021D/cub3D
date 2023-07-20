#include "inc/cub3d.h"

int     main(int ac, char **av)
{
	//init screen + player pos
	// screen(screenWidth, screenHeight, 0, "Raycaster");
	t_calcul    calc;
	while (!done)
	//raycast starts here

	uint32_t    x;

	x = 0;
	while (x < MAP_WIDTH)
	{
		calc.cameraX = 2 * x / double(MAP_WIDTH) - 1;
		calc.dirX = calc.dirX + calc.planeX * calc.cameraX;
		calc.dirY = calc.dirY + calc.planeY * calc.cameraX;
		calc.mapX = (int)(calc.posX);
		calc.mapY = (int)(calc.posY);
		if (calc.rayDirX == 0)
			deltaDistX = 1e30;
		else
			deltaDistX = fabs(1 / calc.rayDirX);
		if (calc.rayDirY == 0)
			deltaDistY = 1e30;
		else
			deltaDistY = fabs(1 / calc.rayDirY);
	}


	// calculate step
	if (calc.rayDirX < 0)
	{
		calc.stepX = -1;
		calc.sideDistX = (calc.posX - calc.mapX) * calc.deltaDistX;
	}
	else
	{
		calc.stepX = 1;
		calc.sideDistX = (calc.mapX + 1.0 - calc.posX) * calc.deltaDistX;
	}
	if (rayDirY < 0)
	{
		calc.stepY = -1;
		calc.sideDistY = (calc.posY - calc.mapY) * calc.deltaDistY;
	}
	else
	{
		calc.stepY = 1;
		cacl.sideDistY = (calc.mapY + 1.0 - calc.posY) * calc.deltaDistY;
	}

	// Perform DDA
	while (calc.hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (calc.sideDistX < calc.sideDistY)
		{
			calc.sideDistX += calc.deltaDistX;
			calc.mapX += calc.stepX;
			calc.side = 0;
		}
		else
		{
			calc.sideDistY += calc.deltaDistY;
			calc.mapY += calc.stepY;
			calc.side = 1;
		}
		//Check if ray has hit a wall
		if (calc.map[calc.mapX][calc.mapY] > 0)
			calc.hit = 1;
	}

	//perform DDA
    while (calc.hit == 0)
    {
        //jump to next map square, either in x-direction, or in y-direction
        if (calc.sideDistX < calc.sideDistY)
        {
        	calc.sideDistX += calc.deltaDistX;
        	calc.mapX += calc.stepX;
          	calc.side = 0;
        }
        else
        {
        	calc.sideDistY += calc.deltaDistY;
          	calc.mapY += calc.stepY;
          	calc.side = 1;
        }
        //Check if ray has hit a wall
        if (calc.worldMap[calc.mapX][calc.mapY] > 0)
			calc.hit = 1;
    }

	// caluclate draw end start
	if (calc.side == 0)
		calc.perpWallDist = (calc.sideDistX - calc.deltaDistX);
	else
		calc.perpWallDist = (calc.sideDistY - calc.deltaDistY);
	//Calculate height of line to draw on screen
    calc.lineHeight = (int)(MAP_HEIGHT / calc.perpWallDist);

    //calculate lowest and highest pixel to fill in current stripe
    calc.drawStart = -(calc.lineHeight) / 2 + MAP_HEIGHT / 2;
    if (calc.drawStart < 0)
		calc.drawStart = 0;
    calc.drawEnd = calc.lineHeight / 2 + MAP_HEIGHT / 2;
    if(calc.drawEnd >= MAP_HEIGHT)
		calc.drawEnd = MAP_HEIGHT - 1;
}