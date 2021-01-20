/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:55:43 by jfieux            #+#    #+#             */
/*   Updated: 2020/10/01 11:42:19 by ppitavy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strdup(char *str)
{
	char	*s1;
	int		i;

	if (!(s1 = malloc(sizeof(char) * len(str))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		s1[i] = str[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*init_info(int ret, int fd, char *buf, char *info)
{
	while ((ret = read(fd, buf, 1)) != 0)
	{
		buf[1] = '\0';
		if (!(info = ft_custom_cat(info, buf)))
			return (NULL);
		if (buf[0] == '\n')
			break ;
		if ((buf[0] < 32 || buf[0] > 126))
			return (NULL);
	}
	return (info);
}

int		parse_info(int fd, t_parameters *para, char *info, int i)
{
	char	buf[2];
	char	*str;

	if (!(info = init_info(0, fd, buf, info)))
		return (0);
	i = len(info) - 1;
	if (i < 4)
		return (0);
	if (info[i - 1] != info[i - 2] && info[i - 2] != info[i - 3] &&
		info[i - 1] != info[i - 3])
	{
		para->empty = info[i - 3];
		para->obstruct = info[i - 2];
		para->full = info[i - 1];
	}
	if (!(str = ft_strdup(info)))
		exit(0);
	str[i - 3] = '\0';
	para->nbline = ft_atoi(str);
	if (para->nbline <= 0)
		return (0);
	return (1);
}

char	*map_init(char *map, int fd)
{
	char	*buf;
	int		ret;

	if (!(buf = malloc(sizeof(char) * (BUF_SIZE + 1))))
		exit(0);
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		if (!(map = ft_custom_cat(map, buf)))
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	if (map[0] == 0)
		return (NULL);
	return (map);
}

char	*ft_parsing(int fd, t_parameters *para)
{
	char	*map;
	char	*info;

	if (!(info = malloc(sizeof(char))))
		exit(0);
	info[0] = '\0';
	if (!(parse_info(fd, para, info, 0)))
	{
		free(info);
		return (NULL);
	}
	free(info);
	if (!(map = malloc(sizeof(char))))
		exit(0);
	if (!(map = map_init(map, fd)))
		return (NULL);
	if (close(fd) < 0)
		return (NULL);
	return (map);
}
