/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:24:22 by caubry            #+#    #+#             */
/*   Updated: 2020/09/20 22:30:31 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_countcolup(int *solution, int j)
{
	int boxmax;
	int nbbox;
	int p;

	boxmax = solution[j];
	nbbox = 0;
	p = j + 12;
	while (j <= p)
	{
		if (solution[j] > boxmax)
		{
			boxmax = solution[j];
			nbbox++;
		}
		j = j + 4;
	}
	return(nbbox);
}

int	ft_countcoldown(int *solution, int j)
{
	int boxmax;
	int nbbox;
	int p;

	boxmax = solution[j];
	nbbox = 0;
	p = j - 12;
	while (j >= p)
	{
		if (solution[j] > boxmax)
		{
			boxmax = solution[j];
			nbbox++;
		}
		j = j - 4;
	}
	return (nbbox);
}

int ft_countrowleft(int *solution, int i)
{
	int boxmax;
	int nbbox;
	int p;

	boxmax = solution[i];
	nbbox = 0;
	p = i + 4;
	while (i <= p)
	{
		if (solution[i] > boxmax)
		{
			boxmax = solution[i];
			nbbox++;
		}
		i++;
	}
	return (nbbox);
}

int ft_countrowright(int *solution, int i)
{
	int boxmax;
	int nbbox;
	int p;

	boxmax = solution[i];
	nbbox = 0;
	p = i - 4;
	while (i >= p)
	{
		if (solution[i] > boxmax)
		{
			boxmax = solution[i];
			nbbox++;
		}
		i--;
	}
	return (nbbox);
}

int ft_checktab(int *tab, int *solution, int i, int j, int indice)
{
	int rowleft;

	rowleft = i + 8 - (3 * (i / 4));
	if (i != 0 && indice % i == 3)
	{
		if (ft_countrowleft(solution, i) != tab[rowleft] 
			|| ft_countrowright(solution, i + 4) != tab[rowleft + 4])
			return (0);
		else
			return (1);
	}
	if (j != 0 && indice - j == 0)
	{
		if (ft_countcolup(solution, j) != tab[j]
			|| ft_countcoldown(solution, j + 12) != tab[j + 4])
			return (0);
		else
			return (1);
	}
	return (1);
}
