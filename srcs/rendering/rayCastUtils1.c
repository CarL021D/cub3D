/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCastUtils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:55:35 by caboudar          #+#    #+#             */
/*   Updated: 2023/09/02 12:55:36 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	member_init(t_data *data, t_rayc *rayc, int x)
{
	rayc->cameraX = 2 * x / (double)(SCREEN_WIDTH) - 1;
	rayc->rayDirX = data->dirX + data->planeX * rayc->cameraX;
	rayc->rayDirY = data->dirY + data->planeY * rayc->cameraX;
	rayc->mapX = (int)(data->posX);
	rayc->mapY = (int)(data->posY);
	rayc->hit = 0;
	if (rayc->rayDirX == 0)
		rayc->deltaDistX = 1e30;
	else
		rayc->deltaDistX = fabs(1 / rayc->rayDirX);
	if (rayc->rayDirY == 0)
		rayc->deltaDistY = 1e30;
	else
		rayc->deltaDistY = fabs(1 / rayc->rayDirY);
}

void	init_step_and_side_dist(t_data *data, t_rayc *rayc)
{
	if (rayc->rayDirX < 0)
	{
		rayc->stepX = -1;
		rayc->sideDistX = (data->posX - rayc->mapX) * rayc->deltaDistX;
	}
	else
	{
		rayc->stepX = 1;
		rayc->sideDistX = (rayc->mapX + 1.0 - data->posX) * rayc->deltaDistX;
	}
	if (rayc->rayDirY < 0)
	{
		rayc->stepY = -1;
		rayc->sideDistY = (data->posY - rayc->mapY) * rayc->deltaDistY;
	}
	else
	{
		rayc->stepY = 1;
		rayc->sideDistY = (rayc->mapY + 1.0 - data->posY) * rayc->deltaDistY;
	}
}

void	dda(t_data *data, t_rayc *rayc)
{
	while (!rayc->hit)
	{
		if (rayc->sideDistX < rayc->sideDistY)
		{
			rayc->sideDistX += rayc->deltaDistX;
			rayc->mapX += rayc->stepX;
			rayc->side = 0;
		}
		else
		{
			rayc->sideDistY += rayc->deltaDistY;
			rayc->mapY += rayc->stepY;
			rayc->side = 1;
		}
		if (data->map[rayc->mapX][rayc->mapY] != '0')
			rayc->hit = 1;
	}
}

void	ray_dist_init(t_rayc *rayc)
{
	if (rayc->side == 0)
		rayc->perpWallDist = (rayc->sideDistX - rayc->deltaDistX);
	else
		rayc->perpWallDist = (rayc->sideDistY - rayc->deltaDistY);
	rayc->lineHeight = (int)(SCREEN_HEIGHT / rayc->perpWallDist);
	rayc->drawStart = -rayc->lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (rayc->drawStart < 0)
		rayc->drawStart = 0;
	rayc->drawEnd = rayc->lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (rayc->drawEnd >= SCREEN_HEIGHT)
		rayc->drawEnd = SCREEN_HEIGHT - 1;
}
