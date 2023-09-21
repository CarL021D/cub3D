/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCastUtils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:43:44 by caboudar          #+#    #+#             */
/*   Updated: 2023/09/21 19:52:19 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	get_wall_x(t_data *data, t_rayc *rayc)
{
	if (rayc->side == 0)
		rayc->wall_x = data->pos_y + rayc->perp_wall_dist * rayc->raydir_y;
	else
		rayc->wall_x = data->pos_x + rayc->perp_wall_dist * rayc->raydir_x;
	rayc->wall_x -= floor(rayc->wall_x);
}

void	get_text_x(t_rayc *rayc)
{
	rayc->tex_x = (int)(rayc->wall_x * (double)(TEXT_HEIGHT));
	if (rayc->side == 0 && rayc->raydir_x > 0)
		rayc->tex_x = TEXT_HEIGHT - rayc->tex_x - 1;
	if (rayc->side == 1 && rayc->raydir_y < 0)
		rayc->tex_x = TEXT_HEIGHT - rayc->tex_x - 1;
}

static int	get_pix_wall_color(t_data *data, t_rayc *rayc)
{
	int		current_color;

	current_color = 0;
	if (rayc->side == 1 && rayc->raydir_y > 0)
		current_color = data->texture[0][TEXT_HEIGHT
			* rayc->tex_y + rayc->tex_x];
	else if (rayc->side == 1 && rayc->raydir_y < 0)
			current_color = data->texture[1][TEXT_HEIGHT
			* rayc->tex_y + rayc->tex_x];
	else if (rayc->side == 0 && rayc->raydir_x > 0)
		current_color = data->texture[3][TEXT_HEIGHT
			* rayc->tex_y + rayc->tex_x];
	else if (rayc->side == 0 && rayc->raydir_x < 0)
		current_color = data->texture[2][TEXT_HEIGHT
			* rayc->tex_y + rayc->tex_x];
	return (current_color);
}

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_rays(t_data *data, t_rayc *rayc, int x)
{
	int		current_color;
	int		y;
	double	step;
	double	tex_pos;

	step = 1.0 * TEXT_HEIGHT / rayc->line_height;
	tex_pos = (rayc->draw_start - SCREEN_HEIGHT / 2
			+ rayc->line_height / 2) * step;
	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		if (y < rayc->draw_start)
			current_color = create_trgb(255, data->ceiling_r,
					data->ceiling_g, data->ceiling_b);
		else if (y > rayc->draw_end)
			current_color = create_trgb(255, data->floor_r,
					data->floor_g, data->floor_b);
		else
		{
			rayc->tex_y = (int)tex_pos & (TEXT_HEIGHT - 1);
			tex_pos += step;
			current_color = get_pix_wall_color(data, rayc);
		}
		data->pix_color[y][x] = current_color;
	}
}
