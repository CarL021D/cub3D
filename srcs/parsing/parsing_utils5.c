/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imessaad <imessaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:35:25 by imessaad          #+#    #+#             */
/*   Updated: 2023/09/02 15:22:37 by imessaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_check_items_map(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	if (count > 1)
		return (-1);
	else if (count == 0)
		return (2);
	else
		return (1);
}

int	ft_check_map(char **map)
{
	if (!map)
		return (-1);
	if (ft_check_characters_map(map) == -1)
		return (-1);
	if (ft_check_empty_line_map(map) == -1)
		return (-1);
	if ((!((ft_check_items_map(map, 'N') == 2)
				^ (ft_check_items_map(map, 'S') == 2)
				^ (ft_check_items_map(map, 'E') == 2)
				^ (ft_check_items_map(map, 'W') == 2)))
		|| (ft_check_items_map(map, 'N') == -1
			|| ft_check_items_map(map, 'S') == -1
			|| ft_check_items_map(map, 'E') == -1
			|| ft_check_items_map(map, 'W') == -1))
		return (-1);
	return (1);
}

int	non_wall(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (-1);
}

int	ft_check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (non_wall(map[i][j]) == 1 && (i == 0 || j == 0
				|| map[i + 1] == NULL || map[i][j + 1] == '\0'))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_delete_empty(char **map)
{
	int		i;
	char	*tmp;

	i = 0;
	while (map[i])
	{
		tmp = skip_all_spaces(map[i]);
		if (tmp && tmp[0] == '\0')
		{
			free(map[i]);
			map[i] = NULL;
		}
		i++;
	}
}
