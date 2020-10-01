/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:26:01 by caubry            #+#    #+#             */
/*   Updated: 2020/09/27 22:05:13 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

int		ft_strstr(char	*dict, char *str, int i);
void	ft_putstr(char *dict, int i);
int		ft_strchar(char *dict, char c, int i);
int		ft_putspace(char *str, int i, int size);
void	ft_putspace2(char *str, int i, int size, int space);
int		ft_dictinvalide(char *dict, int i);
int		ft_nbinvalide(char *str);
int		ft_novalue(char *dict, char *str, int i, int size);
int		ft_rush02(const char *bib, char *str);
int		ft_strlen(char *str);
void	ft_printvalue(char *dict, char *str, int size, int i);
int		ft_doublon(char *dict, char *str, int i, int size);

#endif
