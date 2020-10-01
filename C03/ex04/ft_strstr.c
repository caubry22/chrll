/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:34:10 by caubry            #+#    #+#             */
/*   Updated: 2020/09/14 14:12:19 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int j;
	int t;

	i = 0;
	j = 0;
	t = 0;
	if (!to_find[i])
		return (str);
	while (str[i])
	{
		while (str[i + t] == to_find[j + t] && to_find[j + t])
		{
			t++;
		}
		if (to_find[j + t])
		{
			t = 0;
			i++;
		}
		else
			return (str + i);
	}
	return (0);
}
