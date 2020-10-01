/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 10:37:14 by caubry            #+#    #+#             */
/*   Updated: 2020/09/16 18:19:39 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *base)
{
	int i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_strstr(char *base, char to_find)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == to_find)
			return (1);
		i++;
	}
	return (0);
}

int	ft_conv(char *str, char *base)
{
	int nb;
	int i;
	int t_base;

	nb = 0;
	i = 0;
	t_base = ft_strlen(base);
	while (ft_strstr(base, *str))
	{
		while (base[i] != *str)
		{
			i++;
		}
		if (ft_strstr(base, *(str + 1)))
			nb = (nb + i) * t_base;
		else
			nb = nb + i;
		str++;
		i = 0;
	}
	return (nb);
}

int	ft_erreur(char *base)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (ft_strlen(base) < 2)
		return (1);
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (1);
		if (base[i] == '+' || base[i] == '-')
			return (1);
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int neg;
	int nb;

	neg = 0;
	nb = 0;
	if (!(ft_erreur(base)))
	{
		while ((*str >= 9 && *str <= 13) || *str == ' ')
			str++;
		while (*str == '+' || *str == '-')
		{
			if (*str == '-')
				neg++;
			str++;
		}
		nb = ft_conv(str, base);
		if (neg % 2 != 0)
			nb = -nb;
		return (nb);
	}
	return (0);
}
