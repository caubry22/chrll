/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifresolve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:35:32 by caubry            #+#    #+#             */
/*   Updated: 2020/09/19 19:44:09 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_test_col_row(int *tab, int i)
{
	int j;

	j = i + 3;
	while (i <= j)
	{
		if (tab[i] == 1 && tab[i + 4] == 1)
			return (0);
		if (tab[i] == 2 && tab[i + 4] == 4)
			return (0);
		if (tab[i] == 3 && tab[i + 4] > 2)
			return (0);
		if (tab[i] == 4 && tab[i + 4] > 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_test_angle(int *tab)
{
	if ((tab[0] == 1 && tab[8] != 1) || (tab[8] == 1 && tab[0] != 1))
		return (0);
	if ((tab[3] == 1 && tab[12] != 1) || (tab[12] == 1 && tab[3] != 1))
		return (0);
	if ((tab[4] == 1 && tab[11] != 1) || (tab[11] == 1 && tab[4] != 1))
		return (0);
	if ((tab[7] == 1 && tab[15] != 1) || (tab[15] == 1 && tab[7] != 1))
		return (0);
	return (1);
}

int	ft_ifresolve(int *tab)
{
	if (!(ft_test_col_row(tab, 0) && ft_test_col_row(tab, 8)))
		return (0);
	if (!ft_test_angle(tab))
		return (0);
	return (1);
}
