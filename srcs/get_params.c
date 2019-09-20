/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:18:03 by ktimika           #+#    #+#             */
/*   Updated: 2019/07/25 10:20:11 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			get_lines(char *map, int size)
{
	char	*lines;
	int		res;
	int		i;

	i = 0;
	if (!(lines = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (i < size)
	{
		lines[i] = map[i];
		i++;
	}
	lines[i] = '\0';
	res = ft_atoi(lines);
	free(lines);
	return (res);
}

int			valid_first_str(char *map, t_par par)
{
	int		i;
	int		len;

	i = par.start;
	len = 0;
	while (map[i] != '\n')
	{
		if (map[i] == '\0')
			return (0);
		len++;
		i++;
	}
	return (len);
}

int			valid_map(char *map, t_par par)
{
	int		i;
	int		cnt;
	int		len;

	i = par.start;
	cnt = 0;
	if (!(len = valid_first_str(map, par)))
		return (0);
	while (map[i])
	{
		if (map[i] == '\n')
		{
			cnt++;
			if (len != (i - par.start) / cnt)
				return (0);
		}
		i++;
	}
	if (cnt != par.lines)
		return (0);
	if (!(map[i] == '\0' && map[i - 1] == '\n'))
		return (0);
	return (len);
}

int			valid_symbols(char *map, t_par par)
{
	int		i;
	int		comp;

	i = par.start;
	comp = 0;
	while (map[i + 1])
	{
		if ((i - par.start - comp) % par.length == 0 && map[i] == '\n')
		{
			i++;
			comp++;
		}
		if (!(map[i] == par.empty || map[i] == par.obst))
			return (0);
		i++;
	}
	return (1);
}

t_par		get_params(char *map)
{
	int		i;
	t_par	map_data;

	map_data.valid = 0;
	if (!(i = valid_par(map)))
		return (map_data);
	if (!(map_data.lines = get_lines(map, i - 3)))
		return (map_data);
	map_data.start = i + 1;
	map_data.full = map[i - 1];
	map_data.obst = map[i - 2];
	map_data.empty = map[i - 3];
	if (!(map_data.length = valid_map(map, map_data)))
		return (map_data);
	map_data.valid = valid_symbols(map, map_data);
	return (map_data);
}
