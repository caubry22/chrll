/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete23.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 15:16:48 by caubry            #+#    #+#             */
/*   Updated: 2020/09/20 17:31:17 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_upleft23(int *solution, int i, int j, int rang)
{
	if (solution[i + j] == 1)
	{
		solution[i + j + (2 * rang)] = 3;
		solution[i + j + (3 * rang)] = 2;
	}
	else if(solution[i + j] == 2)
	{
		solution[i + j + (2 * rang)] = 3;
		solution[i + j + (3 * rang)] = 1;
	}
	else if(solution[i + j] == 3)
	{
		solution[i + j + (2 * rang)] = 2;
		solution[i + j + (3 * rang)] = 1;
	}
	else if(solution[i + j + (3 * rang)] == 2)
	{
		solution[i + j] = 1;
		solution[i + j + (2 * rang)] = 3;
	}
	return (solution);
}

int	*ft_downright23(int *solution, int i, int j, int rang)
{
	if (solution[i + j] == 1)
	{
		solution[i + j - (2 * rang)] = 3;
		solution[i + j - (3 * rang)] = 2;
	}
	else if(solution[i + j] == 2)
	{
		solution[i + j - (2 * rang)] = 3;
		solution[i + j - (3 * rang)] = 1;
	}
	else if(solution[i + j] == 3)
	{
		solution[i + j - (2 * rang)] = 2;
		solution[i + j - (3 * rang)] = 1;
	}
	else if(solution[i + j - (3 * rang)] == 2)
	{
		solution[i + j] = 1;
		solution[i + j - (2 * rang)] = 3;
	}
	return (solution);
}

int *ft_complete23(int *tab, int *solution)
{
	int i;
	int rowleft;
	int rowright;
	i = 0;
	while(i < 16)
	{
		rowleft = -8 + ((i - 8) * 3);
		rowright = -9 + ((i - 12) * 3);
		if (i < 4 && tab[i] == 2 && tab[i + 4] == 3)
			ft_upleft23(solution, i, 0, 4);
		else if (i > 3 && i < 8 && tab[i] == 2 && tab[i - 4] == 3)
			ft_downright23(solution, i, 8, 4);
		else if (i > 7 && i < 12 && tab[i] == 2 && tab[i + 4] == 3)
			ft_upleft23(solution, i, rowleft, 1);
		else if (i > 11 && tab[i] == 2 && tab[i - 4] == 3)
			ft_downright23(solution, i, rowright, 1);
		i++;
	}
	return (solution);
}
