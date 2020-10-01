/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:00:33 by caubry            #+#    #+#             */
/*   Updated: 2020/10/01 19:24:03 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putnbr(int nb)
{
	char a;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	a = nb % 10 + '0';
	if (nb > 9)
		ft_putnbr(nb / 10);
	write(1, &a, 1);
}

int		ft_atoi(char *str)
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
	while (*str && *str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - 48);
		str++;
	}
	if (neg % 2 != 0)
		nb = -nb;
	return (nb);
}

void	ft_do_op(int a, char op, int b)
{
	if (op == '-')
		ft_putnbr(ft_soustraction(a, b));
	else if (op == '+')
		ft_putnbr(ft_somme(a, b));
	else if (op == '*')
		ft_putnbr(ft_multi(a, b));
	else if (op == '/')
	{
		if (b != 0)
			ft_putnbr(ft_div(a, b));
		else
			write(1, "Stop : division by zero", 23);
	}
	else if (op == '%')
	{
		if (b != 0)
			ft_putnbr(ft_mod(a, b));
		else
			write(1, "Stop : modulo by zero", 21);
	}
	else
		ft_putnbr(0);
	write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	if (ac == 4)
	{
		if (av[2][1])
		{
			ft_putnbr(0);
			return (0);
		}
		ft_do_op(ft_atoi(av[1]), av[2][0], ft_atoi(av[3]));
	}
	return (0);
}
