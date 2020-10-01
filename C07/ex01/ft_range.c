/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 12:08:18 by caubry            #+#    #+#             */
/*   Updated: 2020/09/28 11:42:19 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int taille;
	int	*tab;

	taille = max - min;
	if (min >= max)
	{
		tab = NULL;
		return (tab);
	}
	if (!(tab = (int *)malloc(sizeof(int) * (max - min))))
	{
		return (NULL);
	}
	i = 0;
	while (i < taille)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
