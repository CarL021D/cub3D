#include "../../inc/cub3d.h"

void rayC_init(t_rayC *rayC)
{
	rayC->mapX = 0;
	rayC->mapY = 0;
	rayC->rayDirX = 0;
	rayC->rayDirY = 0;
}

void	drawPixOnWall(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			data->addr[SCREEN_WIDTH * y + x] = data->pixColor[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	draw_on_screen(t_data *data)
{
	t_rayC	rayC;
	int		x;

// - - - - - - - 
	data->current_buffer = 0;
// - - - - - - - 

	x = 0;
	rayC_init(&rayC);
	while (x < SCREEN_WIDTH)
	{
		member_init(data, &rayC, x);
		init_step_and_side_dist(data, &rayC);
		dda(data, &rayC);
		ray_dist_init(&rayC);
		rayC.texNum = data->map[rayC.mapX][rayC.mapY] - 1 - '0';
		get_wallX(data, &rayC);
		get_textX(&rayC);
		draw_rays(data, &rayC, x);
		x++;
	}
	drawPixOnWall(data);
	return (1);
}
