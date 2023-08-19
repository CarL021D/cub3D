#include "inc/cub3d.h"

void	member_init(t_data *data, t_rayC *rayC)
{
	rayC->cameraX = 2 * MAP_WIDTH / (double)(MAP_WIDTH) - 1;
	data->dirX = data->dirX + data->planeX * rayC->cameraX;
	data->dirY = data->dirY + data->planeY * rayC->cameraX;
	rayC->mapX = (int)(data->posX);
	rayC->mapY = (int)(data->posY);
	if (rayC->rayDirX == 0)
		rayC->deltaDistX = 1e30;
	else
		rayC->deltaDistX = fabs(1 / rayC->rayDirX);
	if (rayC->rayDirY == 0)
		rayC->deltaDistY = 1e30;
	else
		rayC->deltaDistY = fabs(1 / rayC->rayDirY);
}

// rayCulate step
void	init_step_and_side_dist(t_data *data, t_rayC *rayC)
{
	if (rayC->rayDirX < 0)
	{
		rayC->stepX = -1;
		rayC->sideDistX = (data->posX - rayC->mapX) * rayC->deltaDistX;
	}
	else
	{
		rayC->stepX = 1;
		rayC->sideDistX = (rayC->mapX + 1.0 - data->posX) * rayC->deltaDistX;
	}
	if (rayC->rayDirY < 0)
	{
		rayC->stepY = -1;
		rayC->sideDistY = (data->posY - rayC->mapY) * rayC->deltaDistY;
	}
	else
	{
		rayC->stepY = 1;
		rayC->sideDistY = (rayC->mapY + 1.0 - data->posY) * rayC->deltaDistY;
	}
}

void	dda(t_rayC *rayC)
{
	while (rayC->hit == 0)
	{
		if (rayC->sideDistX < rayC->sideDistY)
		{
			rayC->sideDistX += rayC->deltaDistX;
			rayC->mapX += rayC->stepX;
			rayC->side = 0;
		}
		else
		{
			rayC->sideDistY += rayC->deltaDistY;
			rayC->mapY += rayC->stepY;
			rayC->side = 1;
		}
		if (rayC->worldMap[rayC->mapX][rayC->mapY] > 0)
			rayC->hit = 1;
	}
}

void	ray_dist_init(t_rayC *rayC)
{
	if (rayC->side == 0)
		rayC->perpWallDist = (rayC->sideDistX - rayC->deltaDistX);
	else
		rayC->perpWallDist = (rayC->sideDistY - rayC->deltaDistY);
	//Calculate height of line to draw on screen
	rayC->lineHeight = (int)(SCREEN_HEIGHT / rayC->perpWallDist);
	//calculate lowest and highest pixel to fill in current stripe
	rayC->drawStart = -rayC->lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (rayC->drawStart < 0)
		rayC->drawStart = 0;
	rayC->drawEnd = rayC->lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (rayC->drawEnd >= SCREEN_HEIGHT)
		rayC->drawEnd = SCREEN_HEIGHT - 1;
}
