#include "../inc/cub3d.h"

static char *sethPathStr(char *str)
{
	char *ret;
	int	 i = 0;
	int len = 0;

	while (str[len])
		len++;
	ret = malloc(sizeof(char) * len + 1);
	i = -1;
	while (str[++i])
		ret[i] = str[i];
	ret[i] = '\0';
	return (ret);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_data	data;
	

	data.map = malloc(sizeof(char *) * 9);
	for (int i = 0; i < 8; i++)
		data.map[i] = malloc(sizeof(char) * 8 + 1);

	// Set borders to '1'
	for (int i = 0; i < 8; i++) {
		data.map[i][0] = '1';
		data.map[i][7] = '1';
		data.map[0][i] = '1';
		data.map[7][i] = '1';
		data.map[i][8] = '\0';
	}
	data.map[8] = NULL;

	// Set interior to '0'
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 7; j++) {
			data.map[i][j] = '0';
		}
	}
	data.map[1][1] = 'N';
	// Print the data.map
	for (int i = 0; data.map[i]; i++) {
		for (int j = 0; data.map[i][j]; j++) {
			printf("%c ", data.map[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	data.path_no = sethPathStr("./assets/north_wall.xpm");
	data.path_so = sethPathStr("./assets/south_wall.xpm");
	data.path_we = sethPathStr("./assets/west_wall.xpm");
	data.path_ea = sethPathStr("./assets/east_wall.xpm");

	data.ceilingColor = 0xF0F8FF;
	data.floorColor = 0x808080;
	// data.wallColor = 0xFF0FF;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// Parsing;
	game_init(&data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, keys_handler, &data);
	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, keys_handler, &data);
	mlx_loop_hook(data.mlx, draw_on_screen, &data);
	mlx_loop(data.mlx);


	write(1, "\nEXIT\n", 6);
// 0 < drawstart 		ceilling
// drawStart < drawEnd	wall
// drawEnd < lowScreen	 define WINHEIGHT

}
