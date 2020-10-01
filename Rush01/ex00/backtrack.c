/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:18:49 by caubry            #+#    #+#             */
/*   Updated: 2020/09/20 22:14:38 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_checktab(int *tab, int *solution, int i, int j, int indice);

int	absentligne(int nb, int *solution, int i)
{
	int p;

	p = i + 4;
	while (i <= p)
	{
		if (solution[i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int absentcolonne(int nb, int *solution, int j)
{
	int p;

	p = j + 12;
	while (j <= p)
	{
		if (solution[j] == nb)
			return (0);
		j = j + 4;
	}
	return (1);
}

int	ft_test(int *tab, int *solution, int indice)
{
	int nb;
	int i;
	int j;

	nb = 1;
	j = indice % 4;
	i = indice - j;
	if (indice == 16)
		return (1);
	if (solution[indice] != 0)
		return (ft_test(tab, solution, indice + 1));
	while (nb <= 4)
	{
		if (absentligne(nb, solution, i) && absentcolonne(nb, solution, j)
				&& ft_checktab(tab, solution, i, j, indice))
		{
			solution[indice] = nb;
			if (ft_test(tab, solution, indice + 1))
					return (1);
		}
		nb++;
		solution[indice] = 0;
	}
	return (0);
}
