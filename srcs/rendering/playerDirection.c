/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerDirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:56:34 by caboudar          #+#    #+#             */
/*   Updated: 2023/09/02 12:59:55 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	move_forward(t_data *data, int keycode)
{
	if (keycode != KEY_UP)
		return (false);
	if (data->map[(int)(data->posX + data->dirX * ROT_SPEED)]
		[(int)(data->posY)] == '0')
			data->posX += data->dirX * ROT_SPEED;
	if (data->map[(int)(data->posX)]
		[(int)(data->posY + data->dirY * ROT_SPEED)] == '0')
			data->posY += data->dirY * ROT_SPEED;
	return (true);
}

bool	move_backward(t_data *data, int keycode)
{
	if (keycode != KEY_DOWN)
		return (false);
	if (data->map[(int)(data->posX - data->dirX * ROT_SPEED)]
		[(int)(data->posY)] == '0')
			data->posX -= data->dirX * ROT_SPEED;
	if (data->map[(int)(data->posX)]
		[(int)(data->posY - data->dirY * ROT_SPEED)] == '0')
			data->posY -= data->dirY * ROT_SPEED;
	return (true);
}

bool	move_left(t_data *data, int keycode)
{
	if (keycode != KEY_LEFT)
		return (false);
	if (data->map[(int)(data->posX - data->planeX * ROT_SPEED)]
		[(int)(data->posY)] == '0')
			data->posX -= data->planeX * ROT_SPEED;
	if (data->map[(int)(data->posX)]
		[(int)(data->posY - data->planeY * ROT_SPEED)] == '0')
			data->posY -= data->planeY * ROT_SPEED;
	return (true);
}

bool	move_right(t_data *data, int keycode)
{
	if (keycode != KEY_RIGHT)
		return (false);
	if (data->map[(int)(data->posX + data->planeX * ROT_SPEED)]
		[(int)(data->posY)] == '0')
			data->posX += data->planeX * ROT_SPEED;
	if (data->map[(int)(data->posX)]
		[(int)(data->posY + data->planeY * ROT_SPEED)] == '0')
			data->posY += data->planeY * ROT_SPEED;
	return (true);
}
