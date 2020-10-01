/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:04:47 by caubry            #+#    #+#             */
/*   Updated: 2020/09/19 19:43:41 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	choose_char(int px, int py, int *solution)
{
	if ((px == 1) || (px == 3) || (px == 5))
	{
		ft_putchar(' ');
	}
	else
	{
		ft_putchar(solution[(px / 2) + (4 * py)] + '0');
	}
}

void	ft_print_tab(int *solution)
{
	int px;
	int py;

	px = 0;
	py = 0;
	while ((px <= 6) && (py <= 3))
	{
		choose_char(px, py, solution);
		if (px == 6)
		{
			ft_putchar('\n');
			py++;
			px = 0;
		}
		else
			px++;
	}
}
