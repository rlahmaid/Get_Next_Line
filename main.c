#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd;
	int n;
	char *line;
	//fd = open("./Get_Next_Line_Tester/test/normal.txt",O_RDONLY);
    fd = open("t.txt", O_RDONLY);
	//fd = 10;
	while((n = get_next_line(fd, &line)) >= 0)
	{
		printf("%d--%s\n",n,line);
		free(line);
        if (n <= 0)
            break ;
	}

    // n = get_next_line(fd, &line);
    // printf("%d   %s\n",n,line);
	// free(line);
    // n = get_next_line(fd, &line);
    // printf("%d   %s\n",n,line);
	// free(line);
    // n = get_next_line(fd, &line);
    // printf("%d   %s\n",n,line);
	// free(line);
    // n = get_next_line(fd, &line);
    // printf("%d   %s\n",n,line);
	// free(line);
    // n = get_next_line(fd, &line);
    // printf("%d   %s\n",n,line);
	// free(line);
    // n = get_next_line(fd, &line);
    // printf("%d   %s\n",n,line);
	// free(line);

}