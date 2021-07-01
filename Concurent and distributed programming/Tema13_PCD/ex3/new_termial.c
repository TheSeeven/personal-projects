#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <signal.h>
void writeToFile(int fd, char *data)
{
    int counter = 0;
    for (int i = 0; i < 128; i++)
    {
        if (data[i] == '\0')
        {
            break;
        }
        counter++;
    }
    write(fd, data, counter);
}

void endProgram(int dummy)
{
    printf("\nConsole terminated!\n");
    fflush(stdout);
    exit(0);
}

int main(int argc, char **argv)
{
    signal(SIGINT, endProgram);
    char inputString[128];

    FILE *file_adress = fopen("buffer", "a+");
    int file_descriptor = fileno(file_adress);
    while (1)
    {
        memset(inputString, '\0', sizeof(char) * 128);
        printf("Input String: ");
        fgets(inputString, 128, stdin);
        writeToFile(file_descriptor, inputString);
    }
    return 0;
}