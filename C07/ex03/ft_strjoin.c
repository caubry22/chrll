/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:55:59 by caubry            #+#    #+#             */
/*   Updated: 2020/09/28 12:00:35 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen_strs(int size, char **strs)
{
	int i;
	int j;
	int len;

	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}

int		ft_strlen(char *sep)
{
	int i;

	i = 0;
	while (sep[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *join, char *copy, int k)
{
	int i;

	i = 0;
	while (copy[i])
	{
		join[k] = copy[i];
		i++;
		k++;
	}
	return (join);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*join;
	int		i;
	int		k;

	i = 0;
	k = 0;
	len = ft_strlen_strs(size, strs) + (ft_strlen(sep) * (size - 1));
	if (size == 0)
		len = 1;
	if (!(join = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	while (i < size)
	{
		ft_strcpy(join, strs[i], k);
		k = k + ft_strlen(strs[i]);
		i++;
		if (i < size)
		{
			ft_strcpy(join, sep, k);
			k = k + ft_strlen(sep);
		}
	}
	join[k] = '\0';
	return (join);
}
