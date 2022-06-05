#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    int sfd;
    char buffer[1024];
    struct sockaddr_in client, server;
    sfd = socket(AF_INET, SOCK_DGRAM, 0);

    if(sfd < 0){
        printf("Socket Error");
        return -1;
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(7000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    bzero(&server.sin_zero, 16);

    printf("Sned message to server: ");
    scanf("%s", buffer);
    sendto(sfd, buffer, 1024, 0, (struct sockaddr*)&server, sizeof(struct sockaddr));

    return 0;
}
