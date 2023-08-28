#include "../../inc/cub3d.h"

void rayC_init(t_rayC *rayC)
{
	rayC->hit = 0;
	rayC->mapX = 0;
	rayC->mapY = 0;
	rayC->rayDirX = 0;
	rayC->rayDirY = 0;
}

int	draw_on_screen(t_data *data)
{
	t_rayC			rayC;
	int				x;

// - - - - - - - 
	data->current_buffer = 0;
// - - - - - - - 

	x = 0;
	rayC_init(&rayC);
	while (x < SCREEN_WIDTH)
	{
		member_init(data, &rayC, x);
		init_step_and_side_dist(data, &rayC);
		dda(data, &rayC);
		ray_dist_init(&rayC);
		// get_wallX(data, &rayC);
		// get_textX(data, &rayC);
		draw_rays(data, &rayC, x);
		x++;
	}
	
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->buffer[0]->img, 0, 0);
	// data->current_buffer = (data->current_buffer + 1) % 2;
	return (1);
}

// void	cast_tex(t_data *data, t_rayC *rayC)
// {
// 	double	step;
// 	double	texPos;
// 	int		y;
// 	int		texY;

// 	step = 1.0 * data->tex->height * rayC->lineHeight;
// 	texPos = (rayC->drawStart - SCREEN_HEIGHT / 2 + rayC->lineHeight / 2) * step;
// 	y = rayC->drawStart;
// 	while (y < rayC->drawEnd)
// 	{
// 		texY = (int)texPos;
// 		texPos += step;

// 		//Uint32 color = texture[texNum][texHeight * texY + texX];
// 		//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
// 		//if(side == 1) color = (color >> 1) & 8355711;
// 		//buffer[y][x] = color;
// 	}
// }




// int draw_on_screen(t_data *data)
// {
//     // Render loop
//     // while (1) {

//     // Clear the buffer
//     memset(data->buffer[data->current_buffer]->addr, 0, data->buffer[data->current_buffer]->size_line * SCREEN_WIDTH);
//     // keys_handler(data);
//     // Render the walls
//     for (int x = 0; x < SCREEN_WIDTH; x++)
//     {
//         for (int i = 0; i < 5; i++) {
//             double cameraX = (2 * x + i - 2) / (double)(SCREEN_WIDTH * 2) - 1;
//             double rayDirX = cos(data->dirX + cameraX * data->fov);
//             double rayDirY = sin(data->dirX + cameraX * data->fov);
//             int mapX = (int)data->posX;
//             int mapY = (int)data->posY;
//             double sideDistX, sideDistY;
//             if (rayDirX == 0)
//                 rayDirX = 1;
//             if (rayDirY == 0)
//                 rayDirY = 1;
//             double deltaDistX = fabs(1 / rayDirX);
//             double deltaDistY = fabs(1 / rayDirY);
//             int stepX, stepY;
//             int hit = 0;
//             int side;

//             if (rayDirX < 0) {
//                 stepX = -1;
//                 sideDistX = (data->posX - mapX) * deltaDistX;
//             } else {
//                 stepX = 1;
//                 sideDistX = (mapX + 1.0 - data->posX) * deltaDistX;
//             }
//             if (rayDirY < 0) {
//                 stepY = -1;
//                 sideDistY = (data->posY - mapY) * deltaDistY;
//             } else {
//                 stepY = 1;
//                 sideDistY = (mapY + 1.0 - data->posY) * deltaDistY;
//             }
// while (!hit) {
//                 if (sideDistX < sideDistY) {
//                     sideDistX += deltaDistX;
//                     mapX += stepX;
//                     side = 0;
//                 } else {
//                     sideDistY += deltaDistY;
//                     mapY += stepY;
//                     side = 1;
//                 }
//                 if (data->map[mapX][mapY] == '1')
//                     hit = 1;
//             }
//             double perpWallDist;
//             if (side == 0)
//                 perpWallDist = fabs((mapX - data->posX + (1 - stepX) / 2) / rayDirX);
//             else
//                 perpWallDist = fabs((mapY - data->posY + (1 - stepY) / 2) / rayDirY);
//             double distToWall = perpWallDist * cos((data->dirX - (data->dirX + cameraX * data->fov)) * M_PI / 180.0);
//             int wall_height = (int)(SCREEN_WIDTH / (distToWall * cos(cameraX * data->fov)));
//             int draw_start = SCREEN_WIDTH / 2 - wall_height / 2;
//             if (draw_start < 0)
//                 draw_start = 0;
//             int draw_end = wall_height / 2 + SCREEN_WIDTH / 2;
//             if (draw_end >= SCREEN_WIDTH)
//                 draw_end = SCREEN_WIDTH - 1;
//             // Calculate the shaded color for the wall
//             int wallColor = 0xFF00FF;
//             for (int y = 0; y < SCREEN_WIDTH; y++) {
//                 if (y < draw_start)
//                     data->buffer[data->current_buffer]->addr[y * SCREEN_WIDTH + x] = data->ceiling_color;
//                 else if (y > draw_end)
//                     data->buffer[data->current_buffer]->addr[y * SCREEN_WIDTH + x] = data->floor_color;
//                 else
//                     data->buffer[data->current_buffer]->addr[y * SCREEN_WIDTH + x] = wallColor;
//             }
//         }
//         }
//         mlx_put_image_to_window(data->mlx, data->mlx_win, data->buffer[data->current_buffer]->img, 0, 0);
//         data->current_buffer = (data->current_buffer + 1) % 2;
// 		return (1);
// }

