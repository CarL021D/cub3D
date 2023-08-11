static void	free_all_and_quit(t_mlx *mlx)
{
	if (mlx->img[0] != NULL)
		mlx_destroy_image(mlx_ptr, mlx->img[0]);
	if (mlx->img[1] != NULL)
		mlx_destroy_image(mlx_ptr, mlx->img[1]);
	if (mlx->img[2] != NULL)
		mlx_destroy_image(mlx_ptr, mlx->img[2]);
	if (mlx->img[3] != NULL)
		mlx_destroy_image(mlx_ptr, mlx->img[3]);
	mlx_destroy_window(mlx, mlx->win);
    mlx_destroy_display(mlx);
	exit(EXIT_SUCCESS);
}

int     keys_handler(int key, t_mlx *data)
{
	if (key == XK_Escape)
		free_all_and_quit(data->mlx);
	if (move_forward(data, keycode) || move_backward(data, keycode)
		|| move_left(data, keycode) || move_right(data, keycode)
		|| rotate_left(data, keycode) || rotate_right(data, keycode))
			return (1)
	return (0);
}