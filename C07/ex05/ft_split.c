/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 22:04:07 by caubry            #+#    #+#             */
/*   Updated: 2020/10/01 12:58:18 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strissep(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int		ft_countsep(char *str, char *charset)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str && !ft_strissep(*str, charset))
		{
			count++;
			while (*str && !ft_strissep(*str, charset))
				str++;
		}
		while (*str && ft_strissep(*str, charset))
			str++;
	}
	return (count);
}

int		ft_strlen(char *str, char *charset)
{
	int i;

	i = 0;
	while (*str && ft_strissep(*str, charset))
		str++;
	while (*str && !ft_strissep(*str, charset))
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_fill(char *str, int i)
{
	char	*word;
	int		j;

	j = 0;
	if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (j < i)
	{
		word[j] = str[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		nb_char;
	char	**strcut;
	int		k;
	int		i;

	k = 0;
	nb_char = ft_countsep(str, charset);
	if (!(strcut = (char **)malloc(sizeof(char *) * (nb_char + 1))))
		return (NULL);
	while (k < nb_char)
	{
		i = ft_strlen(str, charset);
		if (!(strcut[k] = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		while (ft_strissep(*str, charset))
			str++;
		strcut[k] = ft_fill(str, i);
		str = str + i;
		k++;
	}
	strcut[nb_char] = NULL;
	return (strcut);
}
