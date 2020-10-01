/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:34:46 by caubry            #+#    #+#             */
/*   Updated: 2020/09/10 17:33:58 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int *i;
	int *fin;

	fin = tab + size;
	while (tab < fin)
	{
		i = tab + 1;
		while (i < fin)
		{
			if (*tab > *i)
			{
				ft_swap(tab, i);
			}
			i++;
		}
		tab++;
	}
}
