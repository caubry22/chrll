/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 10:17:45 by caubry            #+#    #+#             */
/*   Updated: 2020/09/27 23:25:53 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_nbinvalide(av[1]))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		ft_rush02("numbers.dict", av[1]);
	}
	if (ac == 3)
	{
		if (ft_nbinvalide(av[2]))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		ft_rush02(av[1], av[2]);
	}
	return (0);
}
