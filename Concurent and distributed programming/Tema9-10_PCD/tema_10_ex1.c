#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define LIMIT 1000

__uint64_t* val = 0;
int seed = 0;

void initialize_value() {
    srand(time(NULL));
    __uint64_t result = 0;
    int counter = 0;
    while ( 1 ) {
        sleep(1);
        if ( result == 0 ) {
            result = rand() % 10000000;
        }
        else {
            result = result * (rand() % 10000000);
        }
        printf("Mixing the return number! (current value: %lu)\n" , result);
        counter++;
        if ( counter == 6 ) {
            break;
        }
    }
    *val = result;
    exit(0);
}

void getRandomNumber() {
    __uint64_t limit = LIMIT;
    seed++;
    __uint64_t result = 0;
    result = (((*val / seed) + (seed / limit)) * limit) % limit;
    printf("Process number %d generated number %lu\n" , seed , result);
    exit(0);
}


int main() {

    val = ( __uint64_t* )mmap(NULL , 1 * sizeof(__uint64_t) ,
        PROT_READ | PROT_WRITE ,
        MAP_SHARED | MAP_ANONYMOUS ,
        0 , 0);

    int initialize_val_id = fork();
    if ( initialize_val_id == 0 ) {
        initialize_value();
    }
    wait(NULL);
    printf("Process initialised the value with %lu\n" , *val);

    int processes_id[5] = { 0 };
    for ( int i = 0; i < 5;i++ ) {
        seed = i;

        int child = fork();
        if ( child == 0 ) {
            struct sigaction parentAction = { 0 };
            parentAction.sa_flags = SA_RESTART;
            parentAction.sa_handler = &getRandomNumber;
            sigaction(SIGUSR2 , &parentAction , NULL);
            printf("Process %d waiting to start...\n" , seed);
            fflush(stdout);
            pause();
            exit(0);
        }
        processes_id[i] = child;
    }
    printf("Starting processes...\n");
    sleep(4);

    for ( int i = 0; i < 5; i++ ) {
        kill(processes_id[i] , SIGUSR2);
    }
    wait(NULL);
    printf("All processes stopped!\n");
    return 0;
}