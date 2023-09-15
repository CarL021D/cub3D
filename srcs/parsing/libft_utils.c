/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imessaad <imessaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:04:52 by caboudar          #+#    #+#             */
/*   Updated: 2023/09/02 23:51:29 by imessaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == ((char)c))
			return ((char *)(s + i));
		i--;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[0] || !little)
		return ((char *)big);
	if (!big || !little)
		return (0);
	while (i < n && big[i])
	{
		j = 0;
		while (little[j] && big[i + j] && i + j < n)
		{
			if (little[j] != big[i + j])
				break ;
			j++;
			if (!little[j])
				return ((char *)(big + i));
		}
		i++;
	}
	return (0);
}

static int	len_itoa(int n)
{
	int				i;
	unsigned int	nb;

	i = 1;
	nb = n;
	if (n < 0)
	{
		i++;
		nb = n * (-1);
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	nb;
	char			*str;

	str = (char *)malloc(len_itoa(n) + 1);
	if (!str)
		return (0);
	i = len_itoa(n);
	nb = n;
	if (n < 0)
	{
		nb = n * (-1);
		str[0] = '-';
	}
	str[i] = 0;
	str[i - 1] = '0';
	while (nb > 0)
	{
		i--;
		str[i] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}
