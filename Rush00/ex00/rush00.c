/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiraoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:35:23 by ymiraoui          #+#    #+#             */
/*   Updated: 2020/09/12 17:49:24 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	choose_char(int x, int y, int px, int py)
{
	if (((py == 1) || (py == y)) && ((px == 1) || (px == x)))
	{
		ft_putchar('o');
	}
	else if ((px == 1) || (px == x))
	{
		ft_putchar('|');
	}
	else if ((py == 1) || (py == y))
	{
		ft_putchar('-');
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
