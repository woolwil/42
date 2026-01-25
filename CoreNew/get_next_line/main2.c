#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    int fd3 = open("file3.txt", O_RDONLY);
    char *line1, *line2, *line3;
    int i;

    if (fd1 == -1 || fd2 == -1 || fd3 == -1)
    {
        perror("open");
        return (1);
    }

    printf("--- Alternating reads from 3 files ---\n");
    for (i = 0; i < 4; i++)
    {
        line1 = get_next_line(fd1);
        if (line1) { printf("[file1] %s", line1); free(line1); }
        line2 = get_next_line(fd2);
        if (line2) { printf("[file2] %s", line2); free(line2); }
        line3 = get_next_line(fd3);
        if (line3) { printf("[file3] %s", line3); free(line3); }
    }

    close(fd1);
    close(fd2);
    close(fd3);
    return 0;
}
