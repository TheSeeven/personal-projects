#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>


void logs(char* msg , pid_t PID) {
    printf("err: %s -> %d" , msg , PID);
}

char* pidToString(pid_t pid) {
    char* result = malloc(30 * sizeof(char));
    sprintf(result , "I am darth Vader!->%d" , pid);
    return result;
}

void usage() {
    printf("Usage: -n {NUMBER > 2}\n");
}

int main(int argc , char** argv) {
    int option = 0;
    int index = 0;
    int n = -1;

    static struct option long_options[ ] = {
        {"N", required_argument, 0, 'n'},
        {0, 0, 0, 0} };
    while ( (option = getopt_long(argc , argv , "n:" , long_options , &index)) != -1 )
    {
        switch ( option )
        {
        case 'n':
            n = atoi(optarg);
            if ( n < 2 ) exit(EXIT_FAILURE);
            break;
        default:
            usage();
            exit(EXIT_FAILURE);
            break;
        }
    }
    if ( n <= 0 )
    {
        usage();
        exit(EXIT_FAILURE);
    }


    pid_t _MainPID = getpid();
    printf("Main process PID: %d \n" , _MainPID);

    int numberOfChildProcesses = n;
    int _fileDescriptor[numberOfChildProcesses + 1][2];

    char recvMsg[30];
    pipe(_fileDescriptor[numberOfChildProcesses]);
    for ( int i = 0; i < numberOfChildProcesses; i++ ) {
        pipe(_fileDescriptor[i]);
        write(_fileDescriptor[i][1] , pidToString(getpid()) , 30);
        close(_fileDescriptor[i][1]);

        pid_t childId = fork();
        if ( childId == 0 ) {
            read(_fileDescriptor[i][0] , recvMsg , 30);
            close(_fileDescriptor[i][0]);
            printf("PID: %d -> recv message '%s'\n" , getpid() , recvMsg);
            if ( i == numberOfChildProcesses - 1 ) {
                write(_fileDescriptor[numberOfChildProcesses][1] , pidToString(getpid()) , 30);
                close(_fileDescriptor[numberOfChildProcesses][1]);
            }
            continue;
        }
        break;
    }
    wait(NULL);
    if ( _MainPID == getpid() ) {
        read(_fileDescriptor[numberOfChildProcesses][0] , recvMsg , 30);
        close(_fileDescriptor[numberOfChildProcesses][0]);
        printf("PID: %d -> recv message '%s'\n" , getpid() , recvMsg);
    }
    wait(NULL);

    return 0;
}