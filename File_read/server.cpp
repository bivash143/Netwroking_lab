#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>

int main()
{
    int sfd;
    char buffer[1024]={0};
    struct sockaddr_in server, client;

    sfd = socket(AF_INET, SOCK_DGRAM, 0);

    if(sfd < 0){
        printf("socket error");
        return -1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(7000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    bzero(&server.sin_zero, 16);
    bind(sfd, (struct sockaddr*)&server, sizeof(struct sockaddr));

    socklen_t addr = sizeof(struct sockaddr);
    recvfrom(sfd, buffer, 1024, 0, (struct sockaddr*)&server, &addr);
    printf("\n%s\n",buffer);
    return 0;
}
