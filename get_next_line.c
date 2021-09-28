/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:17:59 by dmontema          #+#    #+#             */
/*   Updated: 2021/09/28 23:01:26 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getStorage(char **storage)
{
	char *res;
	char *tmp;
	int i;

	i = 0;
	while (*storage[i] != '\n')
		i++;
	res = malloc(i + 1);
	if (res == NULL)
		return (NULL);
	res[0] = 0;
	res = ft_strjoin(res, *storage, i);
	tmp = *storage;
	*storage = ft_strdup(*storage + i + 1);
	free(tmp);
	return (res);
}

char	*get_next_line(int fd)
{
	static char *storage;
	char *readbuf;
	int r;
	int i;
	char *tmp;
	char *res;

	res = malloc(1);
	if (res == NULL)
		return (NULL);
	res[0] = 0;
	if (storage)
	{
		if (ft_strchr(storage, '\n'))
		{
			free(res);
			return(ft_getStorage(&storage));
		}
		tmp = res;
		res = ft_strjoin(res, storage, ft_strlen(storage));
		free(tmp);
		storage = 0;
	}
	readbuf = malloc(BUFFER_SIZE);
	if (readbuf == NULL)
		return (NULL);
	readbuf[0] = '\0';
	r = read(fd, readbuf, BUFFER_SIZE);
	while (!ft_strchr(readbuf, '\n'))
	{
		if (r <= 0)
			return (NULL);
		tmp = res;
		res = ft_strjoin(res, readbuf, BUFFER_SIZE);
		free(tmp);
		r = read(fd, readbuf, BUFFER_SIZE);
	}
	i = 0;
	while (readbuf[i] != '\n')
		i++;
	if (i < BUFFER_SIZE)
		storage = strdup(readbuf + i + 1);
	tmp = res;
	res = ft_strjoin(res, readbuf, i);
	free(tmp);
	printf("\nstorage*\n%s\n****\n", storage);
	return (res);
}

	// static char *saved;
	// char *readbuf;
	// char *res;
	// char *tmp;
	// int i = 0;
	// char *newl;

	// readbuf = malloc(BUFFER_SIZE);
	// if (readbuf == NULL)
	// 	return NULL;

	// res = malloc(1);
	// if (res == NULL)
	// 	return (NULL);
	// res[0] = 0;
	// if (saved)
	// {
	// 	newl = ft_strchr(saved, '\n');
	// 	if (newl)
	// 	{
	// 		while (saved[i] != '\n')
	// 			i++;
	// 		res = ft_strjoin(res, saved, i + 1);
	// 		tmp = saved;
	// 		saved = ft_strdup(saved + i + 1);
	// 		printf("\n *** SAVED REST \n%s\n *** \n\n", saved);
	// 		free(tmp);
	// 		printf("RES from saved: %s\n************\n", res);
	// 		return res;
	// 	}
	// 	res = ft_strjoin(res, saved, ft_strlen(saved));
	// 	saved = 0;
	// }
	// int end = read(fd, readbuf, BUFFER_SIZE);
	// printf("\nREADBUF: %s \n", readbuf);
	// if (end <= 0)	return NULL;
	// while (!ft_strchr(readbuf, '\n'))
	// {
	// 	printf("\nREADBUF: %s \n", readbuf);
	// 	tmp = res;
	// 	res = ft_strjoin(res, readbuf, BUFFER_SIZE);
	// 	free(tmp);
	// 	read(fd, readbuf, BUFFER_SIZE);
	// }
	// while (readbuf[i] != '\n' && i < BUFFER_SIZE) //counts i until the '\n'
	// 	i++;
	// if (i < BUFFER_SIZE)
	// {
	// 	saved = ft_strdup(readbuf + i + 1);
	// 	printf("\n *** SAVED \n%s\n *** \n\n", saved);
	// }
	// tmp = res;
	// res = ft_strjoin(res, readbuf, i + 1);
	// free(tmp);
	// 	printf("RES: %s\n************\n", res);
	// return res;
