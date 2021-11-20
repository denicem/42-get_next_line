/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 01:22:00 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/19 23:14:58 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <string.h>
#include <fcntl.h> 

int main() {
	// char *buff = malloc(BUFFER_SIZE);

	/*************	OWN TEST FILES	***************/
	// int fd = open("files/test1.txt", O_RDWR);
	int fd = open("files/test2.txt", O_RDWR);
	// int fd = open("files/test3.txt", O_RDWR);
	/*************	END TEST FILES	***************/

	/*************	TRI TEST FILES	***************/
	// int fd = open("files/empty", O_RDWR);
	// int fd = open("files/41_no_nl", O_RDWR);
	// int fd = open("files/41_with_nl", O_RDWR);
	// int fd = open("files/42_no_nl", O_RDWR);
	// int fd = open("files/42_with_nl", O_RDWR);
	// int fd = open("files/43_no_nl", O_RDWR);
	// int fd = open("files/43_with_nl", O_RDWR);
	// int fd = open("files/alternate_line_nl_no_nl", O_RDWR);
	// int fd = open("files/alternate_line_nl_with_nl", O_RDWR);
	// int fd = open("files/big_line_no_nl", O_RDWR);
	// int fd = open("files/big_line_with_nl", O_RDWR);
	// int fd = open("files/multiple_line_no_nl", O_RDWR);
	// int fd = open("files/multiple_line_with_nl", O_RDWR);
	// int fd = open("files/multiple_nlx5", O_RDWR);
	// int fd = open("files/nl", O_RDWR);
	/*************	END TEST FILES	***************/

	char *line;
	while ((line = get_next_line(fd)))
		printf("%s", line);

	// char *s;
	// s = get_next_line(-1);
	// s = get_next_line(1000);
	// printf("%s", s);

	// BONUS TESTS: TODO: doesn't work
	// int fd1 = open("test1.txt", O_RDONLY);
	// int fd2 = open("test2.txt", O_RDONLY);
	// int fd_bonus = fd1;
	// for (int i = 0; i < 6; i++)
	// {
	// 	printf("FD(%d): %s", fd_bonus, get_next_line(fd_bonus));
	// 	if (fd_bonus == fd1)
	// 		fd_bonus = fd2;
	// 	if (fd_bonus == fd2)
	// 		fd_bonus = fd1;
	// }

	// free(line);
	// system("leaks a.out");
	return 0;
}