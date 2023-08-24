#include "../../inc/cub3d.h"

static bool		is_north_or_south_pos(t_data *data, char c)
{
	if (c != 'N' || c != 'S')
		return (false);
	else if (c == 'N')
	{
		data->dirX = 1;
		data->dirY = 0;
		data->planeX = 0;
		data->planeY = 0.66;
	}
	else if (c == 'S')
	{
		data->dirX = -1;
		data->dirY = 0;
		data->planeX = 0;
		data->planeY = -0.66;
	}
	return (true);
}


static bool		is_west_or_esth_pos(t_data *data, char c)
{
	if (c != 'W' || c != 'E')
		return (false);
	else if (c == 'W')
	{
		data->dirX = 0;
		data->dirY = -1;
		data->planeX = -0.66;
		data->planeY = 0;
	}
	else if (c == 'E')
	{
		data->dirX = 0;
		data->dirY = 1;
		data->planeX = 0.66;
		data->planeY = 0;
	}
	return (true);
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
				data->posX = x;
				data->posY = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	textures_init(t_data *data)
{
	if (i == 0)
		data->tex->img_ptr = mlx_xpm_file_to_img(data->mlx_ptr,
			data->path_no, &data->tex.width, &data->tex.height);
	if (i == 1)
		data->tex->img_ptr = mlx_xpm_file_to_img(data->mlx_ptr,
			data->path_so, &data->tex.width, &data->tex.height);
	if (i == 2)
		data->tex->img_ptr = mlx_xpm_file_to_img(data->mlx_ptr,
			data->path_we, &data->tex.width, &data->tex.height);
	if (i == 3)
		data->tex->img_ptr = mlx_xpm_file_to_img(data->mlx_ptr,
			data->path_ea, &data->tex.width, &data->tex.height);
	if (data->tex->img_ptr == NULL)
			// Free and exit

	data->text.addr = (int *)mlx_get_data_addr(data->text.img,
		&data->text.bpp, &data->text.size_line, &data->text.endian);
}

void	fill_textures(t_data *data)
{
	t_tex	*tmp;
	int		x;
	int		y;
	int		i;

	i = 0;
	tmp = data->tex;
	while (i < 4)
	{
		data->tex[i]->img_ptr = NULL;
		data->text[i].addr = NULL;

		fill_textures(data);		
		
		x = 0;
		while (x < data->tex[i]->width)
		{
			y = 0;
			while (y < data->tex[i]->height)
			{
				data->texture[i][data->tex[i]->width * y + x] =
					data->tex[i]->addr[data->tex[i]->width * y + x];
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

				y++;
			}
			x++;
		}
		mlx_destroy_image(data->mlx_ptr, data->tex[i].img_ptr);
		i++;
	}
}

void	game_init(t_data *data)
{
	int		i;

	data->mlx->mlx_ptr = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx_ptr, SCREEN_HEIGHT, SCREEN_WIDTH, "Cub");
	if (!data->mlx->win)
	{
		write(2, "Mlx initialisation failed\n", 26);
		exit(1);
	}
	// player_pos_init(data);
	i = 0;
	while (i < 4)
		data->text
	
	// data_init();
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);



	// player_pos_init(data);
}