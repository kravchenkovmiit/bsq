/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_treasure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 10:42:22 by ktimika           #+#    #+#             */
/*   Updated: 2019/07/24 16:32:21 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_treasure(char *map, t_res res, t_par par)
{
	int j;
	int start;
	int finish;

	start = par.start + res.y * (par.length + 1) + res.x;
	j = start;
	finish = start + (par.length + 1) * (res.max - 1) + res.max - 1;
	while (start <= finish)
	{
		while (j < res.max + start)
		{
			map[j] = par.full;
			j++;
		}
		start = j + par.length - (res.max - 1);
		j = start;
	}
	j = 0;
	while (j < par.start)
	{
		map++;
		j++;
	}
	write(1, map, par.length * par.lines + par.lines);
}
