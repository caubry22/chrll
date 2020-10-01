/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:56:46 by caubry            #+#    #+#             */
/*   Updated: 2020/10/01 14:51:55 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_create_elem(void *data)
{
	t_list elem;

	elem->data = data;
	elem->next = NULL;
	return (&elem);
}