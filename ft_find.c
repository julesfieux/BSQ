/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitavy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:27:09 by ppitavy           #+#    #+#             */
/*   Updated: 2020/10/01 11:37:35 by ppitavy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		search_inter(char *map, t_parameters *para, t_find *save)
{
	int i;

	i = save->low_diago;
	while (i > save->low_left)
	{
		if (map[i] != para->empty)
			return (0);
		i--;
	}
	i = save->low_diago;
	while (i > save->top_right)
	{
		if (map[i] != para->empty)
			return (0);
		i = i - para->lenline;
	}
	return (1);
}

int		search(char *map, int i, t_parameters *para, t_find *save)
{
	int x;

	x = 0;
	if ((para->lenline - save->size - 1 <= i - (save->count * para->lenline)) ||
		(para->nbline - save->size) * para->lenline < i)
		return (0);
	while (map[i + x] == para->empty)
	{
		if (new_check(para, save, i, x) == 0)
			break ;
		if (map[save->top_right] == para->empty
						&& map[save->low_left] == para->empty
						&& map[save->low_diago] == para->empty)
		{
			if (search_inter(map, para, save) == 1)
				x++;
			else
				return (x);
		}
		else
			return (x);
	}
	return (x);
}

int		check(char *map, t_parameters *para, int i, t_find *save)
{
	if (save->count >= para->nbline)
		return (0);
	if (map[i] != para->empty && map[i] != para->obstruct && map[i] != '\n')
		return (0);
	if (map[i] != '\n' && (i + 1) % para->lenline == 0)
		return (0);
	if (map[i] == '\n' && (i + 1) % para->lenline == 0)
		save->count = save->count + 1;
	if (map[i] == '\n' && (i + 1) % para->lenline != 0)
		return (0);
	if (map[i + 1] == '\0' && map[i] != '\n')
		return (0);
	if (map[i + 1] == '\0' && map[i] == '\n' && save->count != para->nbline)
		return (0);
	return (1);
}

void	set_lenline(t_parameters *para, char *map)
{
	int i;

	i = 1;
	while (map[i] != '\n' && map[i])
		i++;
	para->lenline = i + 1;
}

int		ft_find_bigest(char *map, t_parameters *para, int i, int temp)
{
	t_find	*save;

	if (!(save = malloc(sizeof(t_find))))
		exit(0);
	save->count = 0;
	save->size = 0;
	set_lenline(para, map);
	while (map[i])
	{
		if (check(map, para, i, save) == 0)
			return (0);
		if (map[i] == para->empty)
		{
			temp = search(map, i, para, save);
			if (temp > save->size)
			{
				save->size = temp;
				save->adress = i;
			}
		}
		i++;
	}
	display(map, save, para);
	free(save);
	return (1);
}
