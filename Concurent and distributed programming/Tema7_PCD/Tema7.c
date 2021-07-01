#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void _SignalHandler()
{
    printf("Signal received! PID: %d\n" , getpid());
}

int main(void)
{
    int _ChildPid = fork();
    if ( _ChildPid == -1 )
    {
        return 1;
    }
    if ( _ChildPid == 0 )
    {
        printf("Child PID= %d , PPID=%d\n" , getpid() , getppid());
        sleep(4);
        kill(getppid() , SIGUSR2);
        pause();
    }
    else {
        struct sigaction _actionHandler = { 0 };
        _actionHandler.sa_flags = SA_RESTART;
        _actionHandler.sa_handler = &_SignalHandler;
        sigaction(SIGUSR2 , &_actionHandler , NULL);

        printf("Parent PID= %d\n" , getpid());
        pause();
        printf("SIGUSR2 received from child process %d.\n" , _ChildPid);
        kill(_ChildPid , SIGINT);
    }
    printf("Process %d finished the program.\n" , getpid());
    return 0;
}