/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:31:17 by caubry            #+#    #+#             */
/*   Updated: 2020/09/13 22:27:08 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	if (*str >= 'a' && *str <= 'z')
		*str = *str - 32;
	return (str);
}

char	*ft_strlowcase(char *str)
{
	if (*str >= 'A' && *str <= 'Z')
		*str = *str + 32;
	return (str);
}

int		ft_str_is_alphanum(char *str)
{
	if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))
		return (1);
	else if (*str >= '0' && *str <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*mem;

	mem = str;
	if (*str >= 'a' && *str <= 'z')
	{
		ft_strupcase(str);
		str++;
	}
	while (*str)
	{
		if (ft_str_is_alphanum(str))
		{
			if (ft_str_is_alphanum(str - 1))
				ft_strlowcase(str);
			else
				ft_strupcase(str);
		}
		str++;
	}
	return (mem);
}
