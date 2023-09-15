/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imessaad <imessaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:37:38 by imessaad          #+#    #+#             */
/*   Updated: 2023/09/02 20:30:25 by imessaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	set_struct_values(t_data *ptr)
{
	ptr->path_ea = NULL;
	ptr->path_no = NULL;
	ptr->path_so = NULL;
	ptr->path_we = NULL;
	ptr->ceiling_color = NULL;
	ptr->floor_color = NULL;
	ptr->map = NULL;
	ptr->map_simple = NULL;
	ptr->ceiling_r = -1;
	ptr->ceiling_g = -1;
	ptr->ceiling_b = -1;
	ptr->floor_r = -1;
	ptr->floor_g = -1;
	ptr->floor_b = -1;
}

int	ft_is_white_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

char	*ft_skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_white_space(str[i]))
		i++;
	if (str[i] != '\n')
		return (str + i);
	return (NULL);
}

char	*ft_join_map(char *map, char *line)
{
	char	*tmp;

	if (!map)
		map = ft_strjoin("", line);
	else
	{
		tmp = map;
		if (line[0] == '\n')
			map = ft_strjoin(tmp, "    \n");
		else
			map = ft_strjoin(tmp, line);
		free(tmp);
	}
	return (map);
}

void	ft_free_(t_data *ptr)
{
	if (!ptr)
		return ;
	free(ptr->path_no);
	free(ptr->path_so);
	free(ptr->path_ea);
	free(ptr->path_we);
	free(ptr->ceiling_color);
	free(ptr->floor_color);
	free(ptr->map_simple);
	if (ptr->map)
		ft_free_split(ptr->map);
	free(ptr);
	ptr = NULL;
}
