/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameInit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imessaad <imessaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:53:34 by caboudar          #+#    #+#             */
/*   Updated: 2023/09/02 23:32:52 by imessaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	textures_init(t_data *data, int i)
{
	if (i == 0)
		data->tex[0].path = data->path_ea;
	if (i == 1)
		data->tex[1].path = data->path_we;
	if (i == 2)
		data->tex[2].path = data->path_no;
	if (i == 3)
		data->tex[3].path = data->path_so;
	data->tex[i].img = NULL;
	if (!data->tex[i].path)
	{
		write(2, "Error\nTexture initialization failed\n", 36);
		free_and_exit(data);
	}
	data->tex[i].img = mlx_xpm_file_to_image(data->mlx,
			data->tex[i].path, &data->tex[i].width, &data->tex[i].height);
	data->tex[i].addr = (int *)mlx_get_data_addr(data->tex[i].img,
			&data->tex[i].bpp, &data->tex[i].size_line, &data->tex[i].endian);
	data->texture[i] = malloc(sizeof(int) * 4096);
}

static void	fill_textures(t_data *data)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	while (i < 4)
	{		
		textures_init(data, i);
		y = 0;
		while (y < data->tex[i].height)
		{
			x = 0;
			while (x < data->tex[i].width)
			{
				data->texture[i][data->tex[i].width * y + x]
					= data->tex[i].addr[data->tex[i].width * y + x];
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
	{
		write(2, "Mlx initialisation failed\n", 26);
		free_and_exit(data);
	}
	data->mlx_win = mlx_new_window(data->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "Cub");
	if (!data->mlx_win)
	{
		write(2, "Mlx window initialisation failed\n", 33);
		free_and_exit(data);
	}
	data->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->addr = (int *)mlx_get_data_addr(data->img,
			&data->bpp, &data->line_length, &data->endian);
	fill_textures(data);
	player_pos_init(data);
}
