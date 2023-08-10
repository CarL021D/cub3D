

void	get_wallX(t_rayC *rayC)
{
	if (rayC.side == 0)
		rayC.wallX = rayC.posY + rayC.perpWallDist * rayC.dirY;
	else
		rayC.wallX = rayC.posX + rayC.perpWallDist * rayC.dirX;
	rayC.wallX -= floor(rayC.wallX); 
}

double	get_textX(t_rayC *rayC, t_tex *tex)
{
	rayC.texX = int(rayC.wallX * double(tex.width))
	if (rayC.side == && rayC.dirX > 0)
		texX = tex.width - texX - 1;
	if (rayC.side == 1 && rayC.dirY < 0)
		texX = tex.width - texX - 1;
	return (texX);
}

void	draw_ray(t_rayC *rayC, t_tex *tex, int32_t texX)
{
	int		y;
	int		texY;
	double	step;
	double	texPos;

	y = rayC.drawStart;
	step = 1.0 * tex.height / rayC.lineHeight;
	texPos = (rayC.drawStart - MAP_HEIGHT / 2 + rayC.lineHeight / 2) * step;
	while (y < rayC.drawEnd)
	{
		texY = (int)texPos & (tex.height - 1);
		texPos += step;

		// TO DO
		Uint32 color = texture[texNum][texHeight * texY + texX];
		
	}
}
