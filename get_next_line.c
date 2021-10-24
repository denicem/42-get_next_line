/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:17:59 by dmontema          #+#    #+#             */
/*   Updated: 2021/10/24 04:13:20 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*getRes(char **storage, char **readbuf, char **res)
{
	char *newl;

	if (**res == 0)
	{
		free(*readbuf);
		free(*res);
		return (NULL);
	}
	newl = ft_strchr(*res, '\n');
	if (*(newl + 1) != 0)
		*storage = ft_strdup(newl + 1);
	*(newl + 1) = 0;
	free(*readbuf);
	**readbuf = 0;
	return (*res);
}

char	*readLine(int fd, char **storage, char **readbuf, char **res)
{
	int		bytesRead;
	char	*tmp;
	if (ft_strchr(*res, '\n'))
		return (getRes(storage, readbuf, res));
	bytesRead = BUFFER_SIZE;
	while (bytesRead == BUFFER_SIZE && !ft_strchr(*readbuf, '\n'))
	{
		bytesRead = read(fd, *readbuf, BUFFER_SIZE);
		if (bytesRead <= 0)
			break ;
		(*readbuf)[bytesRead] = 0;
		tmp = *res;
		*res = ft_strjoin(*res, *readbuf, bytesRead);
		free(tmp);
	}
	if (bytesRead == BUFFER_SIZE || **res == 0) // *
		return (getRes(storage, readbuf, res));
	free(*readbuf); // *
	**readbuf = 0; // *
	return (*res); // *if I comment these out, it gets more error from tri. it have to work without these, so it can save something (if necessary), although bytesRead is less than BUFFER_SIZE
}

int	prepareVars(int fd, char **storage, char **readbuf, char **res)
{
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (*storage)
		*res = ft_strdup(*storage);
	else
	{
		*res = malloc(1);
		**res = 0;
	}
	if (*res == NULL)
		return (0);
	*readbuf = malloc(BUFFER_SIZE + 1);
	if (*readbuf == NULL)
	{
		free(*res);
		return (0);
	}
	if (**res)
	{
		free(*storage);
		*storage = 0;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char 		*readbuf;
	char 		*res;
	if (!prepareVars(fd, &storage, &readbuf, &res))
		return (NULL);
	res = readLine(fd, &storage, &readbuf, &res);
	return (res);
}
