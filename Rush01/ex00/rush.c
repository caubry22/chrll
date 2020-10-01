/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 22:38:10 by caubry            #+#    #+#             */
/*   Updated: 2020/09/20 22:54:47 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_verif(char *str);
int		ft_ifresolve(int *tab);
int		ft_conv(char *str, int *tab);
int		ft_solution(int *tab, int *solution);
int		ft_complete13(int *tab, int *solution);
int		ft_complete23(int *tab, int *solution);
int		ft_complete22(int *tab, int *solution);
int		ft_complete12(int *tab, int *solution);
int		ft_test(int *tab, int *solution, int indice);

void	ft_complete(int *tab, int *solution)
{
	ft_complete23(tab, solution);
	ft_complete13(tab, solution);
	ft_complete22(tab, solution);
	ft_complete12(tab, solution);		
	ft_complete23(tab, solution);
	ft_complete13(tab, solution);
	ft_complete22(tab, solution);
	ft_complete12(tab, solution);
}

int		rush(char *str, int *tab, int *solution)
{
	if (!ft_verif(str))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_conv(str, tab);
	if (!ft_ifresolve(tab))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
	{
		ft_solution(tab, solution);
		ft_complete(tab, solution);
		ft_test(tab, solution, 0);
	}
	return (1);
}
