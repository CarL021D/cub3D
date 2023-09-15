/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:36:26 by caboudar          #+#    #+#             */
/*   Updated: 2023/09/02 21:25:48 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	rayc_init(t_rayc *rayc)
{
	rayc->map_x = 0;
	rayc->map_y = 0;
	rayc->raydir_x = 0;
	rayc->raydir_y = 0;
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
			data->addr[SCREEN_WIDTH * y + x] = data->pix_color[y][x];
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
		rayc.tex_num = data->map[rayc.map_x][rayc.map_y] - 1 - '0';
		get_wall_x(data, &rayc);
		get_text_x(&rayc);
		draw_rays(data, &rayc, x);
		x++;
	}
	draw_pix_on_wall(data);
	return (1);
}
