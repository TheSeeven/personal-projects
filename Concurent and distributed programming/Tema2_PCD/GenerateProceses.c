#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>

void printUsage() {
    printf("Usage: -n {NUMAR > 0} -m {NUMAR >= 0}\n");
    exit(EXIT_FAILURE);
}

void printParentsPID(pid_t parents[], size_t size) {
    for (size_t i = 0; i < size;i++) {
        printf("Parent PID: %d\n", parents[i]);
    }
}

void printBlank() {
    printf("\n\n\n\n\n");
}

int main(int argc, char **argv)
{

    int option = 0;
    int index = 0;

    int n = -1;
    int m = -1;

    static struct option long_options[] = {
        {"N_VALUE", required_argument, 0, 'n'},
        {"M_VALUE", required_argument, 0, 'm'},
        {0, 0, 0, 0}};

    while ((option = getopt_long(argc,argv, "n:m:", long_options, &index)) != -1)
    {
        switch (option)
        {
        case 'n':
            n = atoi(optarg);
            break;

        case 'm':
            m = atoi(optarg);
            break;
        default:
            printUsage();
            break;
        }
    }
    
    if (n <= 0 || m < 0)
    {
        printUsage();
    }

    pid_t parentsUid[n];
    pid_t childsID[m];

    pid_t mainPID = getpid();

    fprintf(stderr, "This is the main function with PID: %d\n", mainPID);

    for (int i = 0; i < n; i++) {
        pid_t id = fork();
        if (id == 0) {
            if(getppid()!=mainPID)
                break;
            parentsUid[i] = id;
            fprintf(stderr, "Parent process with ID: %d, PID: %d and PPID: %d\n", id, getpid(), getppid());
            
            for (int j = 0; j < m; j++)
            {
                pid_t cid = -1;
                if (id == 0)
                {
                    cid = fork();
                    if(cid > 0) {
                        childsID[j] = cid;
                        continue;
                    }
                }
                if (cid == 0)
                {
                    fprintf(stderr, "Child process with ID: %d, PID: %d and PPID: %d\n", cid, getpid(), getppid());
                    break;   
                }
                
            }
            
        }
        wait();
    }
    return 0;
}