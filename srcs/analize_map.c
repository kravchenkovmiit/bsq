/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:11:12 by ktimika           #+#    #+#             */
/*   Updated: 2019/07/23 19:01:11 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		min_number(int nb1, int nb2, int nb3)
{
	int min;

	min = nb1;
	if (nb2 <= nb1 && nb2 <= nb3)
		min = nb2;
	else if (nb3 <= nb1 && nb3 <= nb2)
		min = nb3;
	return (min);
}

void	analize_map(int **arr, t_par par)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i < par.lines)
	{
		while (j < par.length)
		{
			if (arr[i][j] == 0 && j != par.length)
				j++;
			else
			{
				arr[i][j] = min_number(arr[i][j - 1], arr[i - 1][j - 1],
						arr[i - 1][j]) + 1;
				j++;
			}
		}
		j = 1;
		i++;
	}
}
