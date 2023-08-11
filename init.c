#include "inc/cub3d.h"

void	game_init(t_data *data)
{
	t_mlx	mlx_struct;
	t_tex	tex_struct;

	data->mlx = &mlx_struct;
	data->rayC = &tex_struct;
	data->mlx->mlx_ptr = mlx_init();
	data->mlx->win = screen(data->mlx->mlx_ptr, MAP_HEIGHT, MAP_WIDTH, "Cub");
	if (!data->mlx->win)
	{
		write(2, "Mlx initialisation failed\n", 26);
		exit(1);
	}
	
	// data_init();
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

}