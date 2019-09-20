/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_num_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 19:31:41 by ktimika           #+#    #+#             */
/*   Updated: 2019/07/24 11:18:39 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		fill_num_map(char *map, t_par par, int **arr)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = par.start - 1;
	while (map[++k])
	{
		if (map[k] == par.empty)
		{
			arr[i][j] = 1;
			j++;
		}
		else if (map[k] == par.obst)
		{
			arr[i][j] = 0;
			j++;
		}
		else
		{
			i++;
			j = 0;
		}
	}
}

int			**create_num_map(char *map, t_par par)
{
	int		**arr;
	int		i;

	i = 0;
	if (!(arr = (int**)malloc(sizeof(*arr) * par.lines)))
		return (NULL);
	while (i < par.lines)
	{
		if (!(arr[i] = (int*)malloc(sizeof(int) * par.length)))
			return (NULL);
		i++;
	}
	fill_num_map(map, par, arr);
	return (arr);
}
