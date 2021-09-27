/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:17:59 by dmontema          #+#    #+#             */
/*   Updated: 2021/09/27 23:24:50 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *saved;
	char *readbuf;
	char *res;
	char *tmp;
	int i = 0;
	char *newl;

	readbuf = malloc(BUFFER_SIZE);
	if (readbuf == NULL)
		return NULL;

	res = malloc(1);
	if (res == NULL)
		return (NULL);
	res[0] = 0;
	if (saved)
	{
		//printf("*** NOTNULL *** saved: %s\n", saved);
		newl = ft_strchr(saved, '\n');
		if (newl)
		{
			while (saved[i] != '\n')
				i++;
			res = ft_strjoin(res, saved, i + 1);
			tmp = saved;
			saved = ft_strdup(saved + i + 1);
			free(tmp);
			return res;
		}
		res = ft_strjoin(res, saved, ft_strlen(saved));
	}
	int end = read(fd, readbuf, BUFFER_SIZE);
	//printf("READBUF: %s \n", readbuf);
	if (end <= 0)	return NULL;
	while (!ft_strchr(readbuf, '\n'))
	{
		tmp = res;
		res = ft_strjoin(res, readbuf, BUFFER_SIZE);
		free(tmp);
		read(fd, readbuf, BUFFER_SIZE);
	}
	while (readbuf[i] != '\n' && i < BUFFER_SIZE) //counts i until the '\n'
		i++;
	if (i < BUFFER_SIZE)
	{
		saved = ft_strdup(readbuf + i + 1);
		//printf("\nSAVED %s\n", readbuf);
	}
	tmp = res;
	res = ft_strjoin(res, readbuf, i + 1);
	free(tmp);
	return res;
}
