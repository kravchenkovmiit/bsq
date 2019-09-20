/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_from_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:59:45 by ktimika           #+#    #+#             */
/*   Updated: 2019/07/24 19:00:02 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char		*get_tmp_file(char *buf, int j)
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
	return (tmp);
}

int			crutch(int *i, int *j, int ret)
{
	if (ret == -1)
		return (0);
	*i += ret;
	*j += ret;
	return (1);
}

char		*read_string(int fd)
{
	char	*buf;
	char	*tmp;
	int		ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(buf = (char*)malloc(sizeof(char) * (BSIZE + 1))))
		return (NULL);
	while ((ret = read(fd, buf + j, BSIZE - i)))
	{
		if (!(crutch(&i, &j, ret)))
			return (NULL);
		buf[j] = '\0';
		if (i == BSIZE)
		{
			tmp = get_tmp_file(buf, j);
			free(buf);
			buf = tmp;
			i = 0;
		}
	}
	buf[j] = '\0';
	return (buf);
}

char		*get_string_from_file(char *file_name)
{
	int		fd;
	char	*str;

	fd = open(file_name, O_RDONLY, S_IRUSR);
	if (fd == -1)
		return (NULL);
	str = read_string(fd);
	if (close(fd) == -1)
		return (NULL);
	return (str);
}
