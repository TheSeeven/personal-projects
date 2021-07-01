#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <resolv.h>
#include <pthread.h>
#include <stdbool.h>

#define MAXBUF 1024
#define MAXHOSTNAME 100
#define SERV_UDP_PORT 5000
struct sockaddr_in server_addr;
struct hostent *he;

struct NewClient
{
    struct sockaddr_in a;
    socklen_t b;
    int c;
    char *d;
    ssize_t e;
};

void handleClient(struct NewClient *params)
{
    struct sockaddr_in client_addr = params->a;
    socklen_t lung = params->b;
    int sd = params->c;
    char *buffer = params->d;
    ssize_t rc = params->e;
    if (rc > 0)
    {
        printf("---UDPServer. Am primit date de la %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(server_addr.sin_port));
        he = gethostbyaddr((char *)&client_addr.sin_addr.s_addr, sizeof(client_addr.sin_addr.s_addr), AF_INET);
        printf("\t(cu nume: %s)\n", he->h_name);

        printf("---UDPServer. Am primit: %s\n", buffer);

        sendto(sd, buffer, strlen(buffer), 0, (struct sockaddr *)&client_addr, (socklen_t)lung);
        bzero((char *)&client_addr, sizeof(client_addr));
        for (rc = 0; rc < MAXBUF; rc++)
            buffer[rc] = '\0';
    }
    while (rc = recvfrom(sd, buffer, MAXBUF, MSG_WAITALL, (struct sockaddr *)&client_addr, &lung) > 0)
    {
        printf("---UDPServer. Am primit date de la %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(server_addr.sin_port));
        he = gethostbyaddr((char *)&client_addr.sin_addr.s_addr, sizeof(client_addr.sin_addr.s_addr), AF_INET);
        printf("\t(cu nume: %s)\n", he->h_name);

        printf("---UDPServer. Am primit: %s\n", buffer);

        sendto(sd, buffer, strlen(buffer), 0, (struct sockaddr *)&client_addr, (socklen_t)lung);
        bzero((char *)&client_addr, sizeof(client_addr));
        for (rc = 0; rc < MAXBUF; rc++)
            buffer[rc] = '\0';
    }
    pthread_exit(NULL);
}

bool checkRC(ssize_t *clients, ssize_t val)
{
    for (int i = 0; i < 100; i++)
    {
        if (clients[i] == val)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int sd, lungime;
    socklen_t lung;
    ssize_t rc;
    struct sockaddr_in client_addr;
    char buffer[MAXBUF];
    char NumeServer[MAXHOSTNAME];
    gethostname(NumeServer, MAXHOSTNAME);
    printf("\n----UDPServer startat pe hostul: %s\n", NumeServer);
    he = gethostbyname(NumeServer);
    bcopy(he->h_addr, &(server_addr.sin_addr), he->h_length);
    printf(" \t(UDPServer INET ADDRESS (IP) este: %s )\n", inet_ntoa(server_addr.sin_addr));
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_UDP_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    sd = socket(AF_INET, SOCK_DGRAM, 0);
    if (bind(sd, (struct sockaddr *)&server_addr, sizeof(server_addr)) != 0)
    {
        perror("bind");
        abort();
    }
    lungime = sizeof(server_addr);
    getsockname(sd, (struct sockaddr *)&server_addr, &lungime);
    printf("---UDPServer. Portul este: %d\n", ntohs(server_addr.sin_port));
    lung = sizeof(client_addr);
    bzero((char *)&client_addr, sizeof(client_addr));
    for (rc = 0; rc < MAXBUF; rc++)
        buffer[rc] = '\0';

    ssize_t clients[100] = {0};
    int clientsCounter = 0;
    while (rc = recvfrom(sd, buffer, MAXBUF, MSG_WAITALL, (struct sockaddr *)&client_addr, &lung) > 0)
    {
        if (!checkRC(clients, rc))
        {
            clients[clientsCounter] = rc;
            clientsCounter++;

            struct NewClient *parameters = (struct NewClient *)malloc(sizeof(struct NewClient));
            char *newBuffer = (char *)malloc(sizeof(char) * 1000);
            for (int i = 0; i < 1000; i++)
            {
                newBuffer[i] = buffer[i];
            }
            parameters->a = client_addr;
            parameters->b = lung;
            parameters->c = sd;
            parameters->d = newBuffer;
            parameters->e = rc;

            pthread_t newClient;
            pthread_create(&newClient, NULL, (void *)handleClient, parameters);
        }
    }
    printf("%s:%d terminat\n", inet_ntoa(client_addr.sin_addr), ntohs(server_addr.sin_port));
    close(sd);
    return 0;
}
