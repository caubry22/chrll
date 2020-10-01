/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 12:07:58 by caubry            #+#    #+#             */
/*   Updated: 2020/09/15 10:42:04 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_printable(unsigned char *str)
{
	if (*str < 32 || *str > 126)
		return (0);
	else
		return (1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*unchar;
	static char		hex[16] = "0123456789abcdef";
	int				i;

	unchar = (unsigned char *)str;
	i = 0;
	while (unchar[i])
	{
		if (ft_str_is_printable(unchar))
			write(1, unchar, 1);
		else
		{
			write(1, "\\", 1);
			write(1, &hex[unchar[i] / 16], 1);
			write(1, &hex[unchar[i] % 16], 1);
		}
		unchar++;
	}
}

#include <stdio.h>

int	main()
{
	char test[] = "ç\0";
	ft_putstr_non_printable(test);
}
