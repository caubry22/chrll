/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 09:32:39 by caubry            #+#    #+#             */
/*   Updated: 2020/09/21 13:29:56 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_sort(int ac, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*mem;

	i = 1;
	while (i < ac)
	{
		k = 1;
		while (i + k < ac)
		{
			j = 0;
			while (argv[i][j] && argv[i][j] == argv[i + k][j])
				j++;
			if (argv[i][j] > argv[i + k][j])
			{
				mem = argv[i];
				argv[i] = argv[i + k];
				argv[i + k] = mem;
				j++;
			}
			k++;
		}
		i++;
	}
}

int		main(int ac, char **argv)
{
	int i;

	i = 1;
	ft_sort(ac, argv);
	while (i < ac)
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}
