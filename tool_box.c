/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:50:42 by jfieux            #+#    #+#             */
/*   Updated: 2020/10/01 12:05:17 by ppitavy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_custom_cat(char *src1, char *src2)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	if (!(dest = malloc(sizeof(char) * (len(src1) + len(src2) + 1))))
		exit(0);
	while (src1[i])
	{
		dest[i] = src1[i];
		i++;
	}
	j = 0;
	while (src2[j])
	{
		dest[i] = src2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_atoi(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

int		new_check(t_parameters *para, t_find *save, int i, int x)
{
	save->low_left = i + (para->lenline * x);
	save->top_right = i + x;
	save->low_diago = i + (para->lenline * x) + x;
	if (save->low_left > (para->nbline * para->lenline) ||
		save->top_right > (para->nbline * para->lenline) ||
		save->low_diago > (para->nbline * para->lenline))
		return (0);
	return (1);
}
