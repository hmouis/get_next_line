#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd = open("file.txt",O_RDWR);
    if (fd < 0)
    {
        printf("fd : failed");
        return 0;
    }
    char *buf;
    int i = 0;
    while((buf = get_next_line(fd)))
    {
        i++;
        printf("line[%d] = %s\n",i,buf);
        free(buf);
    }
}
