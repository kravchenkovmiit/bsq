/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:05:53 by ktimika           #+#    #+#             */
/*   Updated: 2019/07/24 19:17:18 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		call_foo(char *map)
{
	int		**arr;
	t_par	par;
	t_res	res;

	arr = NULL;
	par = get_params(map);
	if (par.valid)
	{
		arr = create_num_map(map, par);
		analize_map(arr, par);
		res = max_finder(arr, par);
		print_treasure(map, res, par);
		free(arr);
	}
	else
		write(2, "map error\n", 10);
}

int			main(int ac, char **av)
{
	char	*map;
	int		i;

	if (ac == 1)
	{
		map = get_string_from_input();
		call_foo(map);
	}
	else
	{
		i = 0;
		while (++i < ac)
		{
			if (i > 1)
				write(1, "\n", 1);
			map = get_string_from_file(av[i]);
			if (map != NULL)
				call_foo(map);
			else
				write(2, "map error\n", 10);
		}
	}
	free(map);
	return (0);
}
