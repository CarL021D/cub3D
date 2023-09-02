/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCastUtils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:43:44 by caboudar          #+#    #+#             */
/*   Updated: 2023/09/02 12:53:01 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	get_wall_x(t_data *data, t_rayc *rayc)
{
	if (rayc->side == 0)
		rayc->wallX = data->posY + rayc->perpWallDist * rayc->rayDirY;
	else
		rayc->wallX = data->posX + rayc->perpWallDist * rayc->rayDirX;
	rayc->wallX -= floor(rayc->wallX);
}

void	get_text_x(t_rayc *rayc)
{
	rayc->texX = (int)(rayc->wallX * (double)(TEXT_HEIGHT));
	if (rayc->side == 0 && rayc->rayDirX > 0)
		rayc->texX = TEXT_HEIGHT - rayc->texX - 1;
	if (rayc->side == 1 && rayc->rayDirY < 0)
		rayc->texX = TEXT_HEIGHT - rayc->texX - 1;
}

static int	get_pix_wall_color(t_data *data, t_rayc *rayc)
{
	int		current_color;

	if (rayc->side == 1 && rayc->rayDirY > 0)
		current_color = data->texture[0][TEXT_HEIGHT * rayc->texY + rayc->texX];
	else if (rayc->side == 1 && rayc->rayDirY < 0)
			current_color = data->texture[1][TEXT_HEIGHT
			* rayc->texY + rayc->texX];
	else if (rayc->side == 0 && rayc->rayDirX > 0)
		current_color = data->texture[3][TEXT_HEIGHT * rayc->texY + rayc->texX];
	else if (rayc->side == 0 && rayc->rayDirX < 0)
		current_color = data->texture[2][TEXT_HEIGHT * rayc->texY + rayc->texX];
	return (current_color);
}

void	draw_rays(t_data *data, t_rayc *rayc, int x)
{
	int		current_color;
	int		y;
	double	step;
	double	tex_pos;

	step = 1.0 * TEXT_HEIGHT / rayc->lineHeight;
	tex_pos = (rayc->drawStart - SCREEN_HEIGHT / 2
			+ rayc->lineHeight / 2) * step;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		if (y < rayc->drawStart)
			current_color = data->ceilingColor;
		else if (y > rayc->drawEnd)
			current_color = data->floorColor;
		else
		{
			rayc->texY = (int)tex_pos & (TEXT_HEIGHT - 1);
			tex_pos += step;
			current_color = get_pix_wall_color(data, rayc);
		}
		data->pixColor[y][x] = current_color;
		y++;
	}
}
