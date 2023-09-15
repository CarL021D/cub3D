/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imessaad <imessaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:49:29 by imessaad          #+#    #+#             */
/*   Updated: 2023/09/02 15:02:23 by imessaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	pars_colors(char *str, t_data *ptr, char c)
{
	char	**splitted;
	int		i;
	int		nbr;

	i = 0;
	splitted = ft_split(str, ',');
	while (splitted[i])
		i++;
	if (i != 3)
		return (ft_free_split(splitted), -1);
	i = 0;
	while (splitted[i])
	{
		nbr = ft_atoi(splitted[i]);
		if (nbr > 255 || nbr < 0)
			return (ft_free_split(splitted), -1);
		else
			assign_colors(nbr, ptr, c);
		i++;
	}
	return (ft_free_split(splitted), 1);
}

int	ft_check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_white_space(str[i]) && i > 0 && (str[i - 1] != ' '
				&& str[i - 1] != ',') && str[i + 1] && ft_isdigit(str[i + 1]))
			return (-1);
		i++;
	}
	return (1);
}

int	ft_check_colors(char *str, t_data *ptr, char c)
{
	if (!str)
		return (-1);
	str[ft_strlen(str) - 1] = '\0';
	if (check_virg(str) == -1)
		return (-1);
	if (ft_check_space(str) == -1)
		return (-1);
	if (pars_colors(str, ptr, c) == -1)
		return (-1);
	return (1);
}

int	ft_check_characters_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'E' && map[i][j] != 'W')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_empty_line_map(char **map)
{
	int		i;
	int		var;
	char	*tmp;

	var = 0;
	i = 0;
	while (map[i])
	{
		tmp = skip_all_spaces(map[i]);
		if (*tmp == '\0' || map[i][0] == '\n')
			tmp = NULL;
		if (var == 0 && !tmp)
			var = 1;
		else if (var == 1 && tmp)
			return (-1);
		i++;
	}
	return (1);
}
