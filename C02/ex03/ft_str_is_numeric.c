/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:16:05 by caubry            #+#    #+#             */
/*   Updated: 2020/09/13 21:46:46 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int i;

	i = 1;
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			i = 0;
		}
		str++;
	}
	return (i);
}
