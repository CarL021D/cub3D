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
	rayC->texX = (int)(rayC->wallX * (double)(data->tex->width));
	if (rayC->side == 0 && rayC->rayDirX > 0)
		rayC->texX = data->tex->width - rayC->texX - 1;
	if (rayC->side == 1 && rayC->rayDirY < 0)
		rayC->texX = data->tex->width - rayC->texX - 1;
}


void	draw_rays(t_data *data, t_rayC *rayC)
{
	int		y;
	int		texY;
	double	step;
	double	texPos;

	y = rayC->drawStart;
	step = 1.0 * data->tex->height / rayC->lineHeight;
	texPos = (rayC->drawStart - MAP_HEIGHT / 2 + rayC->lineHeight / 2) * step;
	while (y < rayC->drawEnd)
	{
		texY = (int)texPos;
		texPos += step;

		// TO DO
		// Uint32 color = texture[texNum][texHeight * texY + rayC->texX];
		y++;
	}
}
