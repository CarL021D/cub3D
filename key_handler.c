static void	free_all_and_quit(t_mlx *mlx)
{


	mlx_destroy_window(mlx, mlx->win);
    mlx_destroy_display(mlx);
	exit(0);
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