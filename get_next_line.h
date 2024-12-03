#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char *get_next_line(int fd);
char *ft_strcpy_nl(char *line, char *str);

#endif
