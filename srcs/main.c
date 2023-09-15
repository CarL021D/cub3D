/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imessaad <imessaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:02:38 by caboudar          #+#    #+#             */
/*   Updated: 2023/09/02 22:10:11 by imessaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	int		fd;
	t_data	*data;

	if (ac == 2)
	{
		fd = open_and_check(av);
		if (fd == -1)
			return (-1);
		data = create_and_set(fd);
		if (ft_check_valid_data(data) == -1)
			return (ft_free_(data), close(fd), -1);
		close(fd);
		game_init(data);
		mlx_hook(data->mlx_win, KeyPress, KeyPressMask, keys_handler, data);
		mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, keys_handler, data);
		mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask,
			free_and_exit, data);
		mlx_loop_hook(data->mlx, draw_on_screen, data);
		mlx_loop(data->mlx);
	}	
}
