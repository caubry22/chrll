/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:48:39 by caubry            #+#    #+#             */
/*   Updated: 2020/09/09 18:48:17 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_convert(int nb)
{
	char	dizaine;
	char	unite;

	unite = nb % 10;
	dizaine = (nb - unite) / 10 + 48;
	if (dizaine == 0)
	{
		write(1, "0", 1);
	}
	else
	{
		write(1, &dizaine, 1);
	}
	unite = unite + 48;
	write(1, &unite, 1);
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			ft_convert(a);
			write(1, " ", 1);
			ft_convert(b);
			if (a < 98)
			{
				write(1, ", ", 2);
			}
			b++;
		}
		a++;
	}
}
