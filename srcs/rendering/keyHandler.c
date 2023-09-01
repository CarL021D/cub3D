#include "../../inc/cub3d.h"

static void	free_all_and_exit(t_data *data)
{
	if (data->tex[0].img != NULL)
		mlx_destroy_image(data->mlx, data->tex[0].img);
	if (data->tex[1].img != NULL)
		mlx_destroy_image(data->mlx, data->tex[1].img);
	if (data->tex[2].img != NULL)
		mlx_destroy_image(data->mlx, data->tex[2].img);
	if (data->tex[3].img != NULL)
		mlx_destroy_image(data->mlx, data->tex[3].img);
	mlx_destroy_window(data->mlx, data->mlx_win);
    mlx_destroy_display(data->mlx);
	exit(EXIT_SUCCESS);
}

int     keys_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		free_all_and_exit(data);
	if (move_forward(data, keycode) || move_backward(data, keycode)
		|| move_left(data, keycode) || move_right(data, keycode)
		|| rotate_left(data, keycode) || rotate_right(data, keycode))
	{
		draw_on_screen(data);
		return (1);
	}
	return (0);
}