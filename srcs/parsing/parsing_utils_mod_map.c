/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_mod_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imessaad <imessaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:36:11 by imessaad          #+#    #+#             */
/*   Updated: 2023/09/02 15:03:51 by imessaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*str_space(int len)
{
	int		i;
	char	str[10000];

	i = 0;
	while (i < len)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (ft_strdup(str));
}

int	get_max_len(char **map)
{
	int				i;
	unsigned int	max;
	unsigned int	len;

	max = 0;
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

void	recreate_map(char **map)
{
	int				i;
	unsigned int	max;
	char			*tmp;
	char			*tmp_space;

	max = get_max_len(map);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) < max)
		{
			tmp = map[i];
			tmp_space = str_space(max - ft_strlen(map[i]));
			map[i] = ft_strjoin(tmp, tmp_space);
			free(tmp);
			free(tmp_space);
		}
		i++;
	}
}

void	assign_colors(int val, t_data *ptr, char c)
{
	if (c == 'c')
	{
		if (ptr->ceiling_r == -1)
			ptr->ceiling_r = val;
		else if (ptr->ceiling_g == -1)
			ptr->ceiling_g = val;
		else if (ptr->ceiling_b == -1)
			ptr->ceiling_b = val;
	}
	else if (c == 'f')
	{
		if (ptr->floor_r == -1)
			ptr->floor_r = val;
		else if (ptr->floor_g == -1)
			ptr->floor_g = val;
		else if (ptr->floor_b == -1)
			ptr->floor_b = val;
	}
}

int	ft_create_and_set_norm(t_data *ptr, char *after_space, char *line)
{
	if (ptr->nb_data <= 6)
	{
		if (!after_space)
		{
			free(line);
			return (-1);
		}
		check_lines(ptr, after_space);
	}
	return (1);
}
