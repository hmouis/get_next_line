#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char *get_next_line(int fd)
{
    char *after_newline;
    char *line;
    static char *str;
    char *buf;
    ssize_t count;

    if (BUFFER_SIZE <= 0)
        return (NULL);
    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);
    str = NULL;
    buf[0] = '\0';
    while (!ft_strchr(buf, '\n'))
    {
        count = read(fd, buf, BUFFER_SIZE);
        if (count <= 0)
            break;
        buf[count] = '\0';
        str = ft_strjoin(str, buf);
    }

    printf("str = %s\n", str);
    after_newline = ft_strchr(str, '\n');
    line = malloc(sizeof(char) * (ft_strlen(str) - ft_strlen(after_newline)));
    if (!line)
        return (NULL);
    line = ft_strcpy(line, str);
    str = strcpy(str, after_newline);
    printf("str = %s\n", str);
    printf("after_newline = %s\n", after_newline);
    return (line);
}

