/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:37:25 by caubry            #+#    #+#             */
/*   Updated: 2020/09/14 16:42:21 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *src)
{
	unsigned int i;

	i = 0;
	while (*src)
	{
		i++;
		src++;
	}
	return (i);
}

char			*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	size_dest;
	unsigned int	i;

	size_dest = ft_strlen(dest);
	i = 0;
	while (i < nb && src[i])
	{
		dest[i + size_dest] = src[i];
		i++;
	}
	dest[i + size_dest] = 0;
	return (dest);
}
