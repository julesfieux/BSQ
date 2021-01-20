/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:14:01 by jfieux            #+#    #+#             */
/*   Updated: 2020/10/01 11:55:49 by ppitavy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		manage_ent(t_parameters *para, int fd, int i, int ac)
{
	char *map;

	if (!(map = ft_parsing(fd, para)))
	{
		free(map);
		free(para);
		write(1, "map error\n", 10);
		if (i < (ac - 1))
			write(1, "\n", 1);
		return (0);
	}
	if (!(ft_find_bigest(map, para, 0, 0)))
	{
		free(map);
		free(para);
		write(1, "map error\n", 10);
		if (i < (ac - 1))
			write(1, "\n", 1);
		return (0);
	}
	free(map);
	free(para);
	return (1);
}

int		init_bsq(int ac, char **av, int fd, int i)
{
	t_parameters *para;

	if (!(para = malloc(sizeof(t_parameters))))
		exit(0);
	if (ac == 1)
		return (manage_ent(para, 0, 1, ac));
	while (i < ac)
	{
		if (i > 1 && !(para = malloc(sizeof(t_parameters))))
			exit(0);
		if ((fd = open(av[i], O_RDONLY)) < 0)
		{
			write(1, "map error\n", 10);
			if (i < (ac - 1))
				write(1, "\n", 1);
		}
		else if (manage_ent(para, fd, i, ac) != 0)
			if (i < (ac - 1))
				write(1, "\n", 1);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (init_bsq(ac, av, 0, i) != 1)
		return (1);
	return (0);
}
