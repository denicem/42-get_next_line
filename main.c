/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 01:22:00 by dmontema          #+#    #+#             */
/*   Updated: 2021/09/28 23:16:55 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main() {
	//char *buff;
	int fd = open("test1.txt", O_RDWR);
	int i = 0;
	// int j;
	char *line;
	// while (i < 8)
	// {
	// 	j = 0;
	// 	line = get_next_line(fd);
	// 	while (line[j])
	// 		printf("%c", line[j++]);
	// 	//printf("\n");
	// 	i++;
	// }
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("%s", line);
		i++;
	}
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