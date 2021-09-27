/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:17:59 by dmontema          #+#    #+#             */
/*   Updated: 2021/09/23 20:25:29 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *res;
	char buf[BUFFER_SIZE + 1];

	read(fd, buf, BUFFER_SIZE);
	res = malloc(ft_strlen(buf) + 1);
	if (res == NULL)	return NULL;
	ft_strlcpy(res, buf, ft_strlen(buf) + 1);
	//if buf does not have a '\n', then save curr buf to res, and read again and concat it to the saved string
	//do this process until buf has a '\n'
	return (res);
}
