/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerRotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:38:15 by caboudar          #+#    #+#             */
/*   Updated: 2023/09/02 12:41:08 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	rotate_left(t_data *data, int keycode)
{
	double	old_dir_x;
	double	old_plane_x;

	if (keycode != ROTATE_LEFT_KEY)
		return (false);
	old_dir_x = data->dirX;
	data->dirX = data->dirX * cos(-ROT_SPEED) - data->dirY * sin(-ROT_SPEED);
	data->dirY = old_dir_x * sin(-ROT_SPEED) + data->dirY * cos(-ROT_SPEED);
	old_plane_x = data->planeX;
	data->planeX = data->planeX * cos(-ROT_SPEED)
		- data->planeY * sin(-ROT_SPEED);
	data->planeY = old_plane_x * sin(-ROT_SPEED)
		+ data->planeY * cos(-ROT_SPEED);
	return (true);
}

bool	rotate_right(t_data *data, int keycode)
{
	double	old_dir_x;
	double	old_plane_x;

	if (keycode != ROTATE_RIGHT_KEY)
		return (false);
	old_dir_x = data->dirX;
	data->dirX = data->dirX * cos(ROT_SPEED) - data->dirY * sin(ROT_SPEED);
	data->dirY = old_dir_x * sin(ROT_SPEED) + data->dirY * cos(ROT_SPEED);
	old_plane_x = data->planeX;
	data->planeX = data->planeX * cos(ROT_SPEED)
		- data->planeY * sin(ROT_SPEED);
	data->planeY = old_plane_x * sin(ROT_SPEED)
		+ data->planeY * cos(ROT_SPEED);
	return (true);
}
