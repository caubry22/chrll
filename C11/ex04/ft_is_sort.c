/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:45:44 by caubry            #+#    #+#             */
/*   Updated: 2020/10/01 11:50:41 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int plus;
	int moins;

	plus = 0;
	moins = 0;
	i = 0;
	while (i < (length - 1))
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			plus++;
		else if ((*f)(tab[i], tab[i + 1]) < 0)
			moins++;
		i++;
	}
	if (moins > 0 && plus > 0)
		return (0);
	return (1);
}
