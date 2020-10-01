/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:28:36 by caubry            #+#    #+#             */
/*   Updated: 2020/09/13 21:51:35 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int i;

	i = 1;
	while (*str)
	{
		if (*str < 32 || *str == 127)
		{
			i = 0;
		}
		str++;
	}
	return (i);
}