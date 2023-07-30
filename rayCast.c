#include "inc/cub3d.h"

int	rayCast(t_rayC *rayC)
{
	uint32_t    x;
	x = 0;
	while (x < MAP_WIDTH)
	{
		member_init(rayC);
		calculate_step_and_side_dist(rayC);
		perform_dda(rayC);
		ray_dist_init(t_rayC *rayC);
		caluclate_ray_dist(t_rayC *rayC);
		x++;
	}
	return (1);
}