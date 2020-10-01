/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 20:56:59 by caubry            #+#    #+#             */
/*   Updated: 2020/09/16 18:18:44 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int				ft_erreur(char *base)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (ft_strlen(base) < 2)
		return (1);
	while (base[i])
	{
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

void			ft_putnbr_base(int nbr, char *base)
{
	long			nb;
	unsigned int	t_base;

	nb = (long)nbr;
	t_base = ft_strlen(base);
	if (!(ft_erreur(base)))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		if (nb >= t_base)
		{
			ft_putnbr_base(nb / t_base, base);
			write(1, &base[nb % t_base], 1);
		}
		else
			write(1, &base[nb % t_base], 1);
	}
}
