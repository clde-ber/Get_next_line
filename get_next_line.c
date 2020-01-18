/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:12:28 by clde-ber          #+#    #+#             */
/*   Updated: 2020/01/18 13:40:18 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 1000000

int		get_next_line(int fd, char **line)
{
	size_t i;
	size_t j;
	char buf[BUFFER_SIZE + 1];
	static char *left;

	i = 0;
	buf[0] = '\0';
	if (!left)
	{
		if (!(left = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		left[0] = '\0';
	}
	line[0] = ft_strdup(left);
	ft_clear_left(left, BUFFER_SIZE);
	if (ft_find_n(line[0], ft_strlen(line[0])) != -1)
	{
		line[0][ft_find_n(line[0], ft_strlen(line[0]))] = '\0';
		printf("%s\n", line[0]);
		return (1);
	}
	while (ft_find_n(buf, BUFFER_SIZE) == -1)
	{
		if (!(i = read(fd, buf, BUFFER_SIZE)))
			break ;
		buf[i] = '\0';
		line[0] = ft_strjoin(line[0], buf);
	}
	if (i == 0)
		line[0] = ft_strjoin(line[0], buf);
	if (ft_find_n(line[0], ft_strlen(line[0])) != -1)
	{
		line[0][ft_find_n(line[0], ft_strlen(line[0]))] = '\0';
		ft_memcpy(left, buf + ft_find_n(buf, BUFFER_SIZE) + 1, ft_strlen(buf) + 1);
		printf("%s\n", line[0]);
		return (1);
	}
	else
		return (0);
}
