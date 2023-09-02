/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyHandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:41:39 by caboudar          #+#    #+#             */
/*   Updated: 2023/09/02 12:41:46 by caboudar         ###   ########.fr       */
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
// - - - - - - - - - - - - - - -

	// free map
	int i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map[i]);
	free(data->map);

	// free path
	if (data->path_no != NULL)
		free(data->path_no);
	if (data->path_so != NULL)
		free(data->path_so);
	if (data->path_we != NULL)
		free(data->path_we);
	if (data->path_ea != NULL)
		free(data->path_ea);
// - - - - - - - - - - - - - - -

	if (data->img != NULL)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx_win != NULL)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx != NULL)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
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
