/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 01:17:40 by dmontema          #+#    #+#             */
/*   Updated: 2021/10/18 22:31:25 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	res;

	res = 0;
	while (s[res] != '\0')
		res++;
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			res = (char *) s + i;
			break ;
		}
		i++;
	}
	if (s[i] == (char) c)
		res = (char *) s + i;
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2, int len_s2)
{
	char	*res;
	int		i;
	int		j;

	res = (char *) malloc(ft_strlen(s1) + len_s2 + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (s1[0] != '\0')
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
	}
	while (s2[j] && j < len_s2)
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	byte_size;
	size_t	i;

	byte_size = count * size;
	res = malloc(byte_size);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < byte_size)
	{
		((unsigned char *) res)[i] = 0;
		i++;
	}
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;
	size_t	byte_size;

	byte_size = ft_strlen(s1);
	res = malloc(byte_size + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < byte_size)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}