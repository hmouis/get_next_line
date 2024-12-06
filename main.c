#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h" 
int main()
{
	int fd = open("/home/codespace/francinette/temp/get_next_line/fsoares/only_nl.txt",O_RDONLY);
	
	char * line  = get_next_line(fd);
	printf("%s",line);
}
