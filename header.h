/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:10:54 by jfieux            #+#    #+#             */
/*   Updated: 2020/10/01 11:41:20 by ppitavy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUF_SIZE 2000000000

typedef struct	s_parameters
{
	int		lenline;
	int		nbline;
	char	empty;
	char	obstruct;
	char	full;
}				t_parameters;

typedef struct	s_find
{
	int		top_right;
	int		low_left;
	int		low_diago;
	int		size;
	int		adress;
	int		count;
}				t_find;

char			*ft_parsing(int fd, t_parameters *para);
char			*ft_custom_cat(char *src1, char *src2);
int				ft_atoi(char *str);
int				ft_find_bigest(char *map, t_parameters *para, int i, int temp);
void			display(char *map, t_find *save, t_parameters *para);
int				len(char *str);
int				new_check(t_parameters *para, t_find *save, int i, int x);

#endif
