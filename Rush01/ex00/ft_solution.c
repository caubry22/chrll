/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:41:59 by caubry            #+#    #+#             */
/*   Updated: 2020/09/20 11:41:45 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_colup(int *tab, int *solution, int i)
{
	if (tab[i] == 1)
	{
		solution[i] = 4;
		if (tab[i + 4] == 2)
			solution[i + 12] = 3;
	}
	else if (tab[i] == 4)
	{
		solution[i] = 1;
		solution[i + 4] = 2;
		solution[i + 8] = 3;
		solution[i + 12] = 4;
	}
	else if (tab[i] == 2 && tab[i + 4] == 3)
	{
		solution[i + 4] = 4;
	}
	return (solution);
}

int	*ft_coldown(int *tab, int *solution, int i)
{
	int j;

	j = i + 8;
	if (tab[i] == 1)
	{
		solution[j] = 4;
		if (tab[i - 4] == 2)
			solution[j - 12] = 3;
	}
	else if (tab[i] == 4)
	{
		solution[j] = 1;
		solution[j - 4] = 2;
		solution[j - 8] = 3;
		solution[j - 12] = 4;
	}
	else if (tab[i] == 2 && tab[i - 4] == 3)
		solution[j - 4] = 4;
	return (solution);
}

int	*ft_rowleft(int *tab, int *solution, int i)
{
	int j;

	j = i - 8 + ((i - 8) * 3);
	if (tab[i] == 1)
	{
		solution[j] = 4;
		if (tab[i + 4] == 2)
			solution[j + 3] = 3;
	}
	else if (tab[i] == 4)
	{
		solution[j] = 1;
		solution[j + 1] = 2;
		solution[j + 2] = 3;
		solution[j + 3] = 4;
	}
	else if (tab[i] == 2 && tab[i + 4] == 3)
		solution[j + 1] = 4;
	return (solution);
}

int	*ft_rowright(int *tab, int *solution, int i)
{
	int j;

	j = i - 9 + ((i - 12) * 3);
	if (tab[i] == 1)
	{
		solution[j] = 4;
		if (tab[i - 4] == 2)
			solution[j - 3] = 3;
	}
	else if (tab[i] == 4)
	{
		solution[j] = 1;
		solution[j - 1] = 2;
		solution[j - 2] = 3;
		solution[j - 3] = 4;
	}
	else if (tab[i] == 2 && tab[i - 4] == 3)
		solution[j - 1] = 4;
	return (solution);
}

int	*ft_solution(int *tab, int *solution)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 16)
	{
		if (i <= 3)
			ft_colup(tab, solution, i);
		else if (i <= 7)
			ft_coldown(tab, solution, i);
		else if (i <= 11)
			ft_rowleft(tab, solution, i);
		else if (i <= 15)
			ft_rowright(tab, solution, i);
		i++;
	}
	return (solution);
}
