#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

// pthread_create , pthread_exit  , pthread_attr_init  , pthread_attr_destroy , pthread_attr_setdetachstate , ptthread_join



void longExpensiveFileTask(void* arg) {
    char processNumber = (*( int* )arg) + 48;
    char file_name[20] = { "Thread number X.txt" };
    file_name[14] = processNumber;
    char randomText[256] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Morbi sed gravida erat, non luctus eros.\nThread X Finished!";
    randomText[105] = processNumber;
    printf("%d --> Processing the task...\n" , processNumber);
    sleep(7);
    FILE* fp;
    fp = fopen(file_name , "w+");
    for ( int i = 0; randomText[i] != '\0'; i++ ) {
        fputc(randomText[i] , fp);
    }
    fclose(fp);
    pthread_exit(0);
}

void startTasks(void* arg) {
    int number_of_threads = *( int* )arg;
    pthread_attr_t detachedThread;
    pthread_attr_init(&detachedThread);
    pthread_attr_setdetachstate(&detachedThread , PTHREAD_CREATE_DETACHED);


    pthread_t threads[number_of_threads];
    for ( int i = 0; i < number_of_threads; i++ ) {
        int* arg = ( int* )malloc(sizeof(int));
        *arg = i;
        pthread_create(&threads[i] , &detachedThread , ( void* )&longExpensiveFileTask , arg);
    }

    pthread_attr_destroy(&detachedThread);
    pthread_exit(0);
}


int main() {
    int number_of_threads = 9;
    int* number_of_thread_ptr = &number_of_threads;
    if ( number_of_threads > 9 ) {
        printf("Cannot generate more than 9 threads!");
    }

    pthread_t threadLauncher;
    pthread_create(&threadLauncher , NULL , ( void* )&startTasks , number_of_thread_ptr);
    printf("Threads launched succesfully! \nWaiting for tasks to finish! \n");
    pthread_join(threadLauncher , NULL);
    printf("Main function finished!\n");
    pthread_exit(0);
}