/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 11:28:01 by caubry            #+#    #+#             */
/*   Updated: 2020/09/27 23:27:24 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft.h"

int		ft_tbib(const char *bib)
{
	int		ret;
	int		t_bib;
	int		fd;
	char	dict[300];

	fd = open(bib, O_RDONLY);
	t_bib = 0;
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	while ((ret = read(fd, dict, 299)))
	{
		dict[ret] = '\0';
		t_bib = t_bib + ret;
	}
	dict[299] = '\0';
	close(fd);
	return (t_bib);
}

int		ft_zero(char *dict, char *str, int size)
{
	int i;
	int find;

	i = 0;
	if (size == 0)
	{
		write(1, "Error", 5);
		return (-2);
	}
	while (str[i] == '0')
	{
		i++;
		size--;
	}
	if (!str[i])
	{
		find = ft_strchar(dict, '0', 0);
		ft_putstr(dict, find);
		return (-1);
	}
	return (i);
}

void	ft_callprint(char *dict, char *str, int size)
{
	int i;

	i = 0;
	if (!ft_dictinvalide(dict, 0))
	{
		i = ft_zero(dict, str, size);
		size = size - i;
		if (i >= 0)
		{
			if (ft_novalue(dict, str, i, size))
				write(1, "Error", 5);
			else if (ft_doublon(dict, str, i, size))
				write(1, "Dict Error", 10);
			else
				ft_printvalue(dict, str, size, i);
		}
	}
	else
		write(1, "Dict Error", 10);
}

int		ft_rush02(const char *bib, char *str)
{
	int		size;
	int		t_bib;
	int		fd;
	char	*dict;

	fd = open(bib, O_RDONLY);
	t_bib = ft_tbib(bib);
	if (t_bib == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!(dict = (char *)malloc(sizeof(char) * t_bib + 1)))
		return (0);
	read(fd, dict, t_bib);
	size = ft_strlen(str);
	ft_callprint(dict, str, size);
	write(1, "\n", 1);
	close(fd);
	return (0);
}
