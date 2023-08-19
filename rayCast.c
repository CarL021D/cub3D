#include "inc/cub3d.h"

int	run_rayCast(t_data *data)
{
	t_rayC			rayC;
	unsigned int    x;
	// int32_t		texX;

	x = 0;
	while (x < MAP_WIDTH)
	{
		member_init(data, &rayC);
		init_step_and_side_dist(data, &rayC);
		dda(&rayC);
		ray_dist_init(&rayC);
		get_wallX(data, &rayC);
		get_textX(data, &rayC);
		// draw_rays(data, &rayC);
		x++;
	}
	return (1);
}