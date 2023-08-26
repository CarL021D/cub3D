#include "../../inc/cub3d.h"

void rayC_init(t_rayC *rayC)
{
	rayC->hit = 0;
	rayC->side = 0;
	rayC->rayDirX = 0;
	rayC->rayDirY = 0;
}

void	launch_rays(t_data *data)
{
	t_rayC			rayC;
	int				x;

	x = 0;
	while (x < data->map_width)
	{
		member_init(data, &rayC, x);
		init_step_and_side_dist(data, &rayC);
		dda(data, &rayC);
		ray_dist_init(&rayC);
		// get_wallX(data, &rayC);
		// get_textX(data, &rayC);
		draw_rays(data, &rayC, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win, data->tex[0]->img_ptr, 0, 0);
}

// void	cast_tex(t_data *data, t_rayC *rayC)
// {
// 	double	step;
// 	double	texPos;
// 	int		y;
// 	int		texY;

// 	step = 1.0 * data->tex->height * rayC->lineHeight;
// 	texPos = (rayC->drawStart - SCREEN_HEIGHT / 2 + rayC->lineHeight / 2) * step;
// 	y = rayC->drawStart;
// 	while (y < rayC->drawEnd)
// 	{
// 		texY = (int)texPos;
// 		texPos += step;

// 		//Uint32 color = texture[texNum][texHeight * texY + texX];
// 		//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
// 		//if(side == 1) color = (color >> 1) & 8355711;
// 		//buffer[y][x] = color;
// 	}
// }
