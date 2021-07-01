#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
    printf("Usage of execlp() of the command 'pwd' \n");

    int result = execlp("pwd", "pwd", "-L", (char *)0);

    printf("This line is lonely, it will never be reached, it is reached only in case of an error of the abouve command. %d\n", result);
    return 0;
}