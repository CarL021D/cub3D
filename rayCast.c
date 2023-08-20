#include "inc/cub3d.h"

int	run_rayCast(t_data *data)
{
	t_rayC			rayC;
	unsigned int    x;
	// int32_t		texX;

	x = 0;
	while (x < MAP_WIDTH)
	{
		member_init(data, &rayC, x);
		init_step_and_side_dist(data, &rayC);
		dda(data, &rayC);
		ray_dist_init(&rayC);
		get_wallX(data, &rayC);
		get_textX(data, &rayC);
		// draw_rays(data, &rayC);
		x++;
	}
	return (1);
}

void	cast_tex(t_data *data, t_rayC *rayC)
{
	double	step;
	double	texPos;
	int		y;
	int		texY;

	step = 1.0 * data->tex->height * rayC->lineHeight;
	texPos = (rayC->drawStart - SCREEN_HEIGHT / 2 + rayC->lineHeight / 2) * step;
	y = rayC.drawStart;
	while (y < rayC->drawEnd)
	{
		texY = (int)texPos;
		texPos += step;

		//Uint32 color = texture[texNum][texHeight * texY + texX];
		//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		//if(side == 1) color = (color >> 1) & 8355711;
		//buffer[y][x] = color;
	}
}
