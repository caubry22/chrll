/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 00:47:11 by caubry            #+#    #+#             */
/*   Updated: 2020/10/01 11:45:40 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_length(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		length;
	char	*swap;

	i = 0;
	length = ft_length(tab);
	while (i < length)
	{
		j = 0;
		while (tab[j + 1])
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
			{
				swap = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
}
