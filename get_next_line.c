/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:17:59 by dmontema          #+#    #+#             */
/*   Updated: 2021/10/29 19:46:56 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

# define BUFFER_SIZE 42

char	*getRes(char **storage, char **readbuf, char **res)
{
	char	*newl;

	if (**res == 0)
	{
		free(*readbuf);
		*readbuf = 0;
		free(*res);
		*res = NULL;
		return (NULL);
	}
	newl = ft_strchr(*res, '\n');
	if (newl != NULL && *(newl + 1) != 0)
	{
		*storage = ft_strdup(newl + 1);
		*(newl + 1) = 0;
	}
	free(*readbuf);
	*readbuf = 0;
	return (*res);
}

char	*readLine(int fd, char **storage, char **readbuf, char **res)
{
	int		bytesRead;

	if (!ft_strchr(*res, '\n'))
	{
		bytesRead = BUFFER_SIZE;
		while (bytesRead == BUFFER_SIZE && !ft_strchr(*readbuf, '\n'))
		{
			bytesRead = read(fd, *readbuf, BUFFER_SIZE);
			if (bytesRead <= 0)
				break ;
			(*readbuf)[bytesRead] = 0;
			*res = ft_strjoin(*res, *readbuf, bytesRead);
		}
	}
	return (getRes(storage, readbuf, res));
}

int	prepareVars(int fd, char **storage, char **readbuf, char **res)
{
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (*storage)
	{
		*res = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
	}
	else
	{
		*res = ft_calloc(1, 1);
		if (*res == NULL)
			return (0);
		**res = 0;
	}
	*readbuf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (*readbuf == NULL)
	{
		free(*res);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*readbuf;
	char		*res;

	if (!prepareVars(fd, &storage, &readbuf, &res))
		return (NULL);
	res = readLine(fd, &storage, &readbuf, &res);
	return (res);
}
