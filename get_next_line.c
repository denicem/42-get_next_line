/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:17:59 by dmontema          #+#    #+#             */
/*   Updated: 2021/10/22 01:24:53 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readLine(int fd, char **storage)
{
	char	*readbuf;
	char	*res;
	int		bytesRead;

	readbuf = malloc(BUFFER_SIZE);
	res = malloc(1);
	if (readbuf == NULL || res == NULL)
		return (NULL);
	if (*storage)
	{
		res = ft_strjoin(res, *storage, ft_strlen(*storage));
		*storage = 0;
	}
	bytesRead = 1;
	while (bytesRead && !ft_strchr(readbuf, '\n'))
	{
		bytesRead = read(fd, readbuf, BUFFER_SIZE);
		if (bytesRead < 0)
			return (NULL);
		readbuf[bytesRead] = 0;
		res = ft_strjoin(res, readbuf, bytesRead);
	}
	if (bytesRead)
	{
		*storage = ft_strdup(ft_strchr(readbuf, '\n') + 1);
		*(ft_strchr(res, '\n') + 1) = 0;
	}
	return (res);
}

 char	*getStorage(char **storage)
{
	char	*res;
	int		i;

	i = 0;
	while ((*storage)[i] != '\n' && (*storage)[i])
		i++;
	res = malloc(1);
	if (res == NULL)
		return (NULL);
	res = ft_strjoin(res, *storage, i + 1);
	*storage = ft_strdup((*storage) + i + 1);
	res[i + 1] = 0;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char 		*res;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (storage && ft_strchr(storage, '\n'))
		return (getStorage(&storage));
	res = readLine(fd, &storage);
	// printf("storage: %s\n", storage);
	return (res);
}
