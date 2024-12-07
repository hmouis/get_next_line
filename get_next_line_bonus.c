/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:31:19 by hmouis            #+#    #+#             */
/*   Updated: 2024/12/07 15:31:21 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strcpy(char *str, char *after_newline)
{
	int	i;

	i = 0;
	while (after_newline[i])
	{
		str[i] = after_newline[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*get_line(char *str, char *after_newline)
{
	char	*line;

	line = malloc(sizeof(char) * (ft_strlen(str) - ft_strlen(after_newline)
				+ 1));
	if (!line)
	{
		free(str);
		return (NULL);
	}
	line = ft_strcpy_nl(line, str);
	return (line);
}

static char	*fill_str(char *str, int fd)
{
	ssize_t	count;
	char	*buf;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (free(str), NULL);
	buf[0] = '\0';
	while (!ft_strchr(buf, '\n'))
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == 0)
			break ;
		if (count < 0)
		{
			free(str);
			str = NULL;
			break ;
		}
		buf[count] = '\0';
		str = ft_strjoin(str, buf);
		if (!str)
			return (free(buf), NULL);
	}
	return (free(buf), str);
}

static char	*check_after_nl(char **str)
{
	char	*line;

	if (str)
	{
		line = malloc(sizeof(char) * (ft_strlen(*str) + 1));
		if (!line)
		{
			free(*str);
			*str = NULL;
			return (NULL);
		}
		line = ft_strcpy(line, *str);
		free(*str);
		*str = NULL;
		return (line);
	}
	free(*str);
	str = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*after_newline;
	char		*line;
	static char	*str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = fill_str(str[fd], fd);
	if (!str[fd])
		return (NULL);
	after_newline = ft_strchr(str[fd], '\n');
	if (!after_newline)
		return (check_after_nl(&str[fd]));
	line = get_line(str[fd], after_newline);
	if (!line)
		return (str[fd] = NULL);
	str[fd] = ft_strcpy(str[fd], after_newline);
	if (str[fd] && str[fd][0] == '\0')
	{
		free(str[fd]);
		str[fd] = NULL;
	}
	return (line);
}
