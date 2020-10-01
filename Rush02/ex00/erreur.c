/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 11:09:12 by caubry            #+#    #+#             */
/*   Updated: 2020/09/27 21:58:26 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft.h"

int		ft_nbinvalide(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int		ft_dictinvalide(char *dict, int i)
{
	while (dict[i])
	{
		while (dict[i] && (dict[i] == ' ' || dict[i] == '\n'))
			i++;
		if (dict[i] < '0' || dict[i] > '9')
			return (1);
		while (dict[i] >= '0' && dict[i] <= '9')
			i++;
		while (dict[i] == ' ')
			i++;
		if (dict[i] != ':')
			return (1);
		while (dict[i] == ' ')
			i++;
		while (dict[i] != '\n')
		{
			if (dict[i] < 32 || dict[i] > 126)
				return (1);
			i++;
		}
		if (!dict[i + 1])
			return (0);
	}
	return (0);
}

int		ft_novalue2(char *dict, int size)
{
	char	*seek;
	int		indice;

	indice = 1;
	if (!(seek = (char *)malloc(sizeof(char) * size + 1)))
		return (-1);
	seek[0] = '1';
	while (indice < size)
	{
		seek[indice] = '0';
		indice++;
	}
	seek[size] = '\0';
	if (ft_strstr(dict, seek, 0) == -2)
		return (1);
	else
		return (0);
}

int		ft_novalue(char *dict, char *str, int i, int size)
{
	while (str[i])
	{
		if ((size - 1) % 3 == 0)
		{
			if (ft_novalue2(dict, size))
				return (1);
		}
		if (ft_strchar(dict, str[i], 0) == -2)
			return (1);
		i++;
		size--;
	}
	return (0);
}
