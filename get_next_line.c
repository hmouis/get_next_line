#include "get_next_line.h"

char *ft_strcpy(char *str, char *after_newline)
{
    int i;

    i = 0;
    while (after_newline[i])
    {
        str[i] = after_newline[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *get_next_line(int fd)
{
    char *after_newline;
    char *line;
    static char *str;
    char *buf;
    ssize_t count;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
    {
        free(str);
        return (str = NULL);
    }
    while (!ft_strchr(buf, '\n'))
    {
        count = read(fd, buf, BUFFER_SIZE);
        if (count <= 0)
            break;
        buf[count] = '\0';
        str = ft_strjoin(str, buf);
        if (!str)
        {
            free(str);
            return (str = NULL);
        }
    }
    free(buf);
    after_newline = ft_strchr(str, '\n');
    line = malloc(sizeof(char) * (ft_strlen(str) - ft_strlen(after_newline)));
    if (!line)
    {
        free(str);
        return (str = NULL);
    }
    line = ft_strcpy_nl(line, str);
    if (!after_newline)
    {
        free(str);
        return (str = NULL);
    }
    str = ft_strcpy(str, after_newline);
    return (line);
}
