#include "inc/cub3d.h"

static void		mlx_init(t_mlx *mlx)
{
	data->mlx_ptr = mlx_init();
	data->win = screen(data->mlx_ptr, MAP_HEIGHT, MAP_WIDTH, "Cub");
	if (!data->win)
	{
		write(2, "Mlx initialisation failed\n", 26);
		exit(1);
	}
}

void	game_init(t_data *data, t_rayC *rayC)
{
	mlx_init(data);
	data_init()
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

}