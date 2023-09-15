/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imessaad <imessaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:57:30 by imessaad          #+#    #+#             */
/*   Updated: 2023/09/02 15:02:19 by imessaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	open_and_check(char **av)
{
	int		fd;
	char	*extension;

	extension = ft_strnstr(av[1], ".cub", ft_strlen(av[1]));
	if (extension && *(extension + 4) == '\0')
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (printf("%s: %s\n", av[1], strerror(errno)), -1);
	}
	else
		return (write(2, "Error\nFile is not a .cub\n", 26), -1);
	return (fd);
}

char	*skip_all_spaces(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && ft_is_white_space(str[i]))
		i++;
	if (str[i] == '\n')
		return (NULL);
	return (str + i);
}

int	check_valid(char *str, t_data *ptr)
{
	if (str[0])
	{
		if (str[0] == 'C' && str[1] && ft_is_white_space(str[1])
			&& !ptr->ceiling_color)
			ptr->ceiling_color = ft_strdup(skip_all_spaces(str + 1));
		if (str[0] == 'F' && str[1] && ft_is_white_space(str[1])
			&& !ptr->floor_color)
			ptr->floor_color = ft_strdup(skip_all_spaces(str + 1));
		else if (str[1] && str[2])
		{
			if (str == ft_strnstr(str, "NO", ft_strlen(str))
				&& ft_is_white_space(str[2]) && !ptr->path_no)
				ptr->path_no = ft_strdup(skip_all_spaces(str + 2));
			else if (str == ft_strnstr(str, "SO", ft_strlen(str))
				&& ft_is_white_space(str[2]) && !ptr->path_so)
				ptr->path_so = ft_strdup(skip_all_spaces(str + 2));
			else if (str == ft_strnstr(str, "EA", ft_strlen(str))
				&& ft_is_white_space(str[2]) && !ptr->path_ea)
				ptr->path_ea = ft_strdup(skip_all_spaces(str + 2));
			else if (str == ft_strnstr(str, "WE", ft_strlen(str))
				&& ft_is_white_space(str[2]) && !ptr->path_we)
				ptr->path_we = ft_strdup(skip_all_spaces(str + 2));
		}
	}
	return (1);
}

int	check_lines(t_data *ptr, char *str)
{
	ptr->nb_data++;
	check_valid(str, ptr);
	return (1);
}

t_data	*create_and_set(int fd)
{
	t_data	*pars;
	char	*line;
	char	*after_space;

	pars = ft_calloc(1, sizeof(t_data));
	if (!pars)
		return (NULL);
	set_struct_values(pars);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		after_space = ft_skip_space(line);
		if (ft_create_and_set_norm(pars, after_space, line) == -1)
			continue ;
		if (pars->nb_data >= 7)
			pars->map_simple = ft_join_map(pars->map_simple, line);
		free(line);
	}
	if (pars->map_simple)
		pars->map = ft_split(pars->map_simple, '\n');
	return (pars);
}
