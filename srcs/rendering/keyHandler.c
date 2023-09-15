/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyHandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imessaad <imessaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:41:39 by caboudar          #+#    #+#             */
/*   Updated: 2023/09/02 20:35:37 by imessaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	free_and_exit(t_data *data)
{
	if (data->texture[0] != NULL)
		free(data->texture[0]);
	if (data->texture[1] != NULL)
		free(data->texture[1]);
	if (data->texture[2] != NULL)
		free(data->texture[2]);
	if (data->texture[3] != NULL)
		free(data->texture[3]);
	if (data->img != NULL)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx_win != NULL)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx != NULL)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_(data);
	exit(EXIT_FAILURE);
	return (0);
}

int	keys_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		free_and_exit(data);
	if (move_forward(data, keycode) || move_backward(data, keycode)
		|| move_left(data, keycode) || move_right(data, keycode)
		|| rotate_left(data, keycode) || rotate_right(data, keycode))
	{
		draw_on_screen(data);
		return (1);
	}
	return (0);
}
