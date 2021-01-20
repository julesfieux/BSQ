/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitavy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:19:24 by ppitavy           #+#    #+#             */
/*   Updated: 2020/10/01 11:43:18 by ppitavy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display(char *map, t_find *save, t_parameters *para)
{
	int f;
	int g;
	int total_size;

	total_size = para->lenline * para->nbline;
	f = 0;
	while (f < save->size)
	{
		g = 0;
		while (g < save->size)
		{
			map[save->adress + (f * para->lenline + g)] = para->full;
			g++;
		}
		f++;
	}
	write(1, map, total_size);
}
