/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:22:36 by dmontema          #+#    #+#             */
/*   Updated: 2021/10/22 23:58:24 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

#ifndef		BUFFER_SIZE
# define	BUFFER_SIZE 6

# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<string.h>
# include	<fcntl.h>

char	*get_next_line(int fd);
char	*readLine(int fd, char **storage);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2, int len_s2);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

#	endif
#	endif
