#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <getopt.h>

#define MSG_LENGTH 50

void logs(char* msg , pid_t PID) {
    printf("err: %s -> %d" , msg , PID);
}

char* pidToString(pid_t pid) {
    char* result = malloc(MSG_LENGTH * sizeof(char));
    sprintf(result , "'I am darth Vader!' from: %d" , pid);
    return result;
}

void usage() {
    printf("Usage: -n {NUMBER > 2}\n");
}


int main(int argc , char** argv) {
    int option = 0;
    int index = 0;
    int numberOfChildProcesses = -1;

    static struct option long_options[ ] = {
        {"N", required_argument, 0, 'n'},
        {0, 0, 0, 0} };
    while ( (option = getopt_long(argc , argv , "n:" , long_options , &index)) != -1 )
    {
        switch ( option )
        {
        case 'n':
            numberOfChildProcesses = atoi(optarg);
            if ( numberOfChildProcesses < 2 ) exit(EXIT_FAILURE);
            break;
        default:
            usage();
            exit(EXIT_FAILURE);
            break;
        }
    }
    if ( numberOfChildProcesses <= 0 )
    {
        usage();
        exit(EXIT_FAILURE);
    }

    pid_t _MainPID = getpid();
    printf("Main process PID: %d \n" , _MainPID);

    char* _filename = "tema6";
    mkfifo(_filename , 0777);

    pid_t childId;
    int forked = 0;
    for ( int i = 0; i < numberOfChildProcesses; i++ ) {
        int _fileDescriptor[2];
        char recvMsg[MSG_LENGTH];
        childId = fork();
        if ( childId == 0 ) {
            sleep(1);
            _fileDescriptor[0] = open(_filename , O_RDONLY);
            read(_fileDescriptor[0] , recvMsg , MSG_LENGTH);
            printf("PID: %d <- %s \n" , getpid() , recvMsg);
            close(_fileDescriptor[0]);

            if ( i == numberOfChildProcesses - 1 ) {
                _fileDescriptor[1] = open(_filename , O_WRONLY);
                write(_fileDescriptor[1] , pidToString(getpid()) , MSG_LENGTH);
                close(_fileDescriptor[1]);
                exit(0);
            }
        }
        else {

            _fileDescriptor[1] = open(_filename , O_WRONLY);
            write(_fileDescriptor[1] , pidToString(getpid()) , MSG_LENGTH);
            close(_fileDescriptor[1]);

            if ( getpid() == _MainPID ) {
                sleep(numberOfChildProcesses + 1);
                _fileDescriptor[0] = open(_filename , O_RDONLY);
                read(_fileDescriptor[0] , recvMsg , MSG_LENGTH);
                printf("PID: %d <- %s \n" , getpid() , recvMsg);
                close(_fileDescriptor[0]);
                exit(0);
            }
            else {
                printf("%d PID will exit.\n" , getpid());
                return 0;
            }
        }
    }
    wait(NULL);
    return 0;
}