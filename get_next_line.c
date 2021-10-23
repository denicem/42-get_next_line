/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:17:59 by dmontema          #+#    #+#             */
/*   Updated: 2021/10/22 23:53:37 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readLine(int fd, char **storage)
{
	char	*readbuf;
	char	*res;
	int		bytesRead;
	char	*tmp;

	readbuf = malloc(BUFFER_SIZE + 1);
	// printf("%p\n", &readbuf);
	res = malloc(1);
	if (readbuf == NULL || res == NULL)
		return (NULL);
	if (*storage)
	{
		tmp = res;
		res = ft_strjoin(res, *storage, ft_strlen(*storage));
		free(tmp);
		*storage = 0;
	}
	bytesRead = BUFFER_SIZE;
	while (bytesRead == BUFFER_SIZE && !ft_strchr(readbuf, '\n'))
	{
		bytesRead = read(fd, readbuf, BUFFER_SIZE);
	 	// printf("reaad %d\n", bytesRead);
		if (bytesRead < 0)
			return (NULL);
		readbuf[bytesRead] = 0;
		if (bytesRead == 0)
			break ;
		tmp = res;
		res = ft_strjoin(res, readbuf, bytesRead);
		free(tmp);
	}
	if (bytesRead == BUFFER_SIZE)
	{
	// printf("Here0 %d\n", bytesRead);
		tmp = *storage;
		*storage = ft_strdup(ft_strchr(readbuf, '\n') + 1);
		free(tmp);
		*(ft_strchr(res, '\n') + 1) = '\0';
	}
	// printf("Here1");
	if (*res == 0)
		return (NULL);
	free(readbuf);
	*readbuf = 0;
	return (res);
}

 char	*getStorage(char **storage)
{
	char	*res;
	int		i;
	char	*tmp;

	i = 0;
	while ((*storage)[i] != '\n' && (*storage)[i])
		i++;
	res = malloc(1);
	if (res == NULL)
		return (NULL);
	tmp = res;
	res = ft_strjoin(res, *storage, i + 1);
	free(tmp);
	tmp = *storage;
	*storage = ft_strdup((*storage) + i + 1);
	free(tmp);
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
	// printf("Here2\n");
	res = readLine(fd, &storage);
	return (res);
}
