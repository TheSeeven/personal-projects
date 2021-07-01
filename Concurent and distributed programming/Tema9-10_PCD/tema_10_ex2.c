#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int number_of_threads = 9;
int process_number = 0;

void longExpensiveFileTask() {
    char processNumber = process_number + 48;
    char file_name[20] = { "Thread number X.txt" };
    file_name[14] = processNumber;
    char randomText[256] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Morbi sed gravida erat, non luctus eros.\nThread X Finished!";
    randomText[105] = processNumber;
    printf("%d | %d --> Processing the task...\n" , processNumber , getpid());
    sleep(7);
    FILE* fp;
    fp = fopen(file_name , "w+");
    for ( int i = 0; randomText[i] != '\0'; i++ ) {
        fputc(randomText[i] , fp);
    }
    fclose(fp);
    exit(0);
}

void startTasks() {
    printf("%d --> Starting the tasks...\n" , getpid());
    for ( int i = 0; i < number_of_threads; i++ ) {
        int child = fork();
        if ( child == 0 ) {
            longExpensiveFileTask();
        }
        process_number++;
    }
    wait(NULL);
    exit(0);
}


int main() {
    if ( number_of_threads > 9 ) {
        printf("main --> Cannot generate more than 9 threads!");
        return 0;
    }

    int taskStarter = fork();
    if ( taskStarter == 0 ) {
        startTasks();
    }
    printf("main --> Threads launched succesfully! \nWaiting for tasks to finish! \n");
    wait(NULL);
    printf("main --> Main function finished!\n");
    return 0;
}