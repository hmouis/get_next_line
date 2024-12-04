/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:03:39 by hmouis            #+#    #+#             */
/*   Updated: 2024/12/04 16:03:43 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == c)
			return (s + i + 1);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*arr;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	i = 0;
	arr = (char *)malloc(sizeof(char) * s1_len + 1);
	if (arr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy_nl(char *line, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	i = ft_strlen(s1);
	j = 0;
	while (s1 && s1[j] != '\0')
	{
		new[j] = s1[j];
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	free(s1);
	return (new);
}
