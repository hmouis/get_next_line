
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:03:23 by hmouis            #+#    #+#             */
/*   Updated: 2024/12/04 16:03:26 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *str, char *after_newline)
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

char	*get_line(char *str, char *after_newline)
{
	char	*line;

	line = malloc(sizeof(char) * (ft_strlen(str) - ft_strlen(after_newline)));
	if (!line)
	{
		free(str);
		return (NULL);
	}
	line = ft_strcpy_nl(line, str);
	return (line);
}

char	*fill_str(char *str, int fd)
{
	ssize_t	count;
	char		*buf;

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
            break;
        }
		buf[count] = '\0';
		str = ft_strjoin(str, buf);
		if (!str)
        {
            free(buf);
			return (NULL);
        }
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*after_newline;
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = fill_str(str, fd);
	if (!str)
		return (NULL);
	after_newline = ft_strchr(str, '\n');
    if(!after_newline)
    {
        if(str)
        {
            line = malloc(sizeof(char) * (ft_strlen(str) + 1));
            line = ft_strcpy(line, str);
            free(str);
            return (str = NULL, line);
        }
        free(str);
        return (str = NULL);
    }
	line = get_line(str, after_newline);
	if (!line)
		return (str = NULL);
	str = ft_strcpy(str, after_newline);
    if (str && str[0] == '\0')
    {
        free(str);
        str = NULL;
    }
	return (line);
}
