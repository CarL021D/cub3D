#include "../../inc/cub3d.h"

static bool		is_north_or_south_pos(t_data *data, char c)
{
	if (c != 'N' || c != 'S')
		return (false);
	else if (c == 'N')
	{
		data->dirX = 1;
		data->dirY = 0;
		data->planeX = 0;
		data->planeY = 0.66;
	}
	else if (c == 'S')
	{
		data->dirX = -1;
		data->dirY = 0;
		data->planeX = 0;
		data->planeY = -0.66;
	}
	return (true);
}


static bool		is_west_or_esth_pos(t_data *data, char c)
{
	if (c != 'W' || c != 'E')
		return (false);
	else if (c == 'W')
	{
		data->dirX = 0;
		data->dirY = -1;
		data->planeX = -0.66;
		data->planeY = 0;
	}
	else if (c == 'E')
	{
		data->dirX = 0;
		data->dirY = 1;
		data->planeX = 0.66;
		data->planeY = 0;

	}
	return (true);
}

static void	player_pos_init(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (is_north_or_south_pos(data, data->map[x][y])
			|| is_west_or_esth_pos(data, data->map[x][y]))
			{
				data->posX = x;
				data->posY = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	game_init(t_data *data)
{
	data->mlx->mlx_ptr = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx_ptr, SCREEN_HEIGHT, SCREEN_WIDTH, "Cub");
	if (!data->mlx->win)
	{
		write(2, "Mlx initialisation failed\n", 26);
		exit(1);
	}
	// player_pos_init(data);

	
	// data_init();
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);



	// player_pos_init(data);
}