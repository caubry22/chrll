/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_de_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:04:35 by caubry            #+#    #+#             */
/*   Updated: 2020/09/29 14:22:10 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strstr(char *dict, char *str, int i)
{
	int j;
	int doublon;
	int position;

	doublon = 0;
	while (dict[i])
	{
		j = 0;
		if (dict[i] == str[j] 
				&& (dict[i - 1] < '0' || dict[i - 1] > '9'))
		{
			while (dict[i] && str[j] && (dict[i] == str[j]))
			{
				i++;
				j++;
			}
		}
		if (!str[j] && (dict[i] < '0' || dict[i] > '9'))
		{
			doublon++;
			position = i;
		}
		i++;
	}
	if (doublon > 1)
		return (-1);
	if (doublon == 0)
		return (-2);
	return (position);
}

int		ft_strchar(char *dict, char c, int i)
{
	int doublon;
	int position;

	doublon = 0;
	while (dict[i])
	{
		if (dict[i] == c && (!dict[i - 1] ||
					dict[i - 1] < '0' || dict[i - 1] > '9'))
		{
			i++;
			if (dict[i] < '0' || dict[i] > '9')
			{
				doublon++;
				position = i;
			}
		}
		i++;
	}
	if (doublon > 1)
		return (-1);
	if (doublon == 0)
		return (-2);
	return (position);
}

void	ft_putstr(char *dict, int i)
{
	while (dict[i] == ' ')
		i++;
	if (dict[i] == ':')
		i++;
	while (dict[i] == ' ')
		i++;
	while (dict[i] && dict[i] != '\n')
	{
		if (dict[i] == ' ')
		{
			i++;
			while (dict[i] != '\n' && dict[i] == ' ')
				i++;
			if (dict[i] != '\n')
				write(1, " ", 1);
		}
		if (dict[i] != '\n')
		{
			write(1, &dict[i], 1);
			i++;
		}
	}
}
