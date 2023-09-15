/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerDirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:56:34 by caboudar          #+#    #+#             */
/*   Updated: 2023/09/02 21:21:29 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	move_forward(t_data *data, int keycode)
{
	if (keycode != KEY_UP)
		return (false);
	if (data->map[(int)(data->pos_x + data->dir_x * ROT_SPEED)]
		[(int)(data->pos_y)] == '0')
			data->pos_x += data->dir_x * ROT_SPEED;
	if (data->map[(int)(data->pos_x)]
		[(int)(data->pos_y + data->dir_y * ROT_SPEED)] == '0')
			data->pos_y += data->dir_y * ROT_SPEED;
	return (true);
}

bool	move_backward(t_data *data, int keycode)
{
	if (keycode != KEY_DOWN)
		return (false);
	if (data->map[(int)(data->pos_x - data->dir_x * ROT_SPEED)]
		[(int)(data->pos_y)] == '0')
			data->pos_x -= data->dir_x * ROT_SPEED;
	if (data->map[(int)(data->pos_x)]
		[(int)(data->pos_y - data->dir_y * ROT_SPEED)] == '0')
			data->pos_y -= data->dir_y * ROT_SPEED;
	return (true);
}

bool	move_left(t_data *data, int keycode)
{
	if (keycode != KEY_LEFT)
		return (false);
	if (data->map[(int)(data->pos_x - data->plane_x * ROT_SPEED)]
		[(int)(data->pos_y)] == '0')
			data->pos_x -= data->plane_x * ROT_SPEED;
	if (data->map[(int)(data->pos_x)]
		[(int)(data->pos_y - data->plane_y * ROT_SPEED)] == '0')
			data->pos_y -= data->plane_y * ROT_SPEED;
	return (true);
}

bool	move_right(t_data *data, int keycode)
{
	if (keycode != KEY_RIGHT)
		return (false);
	if (data->map[(int)(data->pos_x + data->plane_x * ROT_SPEED)]
		[(int)(data->pos_y)] == '0')
			data->pos_x += data->plane_x * ROT_SPEED;
	if (data->map[(int)(data->pos_x)]
		[(int)(data->pos_y + data->plane_y * ROT_SPEED)] == '0')
			data->pos_y += data->plane_y * ROT_SPEED;
	return (true);
}
