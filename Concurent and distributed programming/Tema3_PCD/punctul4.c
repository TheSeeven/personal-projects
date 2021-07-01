#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Usage of execve() of the command 'uname' \n");

    char *env[] = {"HOME=/usr/home", "LOGNAME=home", (char *)0};
    char *parameters[] = {"uname", "-s", "-o", (char *)0};
    int result = execve("/bin/uname", parameters, env);

    printf("This line is lonely, it will never be reached, it is reached only in case of an error of the above command. %d\n", result);
    return 0;
}