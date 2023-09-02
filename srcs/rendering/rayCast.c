/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:36:26 by caboudar          #+#    #+#             */
/*   Updated: 2023/09/02 12:45:46 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	rayc_init(t_rayc *rayc)
{
	rayc->mapX = 0;
	rayc->mapY = 0;
	rayc->rayDirX = 0;
	rayc->rayDirY = 0;
}

static void	draw_pix_on_wall(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			data->addr[SCREEN_WIDTH * y + x] = data->pixColor[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	draw_on_screen(t_data *data)
{
	t_rayc	rayc;
	int		x;

	x = 0;
	rayc_init(&rayc);
	while (x < SCREEN_WIDTH)
	{
		member_init(data, &rayc, x);
		init_step_and_side_dist(data, &rayc);
		dda(data, &rayc);
		ray_dist_init(&rayc);
		rayc.texNum = data->map[rayc.mapX][rayc.mapY] - 1 - '0';
		get_wall_x(data, &rayc);
		get_text_x(&rayc);
		draw_rays(data, &rayc, x);
		x++;
	}
	draw_pix_on_wall(data);
	return (1);
}
