#include "../../inc/cub3d.h"

static bool		is_north_or_south_pos(t_data *data, char c)
{
	if (c == 'N')
	{
		data->dirX = 1;
		data->dirY = 0;
		data->planeX = 0;
		data->planeY = 0.66;
		return (true);
	}
	else if (c == 'S')
	{
		data->dirX = -1;
		data->dirY = 0;
		data->planeX = 0;
		data->planeY = -0.66;
		return (true);
	}
	return (false);
}

static bool		is_west_or_esth_pos(t_data *data, char c)
{
	if (c == 'W')
	{
		data->dirX = 0;
		data->dirY = -1;
		data->planeX = -0.66;
		data->planeY = 0;
		return (true);
	}
	else if (c == 'E')
	{
		data->dirX = 0;
		data->dirY = 1;
		data->planeX = 0.66;
		data->planeY = 0;
		return (true);
	}
	return (false);
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
				data->posX = x + 0.5;
				data->posY = y + 0.5;
				data->map[x][y] = '0';
				return ;
			}
			y++;
		}
		x++;
	}
}

static void	textures_init(t_data *data, int i)
{
	data->tex[i].img = NULL;
	
	data->tex[i].img = mlx_xpm_file_to_image(data->mlx,
		data->tex[i].path, &data->tex[i].width, &data->tex[i].height);
	data->tex[i].addr = (int *)mlx_get_data_addr(data->tex[i].img,
		&data->tex[i].bpp, &data->tex[i].size_line, &data->tex[i].endian);
	data->texture[i] = malloc(sizeof(int) * 4096);
}

void	fill_textures(t_data *data)
{
	t_tex	*tmp;
	int		x;
	int		y;
	int		i;

	i = 0;
	tmp = data->tex;


	tmp[0].path = data->path_no;
	printf("%s\n\n", tmp[0].path);
	tmp[1].path = data->path_so;
	printf("%s\n\n", tmp[1].path);
	tmp[2].path = data->path_we;
	printf("%s\n\n", tmp[2].path);
	tmp[3].path = data->path_ea;
	printf("%s\n\n", tmp[3].path);
	
	while (i < 4)
	{		
		textures_init(data, i);
		y = 0;
		while (y < data->tex[i].height)
		{
			x = 0;
			while (x < data->tex[i].width)
			{
				data->texture[i][data->tex[i].width * y + x] =
					data->tex[i].addr[data->tex[i].width * y + x];
				x++;
			}
			y++;
		}
		mlx_destroy_image(data->mlx, data->tex[i].img);
		i++;
	}
}

void	game_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->mlx_win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub");
	if (!data->mlx_win)
	{
		write(2, "Mlx initialisation failed\n", 26);
		exit(1);
	}
	data->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->addr = (int *)mlx_get_data_addr(data->img,
			&data->bpp, &data->line_length, &data->endian);

	fill_textures(data);
	printf("TEXT -> INIT\n");
	player_pos_init(data);
	printf("PLAYER POS -> INIT\n\n");
}