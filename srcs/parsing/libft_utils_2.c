/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imessaad <imessaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:51:16 by imessaad          #+#    #+#             */
/*   Updated: 2023/09/02 23:54:03 by imessaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long int	ft_atoi(const char *nptr)
{
	int			i;
	long int	nbr;
	int			signe;

	i = 0;
	nbr = 0;
	signe = 1;
	if (!nptr)
		return (0);
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		signe = -1;
	if (signe == -1 || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = (nbr * 10) + (nptr[i++] - '0');
		if ((nbr * signe) < INT_MIN || (nbr * signe) > INT_MAX)
		{
			return (-1);
		}
	}
	return (nbr * signe);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmenb, size_t size)
{
	void	*ptr;

	if ((size > 0) && ((nmenb * size) / size != nmenb))
		return (NULL);
	ptr = (void *)malloc(nmenb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmenb * size);
	return (ptr);
}

int	ft_isdigit(int c)
{
	if ('0' <= (char)c && (char)c <= '9')
		return (1);
	else
		return (0);
}
