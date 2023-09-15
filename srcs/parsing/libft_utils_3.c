/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imessaad <imessaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:51:12 by imessaad          #+#    #+#             */
/*   Updated: 2023/09/02 23:53:48 by imessaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	ptr = (char *)malloc((ft_strlen(s)) * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	str = (char *)malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

void	fusion_colors(t_data *ptr)
{
	char	*str;
	char	*str_2;
	char	*tmp;

	str = ft_itoa(ptr->ceiling_r);
	tmp = str;
	str_2 = ft_itoa(ptr->ceiling_g);
	str = ft_strjoin(tmp, str_2);
	free(tmp);
	free(str_2);
	tmp = ft_itoa(ptr->ceiling_b);
	str_2 = str;
	str = ft_strjoin(str_2, tmp);
	free(str_2);
	free(tmp);
	ptr->c_color = ft_atoi(str);
	free(str);
}

void	fusion_colors_f(t_data *ptr)
{
	char	*str;
	char	*str_2;
	char	*tmp;

	str = ft_itoa(ptr->floor_r);
	tmp = str;
	str_2 = ft_itoa(ptr->floor_g);
	str = ft_strjoin(tmp, str_2);
	free(tmp);
	free(str_2);
	tmp = ft_itoa(ptr->floor_b);
	str_2 = str;
	str = ft_strjoin(str_2, tmp);
	free(str_2);
	free(tmp);
	ptr->f_color = ft_atoi(str);
	free(str);
}
