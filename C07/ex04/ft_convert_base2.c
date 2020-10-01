/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:22:10 by caubry            #+#    #+#             */
/*   Updated: 2020/09/22 19:23:47 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strstr(char *base, char to_find)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == to_find)
			return (1);
		i++;
	}
	return (0);
}

long	ft_conv_base_from(char *str, char *base_from)
{
	long	nb;
	int		i;
	int		t_base;

	nb = 0;
	i = 0;
	t_base = 0;
	while (base_from[i])
	{
		t_base++;
		i++;
	}
	i = 0;
	while (ft_strstr(base_from, *str))
	{
		while (base_from[i] != *str)
			i++;
		nb = t_base * nb + i;
		str++;
		i = 0;
	}
	return (nb);
}

int		ft_erreur(char *base)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (!(base[0] && base[1]))
		return (1);
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (1);
		if (base[i] == '+' || base[i] == '-')
			return (1);
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

long	ft_convert_base_from(char *nbr, char *base_from)
{
	int		signe;
	long	nb;

	nb = 0;
	signe = 1;
	if (!(ft_erreur(base_from)))
	{
		while ((*nbr >= 9 && *nbr <= 13) || *nbr == ' ')
		{
			nbr++;
		}
		while (*nbr == '+' || *nbr == '-')
		{
			if (*nbr == '-')
				signe = -signe;
			nbr++;
		}
		return (ft_conv_base_from(nbr, base_from) * signe);
	}
	return (0);
}
