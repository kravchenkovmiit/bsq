/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_from_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:57:34 by ktimika           #+#    #+#             */
/*   Updated: 2019/07/25 11:25:12 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char		*get_tmp_input(char *buf, int j)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * (j + BSIZE + 1))))
		return (NULL);
	while (i < j)
	{
		tmp[i] = buf[i];
		i++;
	}
	tmp[i] = '\0';
	free(buf);
	buf = tmp;
	return (buf);
}

int			crutch_in(t_inp *inp)
{
	if (inp->ret == -1)
		return (0);
	inp->i += inp->ret;
	inp->j += inp->ret;
	return (1);
}

t_inp		new_line_calc(char *buf, t_inp inp)
{
	int x;

	x = 0;
	buf[inp.j] = '\0';
	if (inp.k == -1)
	{
		if ((x = (valid_par(buf))) < 1)
		{
			write(2, "map error\n", 10);
			exit(0);
		}
		inp.res = get_lines(buf, x - 3);
		inp.k++;
	}
	while (buf[inp.k])
	{
		if (buf[inp.k] == '\n')
			inp.c_lb++;
		inp.k++;
	}
	inp.k++;
	return (inp);
}

char		*get_string_from_input(void)
{
	char	*buf;
	t_inp	inp;

	inp.i = 0;
	inp.j = 0;
	inp.k = -1;
	inp.c_lb = 0;
	if (!(buf = (char*)malloc(sizeof(char) * (BSIZE + 1))))
		return (NULL);
	while ((inp.ret = read(0, buf + inp.j, BSIZE - inp.i)))
	{
		if (!(crutch_in(&inp)))
			return (NULL);
		inp = new_line_calc(buf, inp);
		if (inp.c_lb == (inp.res + 1))
			return (buf);
		if (inp.i == BSIZE)
		{
			buf = get_tmp_input(buf, inp.j);
			inp.i = 0;
		}
	}
	buf[inp.j] = '\0';
	return (buf);
}
