/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 19:28:24 by caubry            #+#    #+#             */
/*   Updated: 2020/09/15 18:20:33 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_conv(char *str)
{
	int nb;

	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (*(str + 1) >= '0' && *(str + 1) <= '9')
		{
			nb = (nb + (*str - 48)) * 10;
			str++;
		}
		else
		{
			nb = nb + (*str - 48);
			str++;
		}
	}
	return (nb);
}

int	ft_atoi(char *str)
{
	int neg;
	int nb;

	neg = 0;
	nb = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg++;
		str++;
	}
	nb = ft_conv(str);
	if (neg % 2 != 0)
		nb = -nb;
	return (nb);
}
