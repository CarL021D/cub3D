/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerPosInit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:43:02 by caboudar          #+#    #+#             */
/*   Updated: 2023/09/02 21:21:29 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static bool	is_north_or_south_pos(t_data *data, char c)
{
	if (c == 'N')
	{
		data->dir_x = -1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = 0.66;
		return (true);
	}
	else if (c == 'S')
	{
		data->dir_x = 1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = -0.66;
		return (true);
	}
	return (false);
}

static bool	is_west_or_esth_pos(t_data *data, char c)
{
	if (c == 'W')
	{
		data->dir_x = 0;
		data->dir_y = -1;
		data->plane_x = -0.66;
		data->plane_y = 0;
		return (true);
	}
	else if (c == 'E')
	{
		data->dir_x = 0;
		data->dir_y = 1;
		data->plane_x = 0.66;
		data->plane_y = 0;
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
				data->pos_x = x + 0.5;
				data->pos_y = y + 0.5;
				data->map[x][y] = '0';
				return ;
			}
			y++;
		}
		x++;
	}
}
