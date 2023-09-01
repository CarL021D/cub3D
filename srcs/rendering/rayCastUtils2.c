#include "../../inc/cub3d.h"

void	get_wallX(t_data *data, t_rayC *rayC)
{
	if (rayC->side == 0)
		rayC->wallX = data->posY + rayC->perpWallDist * data->dirY;
	else
		rayC->wallX = data->posX + rayC->perpWallDist * data->dirX;
	rayC->wallX -= floor(rayC->wallX); 
}

void	get_textX(t_rayC *rayC)
{
	rayC->texX = (int)(rayC->wallX * (double)(TEXT_HEIGHT));
	if (rayC->side == 0 && rayC->rayDirX > 0)
		rayC->texX = TEXT_HEIGHT - rayC->texX - 1;
	if (rayC->side == 1 && rayC->rayDirY < 0)
		rayC->texX = TEXT_HEIGHT - rayC->texX - 1;
}

static int	getWallPixColor(t_data *data, t_rayC *rayC)
{
	int		currentColor;

	if (rayC->side == 1)
	{
		if (rayC->rayDirY > 0)
			currentColor = data->texture[0][TEXT_HEIGHT * rayC->texY + rayC->texX];
		else
			currentColor = data->texture[1][TEXT_HEIGHT * rayC->texY + rayC->texY];
	}
	else
	{
		if (rayC->rayDirX > 0)
			currentColor = data->texture[3][TEXT_HEIGHT * rayC->texY + rayC->texX];
		else
			currentColor = data->texture[2][TEXT_HEIGHT * rayC->texY + rayC->texX];
	}
	return (currentColor);
}

void	draw_rays(t_data *data, t_rayC *rayC, int x)
{
	int		currentColor;
	int		y;
	double	step;
	double	texPos;

	y = 0;
	step = 1.0 * TEXT_HEIGHT / rayC->lineHeight;
	texPos = (rayC->drawStart - SCREEN_HEIGHT / 2 + rayC->lineHeight / 2) * step;	
	while (y < SCREEN_HEIGHT)
	{
		if (y < rayC->drawStart)
			currentColor = data->ceilingColor;
		else if (y > rayC->drawEnd)
			currentColor = data->floorColor;
		else
		{
			rayC->texY = (int)texPos & (TEXT_HEIGHT - 1);
			texPos += step;
			currentColor = getWallPixColor(data, rayC);
		}
		data->pixBuffer[y][x] = currentColor;
		y++;
	}
}
