/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCastUtils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:55:35 by caboudar          #+#    #+#             */
/*   Updated: 2023/09/02 21:31:56 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	member_init(t_data *data, t_rayc *rayc, int x)
{
	rayc->camera_x = 2 * x / (double)(SCREEN_WIDTH) - 1;
	rayc->raydir_x = data->dir_x + data->plane_x * rayc->camera_x;
	rayc->raydir_y = data->dir_y + data->plane_y * rayc->camera_x;
	rayc->map_x = (int)(data->pos_x);
	rayc->map_y = (int)(data->pos_y);
	rayc->hit = 0;
	if (rayc->raydir_x == 0)
		rayc->delta_dist_x = 1e30;
	else
		rayc->delta_dist_x = fabs(1 / rayc->raydir_x);
	if (rayc->raydir_y == 0)
		rayc->delta_dist_y = 1e30;
	else
		rayc->delta_dist_y = fabs(1 / rayc->raydir_y);
}

void	init_step_and_side_dist(t_data *data, t_rayc *rayc)
{
	if (rayc->raydir_x < 0)
	{
		rayc->step_x = -1;
		rayc->side_dist_x = (data->pos_x - rayc->map_x) * rayc->delta_dist_x;
	}
	else
	{
		rayc->step_x = 1;
		rayc->side_dist_x = (rayc->map_x + 1.0 - data->pos_x)
			* rayc->delta_dist_x;
	}
	if (rayc->raydir_y < 0)
	{
		rayc->step_y = -1;
		rayc->side_dist_y = (data->pos_y - rayc->map_y) * rayc->delta_dist_y;
	}
	else
	{
		rayc->step_y = 1;
		rayc->side_dist_y = (rayc->map_y + 1.0 - data->pos_y)
			* rayc->delta_dist_y;
	}
}

void	dda(t_data *data, t_rayc *rayc)
{
	while (!rayc->hit)
	{
		if (rayc->side_dist_x < rayc->side_dist_y)
		{
			rayc->side_dist_x += rayc->delta_dist_x;
			rayc->map_x += rayc->step_x;
			rayc->side = 0;
		}
		else
		{
			rayc->side_dist_y += rayc->delta_dist_y;
			rayc->map_y += rayc->step_y;
			rayc->side = 1;
		}
		if (data->map[rayc->map_x][rayc->map_y] != '0')
			rayc->hit = 1;
	}
}

void	ray_dist_init(t_rayc *rayc)
{
	if (rayc->side == 0)
		rayc->perp_wall_dist = (rayc->side_dist_x - rayc->delta_dist_x);
	else
		rayc->perp_wall_dist = (rayc->side_dist_y - rayc->delta_dist_y);
	rayc->line_height = (int)(SCREEN_HEIGHT / rayc->perp_wall_dist);
	rayc->draw_start = -rayc->line_height / 2 + SCREEN_HEIGHT / 2;
	if (rayc->draw_start < 0)
		rayc->draw_start = 0;
	rayc->draw_end = rayc->line_height / 2 + SCREEN_HEIGHT / 2;
	if (rayc->draw_end >= SCREEN_HEIGHT)
		rayc->draw_end = SCREEN_HEIGHT - 1;
}
