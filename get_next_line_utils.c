/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-n <fgalan-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:59:48 by fgalan-n          #+#    #+#             */
/*   Updated: 2023/01/17 14:34:20 by fgalan-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	size_t	i;
	size_t	tam2;
	size_t	tam1;

	tam1 = ft_strlen(s1);
	tam2 = ft_strlen(s2);
	string = (char *)malloc(tam1 + tam2 + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (i < tam1)
	{
		string[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < tam2)
	{
		string[tam1 + i] = s2[i];
		i++;
	}
	string[tam1 + i] = '\0';
	free(s1);
	return (string);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *) s)[i] = '\0';
			i++;
		}
	}	
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
