/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:31:53 by ktimika           #+#    #+#             */
/*   Updated: 2019/07/25 10:49:05 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define BSIZE 10048576

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_par
{
	int		start;
	char	empty;
	char	obst;
	char	full;
	int		lines;
	int		length;
	int		valid;
}				t_par;

typedef struct	s_res
{
	int max;
	int x;
	int y;
}				t_res;

typedef struct	s_inp
{
	int ret;
	int i;
	int j;
	int k;
	int c_lb;
	int res;
}				t_inp;

int				ft_atoi(char *str);
t_par			get_params(char *map);
char			*get_string_from_file(char *file_name);
char			*get_string_from_input(void);
int				**create_num_map(char *map, t_par par);
void			analize_map(int **arr, t_par par);
t_res			max_finder(int **arr, t_par par);
void			print_treasure(char *map, t_res res, t_par par);
int				valid_par(char *map);
int				get_lines(char *map, int size);

#endif
