#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_data	data;
	t_mlx	mlx_struct;
	t_tex	tex_struct;

	data.mlx = &mlx_struct;
	data.tex = &tex_struct;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	data.map_height = 24;
	data.map_width = 24;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Parsing;
	game_init(&data);
	mlx_hook(data.mlx->mlx_ptr, KeyPress, KeyPressMask, keys_handler, &data);
	mlx_hook(data.mlx->mlx_ptr, KeyRelease, KeyReleaseMask, keys_handler, data.mlx);
	mlx_loop_hook(data.mlx->mlx_ptr, run_rayCast, &data);
	// mlx_loop();


// 0 < drawstart 		ceilling
// drawStart < drawEnd	wall
// drawEnd < lowScreen	 define WINHEIGHT



// for(int y = 0; y < texHeight; y++)
//   {
// 	int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
// 	//int xcolor = x * 256 / texWidth;
// 	int ycolor = y * 256 / texHeight;
// 	int xycolor = y * 128 / texHeight + x * 128 / texWidth;
// 	texture[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red texture with black cross
// 	texture[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
// 	texture[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
// 	texture[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
// 	texture[4][texWidth * y + x] = 256 * xorcolor; //xor green
// 	texture[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
// 	texture[6][texWidth * y + x] = 65536 * ycolor; //red gradient
// 	texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture

}
