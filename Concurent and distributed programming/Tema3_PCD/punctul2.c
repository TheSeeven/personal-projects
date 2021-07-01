#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Usage of execle() of the command 'echo' \n");

    char *env[] = {"HOME=/usr/home", "LOGNAME=home", (char *)0};
    int result = execle("/bin/echo", "echo","This day is awesome", (char *)0, env);

    printf("This line is lonely, it will never be reached, it is reached only in case of an error of the above command. %d\n", result);
    return 0;
}