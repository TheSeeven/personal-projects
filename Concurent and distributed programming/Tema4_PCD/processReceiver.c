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
   
    fprintf(stderr,"PID %ld PPID %ld \n",(long)getpid(),(long)getppid());
   
    for(int i=0; i < 3;i++){
    msgrcv(_msgID, &msg, sizeof(msg), 0, 0);

    printf("Received <- PID_Sender=%d AND PID_Sender=%d \n", msg.msgPID, msg.msgPPID);
    msgctl(_msgID, IPC_RMID, NULL);
    }
    return 0; 
} 