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

int     keys_handler(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		free_all_and_quit(mlx);
	if (move_forward(rayC, keycode) || move_backward(rayC, keycode)
		|| move_left(rayC, keycode) || move_right(rayC, keycode)
		|| rotate_left(rayC, keycode) || rotate_right(rayC, keycode))
			return (1)
	return (0);
}