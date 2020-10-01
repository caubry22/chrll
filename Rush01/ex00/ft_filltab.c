/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filltab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 15:54:36 by caubry            #+#    #+#             */
/*   Updated: 2020/09/20 16:05:21 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ft_complete13(int *tab, int *solution);
int		*ft_complete23(int *tab, int *solution);
int		*ft_complete22(int *tab, int *solution);

int	*ft_fill(int *tab, int *solution)
{
	ft_complete23(tab, solution);
	ft_complete13(tab, solution);
	ft_complete22(tab, solution);
	ft_complete23(tab, solution);
	ft_complete13(tab, solution);
	ft_complete22(tab, solution);
	ft_complete23(tab, solution);
	ft_complete13(tab, solution);
	ft_complete22(tab, solution);
	ft_complete23(tab, solution);
	ft_complete13(tab, solution);
	ft_complete22(tab, solution);
	return (solution);
}
