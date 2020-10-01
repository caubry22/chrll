/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:06:54 by caubry            #+#    #+#             */
/*   Updated: 2020/09/10 15:13:04 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int *revtab;
	int mem;

	revtab = tab + size - 1;
	i = size / 2;
	while (i > 0)
	{
		mem = *revtab;
		*revtab = *tab;
		*tab = mem;
		tab++;
		revtab--;
		i--;
	}
}
