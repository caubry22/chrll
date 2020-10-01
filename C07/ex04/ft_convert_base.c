/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:03:07 by caubry            #+#    #+#             */
/*   Updated: 2020/10/01 00:57:06 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strstr(char *base, char to_find);
long	ft_conv_base_from(char *str, char *base_from);
int		ft_erreur(char *base);
long	ft_convert_base_from(char *nbr, char *base_from);

int		ft_sizechar(long nb, int s_base_to)
{
	int	sizechar;

	sizechar = 0;
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb = nb / s_base_to;
		sizechar++;
	}
	return (sizechar);
}

char	*ft_conv_base_to(long nb, char *base_to, int s_base_to, int sizechar)
{
	char	*char_base_to;
	int		i;

	if (nb < 0)
		sizechar++;
	if (!(char_base_to = (char *)malloc(sizeof(char) * (sizechar + 1))))
		return (NULL);
	i = sizechar;
	if (nb < 0)
	{
		nb = -nb;
		char_base_to[0] = '-';
	}
	while (i > 0 && (char_base_to[i - 1] != '-'))
	{
		char_base_to[i - 1] = base_to[nb % s_base_to];
		nb = nb / s_base_to;
		i--;
	}
	char_base_to[sizechar] = '\0';
	return (char_base_to);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nb;
	long	s_base_to;
	int		sizechar;

	s_base_to = 0;
	if (!*base_from || !*base_to)
		return (NULL);
	if (!ft_erreur(base_to) && !ft_erreur(base_from))
	{
		nb = ft_convert_base_from(nbr, base_from);
		while (base_to[s_base_to])
			s_base_to++;
		sizechar = ft_sizechar(nb, s_base_to);
		return (ft_conv_base_to(nb, base_to, s_base_to, sizechar));
	}
	return (NULL);
}
