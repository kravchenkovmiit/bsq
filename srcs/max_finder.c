/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_finder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 10:12:33 by ktimika           #+#    #+#             */
/*   Updated: 2019/07/23 19:18:57 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_res		max_finder(int **arr, t_par par)
{
	int		i;
	int		j;
	t_res	res;

	i = -1;
	j = -1;
	res.y = 0;
	res.x = 0;
	res.max = 0;
	while (++i < par.lines)
	{
		while (++j < par.length)
		{
			if (arr[i][j] > res.max)
			{
				res.max = arr[i][j];
				res.y = i;
				res.x = j;
			}
		}
		j = -1;
	}
	res.y = res.y - res.max + 1;
	res.x = res.x - res.max + 1;
	return (res);
}
