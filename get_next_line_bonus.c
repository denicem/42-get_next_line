/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:17:59 by dmontema          #+#    #+#             */
/*   Updated: 2021/10/26 19:55:38 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	"get_next_line_bonus.h"

# define BUFFER_SIZE 42

char	*getRes(char **storage, char **readbuf, char **res)
{
	char *newl;

	if (**res == 0)
	{
		free(*readbuf);
		**readbuf = 0;
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
	**readbuf = 0;
	return (*res);
}

char	*readLine(int fd, char **storage, char **readbuf, char **res)
{
	int		bytesRead;
	char	*tmp;

	if (!ft_strchr(*res, '\n'))
	{
		bytesRead = BUFFER_SIZE;
		while (bytesRead == BUFFER_SIZE && !ft_strchr(*readbuf, '\n'))
		{
			bytesRead = read(fd, *readbuf, BUFFER_SIZE);
			(*readbuf)[bytesRead] = 0;
			if (bytesRead <= 0)
				break ;
			tmp = *res;
			*res = ft_strjoin(*res, *readbuf, bytesRead);
			free(tmp);
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
	static char	*storage[OPEN_MAX];
	char 		*readbuf;
	char 		*res;
	if (!prepareVars(fd, &(storage[fd]), &readbuf, &res))
		return (NULL);
	res = readLine(fd, &(storage[fd]), &readbuf, &res);
	return (res);
}
