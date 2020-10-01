/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:23:32 by caubry            #+#    #+#             */
/*   Updated: 2020/09/29 19:04:16 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_putsize(int i, int zero)
{
	char	a;

	a = i % 10 + '0';
	if (i > 0)
	{
		ft_putsize(i / 10, 1);
		write(1, &a, 1);
	}
	if (i == 0 && zero == 0)
	{
		write(1, "0", 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putsize(par[i].size, 0);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		i++;
	}
}
