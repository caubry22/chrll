/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 21:59:09 by caubry            #+#    #+#             */
/*   Updated: 2020/09/29 14:26:32 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

int		ft_doublon2(char *dict, int size)
{
	char	*seek;
	int		indice;

	indice = 1;
	if (!(seek = (char *)malloc(sizeof(char) * size + 1)))
		return (-1);
	if ((size - 2) % 3 == 0)
		seek[0] = ;
	while (indice < size)
	{
		seek[indice] = '0';
		indice++;
	}
	seek[size] = '\0';
	if (ft_strstr(dict, seek, 0) == -1)
		return (1);
	else
		return (0);
}

int		ft_doublon(char *dict, char *str, int i, int size)
{
	while (str[i])
	{
		if ((size - 1) % 3 == 0 || (size-2) % 3 == 0)
		{
			if (ft_doublon2(dict, size))
				return (1);
		}
		if (ft_strchar(dict, str[i], 0) == -1)
			return (1);
		i++;
		size--;
	}
	return (0);
}
