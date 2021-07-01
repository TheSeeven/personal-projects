#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdbool.h>
#include <dirent.h>
#include <stdlib.h>

int main()
{
    fd_set readfds;
    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    FILE *file_adress = fopen("buffer", "rw");
    int fd1 = fileno(file_adress);
    int fd;
    dup2(fd1, fd);

    while (1)
    {
        FD_ZERO(&readfds);
        FD_SET(fd, &readfds);

        int ret = select(1, &readfds, NULL, NULL, &timeout);
        timeout.tv_sec = 10;
        if (ret > 0)
        {
            char buf[1000] = {'\0'};
            read(fd, (void *)buf, 1000);
            printf("%s", buf);
        }
    }
    return 0;
}