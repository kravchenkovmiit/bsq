/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_par.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:50:40 by ktimika           #+#    #+#             */
/*   Updated: 2019/07/25 11:21:40 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			valid_par(char *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			break ;
		i++;
	}
	if (map[i] == '\0')
		return (0);
	if (i < 4 || map[i] != '\n')
		return (0);
	if (map[i - 1] == map[i - 2] || map[i - 1] == map[i - 3] ||
			map[i - 2] == map[i - 3])
		return (0);
	while (j < i - 3)
	{
		if (map[j] < '0' || map[j] > '9')
			return (0);
		j++;
	}
	return (i);
}
