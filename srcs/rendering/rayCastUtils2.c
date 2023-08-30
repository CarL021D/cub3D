#include "../../inc/cub3d.h"

void	get_wallX(t_data *data, t_rayC *rayC)
{
	if (rayC->side == 0)
		rayC->wallX = data->posY + rayC->perpWallDist * data->dirY;
	else
		rayC->wallX = data->posX + rayC->perpWallDist * data->dirX;
	rayC->wallX -= floor(rayC->wallX); 
}

void	get_textX(t_data *data, t_rayC *rayC)
{
	rayC->texX = (int)(rayC->wallX * (double)(TEXT_WIDTH));
	if (rayC->side == 0 && rayC->rayDirX > 0)
		rayC->texX = TEXT_WIDTH - rayC->texX - 1;
	if (rayC->side == 1 && rayC->rayDirY < 0)
		rayC->texX = TEXT_WIDTH - rayC->texX - 1;
}


void	draw_rays(t_data *data, t_rayC *rayC, int x)
{
	int		y;
	int		texY;
	double	step;
	double	texPos;

	y = 0;
	step = 1.0 * TEXT_WIDTH / rayC->lineHeight;
	texPos = (rayC->drawStart - MAP_HEIGHT / 2 + rayC->lineHeight / 2) * step;	
	while (y < SCREEN_HEIGHT)
	{
		if (y < rayC->drawStart)
			data->buffer[data->current_buffer]->addr[y * SCREEN_WIDTH + x] = data->ceilingColor;
		else if (y > rayC->drawEnd)
			data->buffer[data->current_buffer]->addr[y * SCREEN_WIDTH + x] = data->floorColor;
		else
		{
			data->buffer[data->current_buffer]->addr[y * SCREEN_WIDTH + x] = data->wallColor;

		}
		y++;
	}
}
