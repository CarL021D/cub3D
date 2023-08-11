#include "inc/cub3d.h"

int	run_rayCast_game(t_rayC *data)
{
	t_rayC		rayC;
	uint32_t    x;
	int32_t		texX;

	x = 0;
	while (x < MAP_WIDTH)
	{
		member_init(rayC);
		calculate_step_and_side_dist(rayC);
		dda(rayC);
		ray_dist_init(rayC);
		caluclate_ray_dist(rayC);
		get_wallX(rayC);
		texX = get_textX(rayC);
		draw_rays(rayC, texX);
		x++;
	}
	return (1);
}