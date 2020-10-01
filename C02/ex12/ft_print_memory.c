/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 12:46:59 by caubry            #+#    #+#             */
/*   Updated: 2020/09/22 15:50:42 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_zero(long adresse)
{
	int	i;

	i = 1;
	while (adresse / 16 > 0)
	{
		i++;
		adresse = adresse / 16;
	}
	i = 16 - i;
	while (i > 0)
	{
		write(1, "0", 1);
		i--;
	}
}

void	ft_hexcar(unsigned char *addr, unsigned int size)
{
	static char		hex[16] = "0123456789abcdef";
	unsigned int	i;

	i = 0;
	while (i < 16 && i < size)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, &hex[addr[i] / 16], 1);
		write(1, &hex[addr[i] % 16], 1);
		write(1, &hex[addr[i + 1] / 16], 1);
		write(1, &hex[addr[i + 1] % 16], 1);
		i = i + 2;
	}
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		i++;
	}
}

void	ft_printcar(unsigned char *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16 && i < size)
	{
		if (addr[i] < 32 || addr[i] > 126)
			write(1, ".", 1);
		else
			write(1, &addr[i], 1);
		i++;
	}
}

void	ft_hexaddr(long adresse)
{
	static char hex[16] = "0123456789abcdef";

	if (adresse / 16 > 0)
	{
		ft_hexaddr(adresse / 16);
		write(1, &hex[adresse % 16], 1);
	}
	else
		write(1, &hex[adresse % 16], 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	long			addr_value;
	unsigned char	*chaine;
	unsigned int	espace;

	espace = size;
	while (size > 0)
	{
		addr_value = (long)addr;
		chaine = (unsigned char *)addr;
		ft_zero(addr_value);
		ft_hexaddr(addr_value);
		write(1, ":", 1);
		ft_hexcar(chaine, size);
		write(1, " ", 1);
		ft_printcar(chaine, size);
		write(1, "\n", 1);
		if (size > 16)
			size = size - 16;
		else
			size = 0;
		addr = addr + 16;
	}
	return (addr);
}

#include <stdio.h>

int  main()
{
	char str[] = "Bo\0njour les aminches...c est\t fou.tout.ce qu on peut faire avec ..print_memory..4";
	ft_print_memory(str, 75);

	return 0;
}
