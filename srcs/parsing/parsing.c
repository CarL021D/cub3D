/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imessaad <imessaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:50:50 by imessaad          #+#    #+#             */
/*   Updated: 2023/09/02 23:52:18 by imessaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_check_walls_2(char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i] && map[i + 1])
	{
		j = 1;
		while (map[i][j])
		{
			if (non_wall(map[i][j]) == 1)
			{
				if (map[i + 1][j] == ' ' || map[i - 1][j] == ' '
					|| map[i][j + 1] == ' ' || map[i][j - 1] == ' ')
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	set_h_w(t_data *ptr)
{
	int	i;
	int	j;

	i = 0;
	ptr->map_width = ft_strlen(ptr->map[0]);
	while (ptr->map[i])
	{
		j = 0;
		while (ptr->map[i][j])
			j++;
		i++;
	}
	ptr->map_height = i;
}

int	ft_check_wt_data(t_data *ptr)
{
	if (!ptr)
		return (-1);
	if (check_files(ptr->path_no) == -1)
		return (-1);
	if (check_files(ptr->path_ea) == -1)
		return (-1);
	if (check_files(ptr->path_so) == -1)
		return (-1);
	if (check_files(ptr->path_we) == -1)
		return (-1);
	if (ft_check_colors(ptr->ceiling_color, ptr, 'c') == -1)
		return (printf("Error\nInvalid data\n"), -1);
	if (ft_check_colors(ptr->floor_color, ptr, 'f') == -1)
		return (printf("Error\nInvalid data\n"), -1);
	if (ft_check_map(ptr->map) == -1)
		return (printf("Error\nInvalid map\n"), -1);
	ft_delete_empty(ptr->map);
	if (ft_check_walls(ptr->map) == -1)
		return (printf("Error\nInvalid map\n"), -1);
	recreate_map(ptr->map);
	set_h_w(ptr);
	if (ft_check_walls_2(ptr->map) == -1)
		return (printf("Error\nInvalid map\n"), -1);
	return (1);
}

void	change_to_1(char **map)
{
	int	i;
	int	j;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

int	ft_check_valid_data(t_data *ptr)
{
	if (ft_check_wt_data(ptr) == -1)
		return (-1);
	change_to_1(ptr->map);
	fusion_colors(ptr);
	fusion_colors_f(ptr);
	return (1);
}
