#include "inc/cub3d.h"

int	run_rayCast_game(t_rayC *rayC)
{
	uint32_t    x;
	int32_t		texX;

	x = 0;
	while (x < MAP_WIDTH)
	{
		member_init(rayC);
		calculate_step_and_side_dist(rayC);
		dda(rayC);
		ray_dist_init(t_rayC *rayC);
		caluclate_ray_dist(t_rayC *rayC);
		get_wallX(rayC);
		texX = get_textX(rayC);
		draw_rays(rayC, texX);
		
		x++;
	}
	return (1);
}