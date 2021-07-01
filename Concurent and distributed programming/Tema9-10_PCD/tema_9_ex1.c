#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIMIT 1000

// pthread_create , pthread_exit  , pthread_cond_signal,  pthread_cond_wait, pthread_cond_init  , pthread_cond_destroy 

struct getRandomNumber {
    __uint64_t seed;
    __uint64_t limit;
};


__uint64_t val = 0;
bool start = false;
pthread_mutex_t mutexStartThreads;
pthread_cond_t threadsStartCondition;

void initialize_value() {
    srand(time(NULL));
    __uint64_t* result = ( __uint64_t* )malloc(1 * sizeof(__uint64_t));
    int counter = 0;
    while ( 1 ) {
        sleep(1);
        if ( *result == 0 ) {
            *result = rand() % 10000000;
        }
        else {
            *result = *result * (rand() % 10000000);
        }
        printf("Mixing the return number! (current value: %lu)\n" , *result);
        counter++;
        if ( counter == 6 ) {
            break;
        }
    }
    pthread_exit(result);
}

void getRandomNumber(struct getRandomNumber* args) {
    __uint64_t seed = ( __uint64_t )(*args).seed;
    __uint64_t limit = ( __uint64_t )(*args).limit;
    seed++;
    pthread_mutex_lock(&mutexStartThreads);
    printf("Thread %lu waiting to start...\n" , seed);
    pthread_cond_wait(&threadsStartCondition , &mutexStartThreads);
    pthread_mutex_unlock(&mutexStartThreads);

    if ( start ) {

        __uint64_t result = 0;
        result = (((val / seed) + (seed / limit)) * limit) % limit;
        printf("Thread number %lu generated number %lu\n" , seed , result);

    }
    else {
        printf("Thread %lu was not supposed to be started!\n" , seed);
    }
}

int main() {
    pthread_mutex_init(&mutexStartThreads , NULL);
    pthread_cond_init(&threadsStartCondition , NULL);

    pthread_t threads[8];

    for ( __uint64_t i = 0; i < 8;i++ ) {
        struct getRandomNumber* args = ( struct  getRandomNumber* )malloc(1 * sizeof(struct getRandomNumber));
        args->seed = i;
        args->limit = LIMIT;
        pthread_create(&threads[i] , NULL , ( void* )getRandomNumber , args);
    }


    pthread_t initVal;

    pthread_create(&initVal , NULL , ( void* )initialize_value , NULL);
    __uint64_t* thread_return;
    pthread_join(initVal , ( void* )&thread_return);
    val = *thread_return;
    printf("Thread initialised the value %lu\n" , *thread_return);

    printf("Starting random seed threads...\n");
    sleep(2);
    start = true;
    for ( int i = 0; i < 8; i++ ) {
        pthread_cond_signal(&threadsStartCondition);
    }

    for ( int i = 0; i < 8; i++ ) {
        pthread_join(threads[i] , NULL);
    }
    printf("All threads stopped!\n");


    pthread_mutex_destroy(&mutexStartThreads);
    pthread_cond_destroy(&threadsStartCondition);
    return 0;

}