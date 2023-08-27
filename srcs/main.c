#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_data	data;
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// data.map = malloc(sizeof(char *) * 5 + 1)
	// for (int i = 0; 

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Parsing;
	game_init(&data);
	mlx_hook(data.mlx->mlx_ptr, KeyPress, KeyPressMask, keys_handler, &data);
	mlx_hook(data.mlx->mlx_ptr, KeyRelease, KeyReleaseMask, keys_handler, data.mlx);
	mlx_loop_hook(data.mlx->mlx_ptr, launch_rays, &data);
	mlx_loop(data.mlx_ptr);


// 0 < drawstart 		ceilling
// drawStart < drawEnd	wall
// drawEnd < lowScreen	 define WINHEIGHT

}
