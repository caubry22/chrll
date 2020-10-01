/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiraoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:33:11 by ymiraoui          #+#    #+#             */
/*   Updated: 2020/09/12 15:50:14 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	choose_char(int x, int y, int px, int py)
{
	if ((py == 1) && ((px == 1) || (px == x)))
	{
		ft_putchar('A');
	}
	else if ((py == y) && ((px == 1) || (px == x)))
	{
		ft_putchar('C');
	}
	else if ((px == 1) || (px == x) || (py == 1) || (py == y))
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int px;
	int py;

	px = 1;
	py = 1;
	while ((px <= x) && (py <= y))
	{
		choose_char(x, y, px, py);
		if (px == x)
		{
			ft_putchar('\n');
			py++;
			px = 1;
		}
		else
			px++;
	}
}
