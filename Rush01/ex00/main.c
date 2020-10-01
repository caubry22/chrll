/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:38:26 by caubry            #+#    #+#             */
/*   Updated: 2020/09/20 22:54:33 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		ft_verif(char *str);
void	ft_print_tab(int *solution);
int		rush(char *str, int *tab, int *solution);

int		main(int ac, char **av)
{
	char	*str;
	int		tab[256];
	int		solution[256] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int		i;

	i = 0;
	if (ac == 2)
	{
		str = av[1];
		if (rush(str, tab, solution))
			ft_print_tab(solution);
	}
	return (0);
}
