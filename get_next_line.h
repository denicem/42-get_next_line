/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:22:36 by dmontema          #+#    #+#             */
/*   Updated: 2021/10/24 04:14:47 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

# define BUFFER_SIZE 42
# include	<stdlib.h>
# include	<unistd.h>
# include	<limits.h>

char	*get_next_line(int fd);
int		prepareVars(int fd, char **storage, char **readbuf, char **res);
char	*readLine(int fd, char **storage, char **readbuf, char **res);
char	*getRes(char **storage, char **readbuf, char **res);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2, int len_s2);
char	*ft_strdup(const char *s1);

#	endif
