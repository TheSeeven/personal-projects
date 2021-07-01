#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <unistd.h>
#include <stdlib.h>

struct msg { 
    int msgPPID;
    int msgPID;
    long _msgCounter;
    
} msg; 
  
int main() 
{ 
    key_t key;
    int id='l'; 
    char *path ="/tmp";
    int _msgID; 
     
    key = ftok(path, id); 
    _msgID = msgget(key, 0666 | IPC_CREAT); 
    msg._msgCounter = 1; 
    
    msg.msgPID=(long)getpid();
    msg.msgPPID=(long)getppid();

    fprintf(stderr,"PID %ld PPID %ld \n",(long)getpid(),(long)getppid());

    msgsnd(_msgID, &msg, sizeof(msg), 0); 
    printf("Sent -> PIDp1=%d AND PPIDp1=%d \n", msg.msgPID,msg.msgPPID);
    msg._msgCounter = 2;
    
    msgsnd(_msgID, &msg, sizeof(msg), 0);
    printf("Sent -> PIDp1=%d AND PPIDp1=%d \n", msg.msgPID, msg.msgPPID);
    msg._msgCounter = 3;
    
    msgsnd(_msgID, &msg, sizeof(msg), 0);
    printf("Sent -> PIDp1=%d AND PPIDp1=%d \n", msg.msgPID, msg.msgPPID);
}
