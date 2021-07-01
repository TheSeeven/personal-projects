#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#include <pthread.h>

#define PORT 6000

void server_start()
{
    printf("Server: <PID, %d>,  astept conectare Client...\n", getpid());
}

bool isEnd(char *msg)
{
    char *endmsg = "sfarsit";
    for (int i = 0; i < 8; i++)
    {
        if (msg[i] != endmsg[i])
            return false;
    }
    return true;
}

void exitHandler(int sig)
{
    printf("\nServerul a fost inchis!\n");
    fflush(stdout);
    exit(0);
}

void handleClient(int *args)
{
    int new_socket = args[0];
    int server_fd = args[1];
    int valread;
    printf("Client connected!\n");
    while (1)
    {
        char buffer[1024] = {0};
        valread = read(new_socket, buffer, 1024);
        if (valread > 0)
        {
            if (isEnd(buffer))
            {
                close(server_fd);
                break;
            }
            printf("received: %s\n", buffer);
            fflush(stdout);
            send(new_socket, buffer, strlen(buffer), 0);
        }
        else
        {
            break;
        }
    }
    printf("Client Disconected!\n");
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    signal(SIGINT, exitHandler);

    server_start();
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    while (1)
    {

        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t *)&addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        pthread_t connection;
        int *ThreadArgs = (int *)malloc(sizeof(int) * 2);
        ThreadArgs[0] = new_socket;
        ThreadArgs[1] = server_fd;
        pthread_create(&connection, NULL, (void *)handleClient, ThreadArgs);
    }
}