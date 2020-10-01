/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printvalue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:57:37 by caubry            #+#    #+#             */
/*   Updated: 2020/09/27 22:59:33 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft.h"

void	ft_print1(char *dict, char *str, int i, int size2)
{
	int find;

	if (str[i - 1] != '1')
	{
		find = ft_strchar(dict, str[i], 0);
		if (size2 != 0)
			write(1, " ", 1);
		ft_putstr(dict, find);
	}
}

void	ft_print2(char *dict, char *str, int i, int size2)
{
	int find;

	if (str[i] >= '1')
	{
		find = ft_strchar(dict, str[i], 0);
		if (size2 != 0)
			write(1, " ", 1);
		ft_putstr(dict, find);
		write(1, " ", 1);
	}
	find = ft_strstr(dict, "100", 0);
	ft_putstr(dict, find);
}

int		ft_print3(char *dict, char *str, int i, int size2)
{
	char	*value;
	int		find;

	if (!(value = (char *)malloc(sizeof(char) * 3)))
		return (0);
	value[0] = str[i];
	if (str[i] == '1')
		value[1] = str[i + 1];
	else
		value[1] = '0';
	value[2] = '\0';
	find = ft_strstr(dict, value, 0);
	if (size2 != 0)
		write(1, " ", 1);
	ft_putstr(dict, find);
	free(value);
	return (1);
}

int		ft_print4(char *dict, char *str, int i, int size)
{
	char	*value;
	int		pos;
	int		find;

	pos = 1;
	if (str[i - 1] != '1' && str[i] >= '1')
	{
		find = ft_strchar(dict, str[i], 0);
		ft_putstr(dict, find);
		write(1, " ", 1);
	}
	if (!(value = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	value[0] = '1';
	while (pos < size)
	{
		value[pos] = '0';
		pos++;
	}
	value[size] = '\0';
	find = ft_strstr(dict, value, 0);
	ft_putstr(dict, find);
	free(value);
	return (1);
}

void	ft_printvalue(char *dict, char *str, int size, int i)
{
	int size2;

	size2 = size;
	while (str[i])
	{
		size2 = size2 - size;
		if (size == 1 && str[i] != '0')
			ft_print1(dict, str, i, size2);
		else if (size % 3 == 0 && str[i] != '0')
			ft_print2(dict, str, i, size2);
		else if (((size - 2) % 3 == 0 || size == 2) && str[i] != '0')
			ft_print3(dict, str, i, size2);
		else if ((size - 1) % 3 == 0 && size > 1
				&& (str[i - 2] != '0' || str[i - 1] != '0'
					|| size2 == 0 || str[i] != '0'))
		{
			if (size2 != 0)
				write(1, " ", 1);
			ft_print4(dict, str, i, size);
		}
		i++;
		size--;
	}
}
