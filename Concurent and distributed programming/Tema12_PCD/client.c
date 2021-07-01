#include <stdio.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#define PORT 5000

bool finished(char* msg) {
    char* endmsg = "done";
    for ( int i = 0; i < 8;i++ ) {
        if ( msg[i] != endmsg[i] ) return false;
    }
    return true;
}
int main(int argc , char** argv)
{
    int sock = 0 , valread;
    struct sockaddr_in serv_addr;
    char mesaj[128] = { 0 };
    char buffer[128] = { 0 };

    if ( (sock = socket(AF_INET , SOCK_DGRAM , 0)) < 0 )
    {
        printf("\n Socketul nu a fost creat \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if ( inet_pton(AF_INET , "127.0.0.1" , &serv_addr.sin_addr) <= 0 )
    {
        printf("\nAdresa invalida \n");
        return -1;
    }

    if ( connect(sock , ( struct sockaddr* )&serv_addr , sizeof(serv_addr)) < 0 )
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    while ( 1 ) {
        printf("Introduceti mesaje\n");
        scanf("%s" , mesaj);
        if ( finished(mesaj) ) {
            printf("Disconected\n");
            close(sock);
            break;
        }
        send(sock , mesaj , strlen(mesaj) , 0);
        sleep(2);
        valread = read(sock , buffer , 128);
        printf("%s\n" , buffer);
        memset(buffer , '\0' , 128);

    }
    return 0;
}
