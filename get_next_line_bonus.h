/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:22:36 by dmontema          #+#    #+#             */
/*   Updated: 2021/10/27 00:14:02 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define	GET_NEXT_LINE_BONUS_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<limits.h>

char	*get_next_line(int fd);
int		prepareVars(int fd, char **storage, char **readbuf, char **res);
char	*readLine(int fd, char **storage, char **readbuf, char **res);
char	*getRes(char **storage, char **readbuf, char **res);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2, int len_s2);
char	*ft_strdup(const char *s1);

#	endif
