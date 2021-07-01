#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Usage of execv() of the command 'uname' \n");

    char *parameters[] = {"uname","-s", "-o",(char *)0};
    int result = execv("/bin/uname", parameters);

    printf("This line is lonely, it will never be reached, it is reached only in case of an error of the above command. %d\n", result);
    return 0;
}