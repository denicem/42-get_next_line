/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 01:22:00 by dmontema          #+#    #+#             */
/*   Updated: 2021/10/22 00:50:59 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <errno.h>

int main() {
	// char *buff = malloc(BUFFER_SIZE);
	int fd = open("test1.txt", O_RDWR);
	//read(fd, buff, BUFFER_SIZE);
	// int i = 0;
	// while ((i = read(fd, buff, BUFFER_SIZE)))
	// 	printf("%d\n", i);
	// printf("%d\n", i);
	// printf("%d\n%s", fd, ft_strchr(buff, '\n'));
	char *line;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
	}
	//printf("%zd\n", read(fd, buff, BUFFER_SIZE));
	// if ((read(fd, buff, BUFFER_SIZE)) == -1)
	// 	printf("%s\n", strerror(errno));

	// while (i++ < 9)
	// 	printf ("%d: %s", i, get_next_line(fd));
		
	// int i = 0;
	// int j;
	// char *line;
	// while (i < 8)
	// {
	// 	j = 0;
	// 	line = get_next_line(fd);
	// 	while (line[j])
	// 		printf("%c", line[j++]);
	// 	//printf("\n");
	// 	i++;
	// }
	// while (i < 3)
	// {
	// 	line = get_next_line(fd);
	// 	printf("%s", line);
	// 	i++;
	// }
	// while ((line = get_next_line(fd)))
	// 	printf("%s", line);
	
	//system("leaks a.out");
	// char *line = get_next_line(fd);
	// printf("%s\n", line);
	// line = get_next_line(fd);
	// printf("%s\n", line);
	// line = get_next_line(fd);
	// printf("%s\n", line);
	//int readBytes = read(fd, buff, BUFFER_SIZE);
	//printf("%d %d\n", fd, readBytes);
	//printf("%s\n", buff);
	return 0;
}