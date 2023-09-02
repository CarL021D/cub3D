/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerPosInit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:43:02 by caboudar          #+#    #+#             */
/*   Updated: 2023/09/02 15:24:01 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static bool	is_north_or_south_pos(t_data *data, char c)
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

static bool	is_west_or_esth_pos(t_data *data, char c)
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

void	player_pos_init(t_data *data)
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
