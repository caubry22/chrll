/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:13:24 by caubry            #+#    #+#             */
/*   Updated: 2020/09/14 16:23:40 by caubry           ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int size_dest;
	unsigned int size_src;
	unsigned int i;
	unsigned int sizefin;
	unsigned int t;

	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	t = size_dest + size_src;
	sizefin = size - size_dest;
	i = 0;
	if (size <= size_dest)
		return (size + size_src);
	while (i < sizefin - 1 && src[i])
	{
		dest[i + size_dest] = src[i];
		i++;
	}
	dest[i + size_dest] = 0;
	return (t);
}
