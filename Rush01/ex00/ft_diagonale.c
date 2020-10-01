/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diagonale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 15:21:21 by caubry            #+#    #+#             */
/*   Updated: 2020/09/20 17:58:23 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int *fill_diagonal(int *solution)
{
	if (solution[0] == solution[5] && solution [5] == solution[10])
		solution[15] = solution[0];
	else if (solution[0] == solution[5] && solution[5] == solution[15])
		solution[10] = solution[0];
	else if (solution[0] == solution[10] && solution[10] == solution[15])
		solution[5] = solution[0];
	else if (solution[5] == solution[10] && solution[10] == solution[15])
		solution[0] = solution[5];
	else if (solution[3] == solution[6] && solution[6] == solution[9])
		solution[12] = solution[3];
	else if (solution[3] == solution[6] && solution[3] == solution[12])
		solution[9] = solution[3];
	else if (solution[3] == solution[9] && solution[9] == solution[12])
		solution[6] = solution[3];
	else if (solution[6] == solution[9] && solution[9] == solution[12])
		solution[3] = solution[6];
	return (solution);
}
int *fill_last(int *solution)
{
	if (solution[3] == solution[14] && solution[14] == solution[4])
		solution[9] = solution[3];
	else if (solution[3] == solution[9] && solution[9] == solution[4])
		solution[14] = solution[3];
	else if (solution[3] == solution[14] && solution[14] == solution[9])
		solution[4] = solution[3];
	else if (solution[4] == solution[9] && solution[9] == solution[13])
		solution[3] = solution[4];
	else if (solution[1] == solution[6] && solution[6] == solution[11])
		solution[12] = solution[1];
	else if (solution[1] == solution [6] && solution [6] == solution [12])
		solution[11] = solution[1];
	else if (solution[1] == solution[11] && solution[11] == solution[12])
		solution[6] = solution[1];
	else if (solution[11] == solution [6] && solution[6] == solution[12])
		solution[1] = solution [11];
	else if (solution[15] == solution[2] && solution[2] == solution[5])
		solution[8] = solution[15];
	else if (solution[15] == solution[5] && solution[5] == solution[8])
		solution[2] = solution[15];
	else if (solution[15] == solution[8] && solution[8] == solution[2])
		solution[5] = solution[15];
	else if(solution[5] == solution[2] && solution[2] == solution[8])
		solution[15] = solution[5];
	else if (solution[0] == solution[7] && solution[7] == solution[10])
		solution[13] = solution[0];
	else if (solution[0] == solution[13] && solution[13] == solution [7])
		solution[10] = solution[0];
	else if (solution [0] == solution[13] && solution[13] == solution[10])
		solution[7] = solution[0];
	else if (solution[13] == solution[10] && solution[10] == solution[7])
		solution[0] = solution[13];
	return (solution);
}
int *ft_diagonale(int *solution)
{
	fill_diagonal(solution);
	fill_last(solution);
	return (solution);
}
