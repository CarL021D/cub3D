/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imessaad <imessaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:47:28 by imessaad          #+#    #+#             */
/*   Updated: 2023/09/02 15:02:21 by imessaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_white_space(str[i]))
			return (-1);
		i++;
	}
	return (1);
}

int	check_extension_xpm(char *str)
{
	char	*ptr;

	ptr = ft_strnstr(str, ".xpm", ft_strlen(str));
	if (!ptr)
		return (-1);
	else if (*(ptr + 4) == '\0')
		return (1);
	return (-1);
}

int	check_files(char *str)
{
	int	fd;

	if (!str)
		return (printf("Error\nInvalid data\n"), -1);
	if (str)
		str[ft_strlen(str) - 1] = '\0';
	if (check_extension_xpm(str) == -1)
		return (printf("Error\nInvalid extension for textures\n"), -1);
	else if (check_space(str) == -1)
		return (printf("Error\nInvalid data\n"), -1);
	else
	{
		fd = open(str, O_RDONLY);
		if (fd == -1)
			return (printf("%s: %s\n", str, strerror(errno)), -1);
		else
			return (close(fd), 1);
	}
	return (1);
}

int	ft_check_virg_norm(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((!ft_isdigit(str[i])
				&& !ft_is_white_space(str[i]) && str[i] != ','))
			return (-1);
		i++;
	}
	return (1);
}

int	check_virg(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			count++;
			if (i == 0)
				return (-1);
			if (i > 0 && (str[i + 1] && str[i + 1] == ','))
				return (-1);
		}
		i++;
	}
	if (count != 2)
		return (-1);
	if (ft_check_virg_norm(str) == -1)
		return (-1);
	return (1);
}
