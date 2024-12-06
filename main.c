#include "get_next_line.h"
#include <libc.h>

int main()
{
	int fd = open ("file.txt", O_RDWR);
	char *line; 

	for (int i = 0; i < 7; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	return (0);
}
