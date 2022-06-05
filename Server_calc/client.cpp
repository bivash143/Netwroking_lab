#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main()
{
    int sfd;
    char a[10], b[10], c[2];
    char buffer[1024];
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

    while(1){
        printf("Options..\n");
        printf("1. Add \n2. Sub \n3. Mul \n4. Div \n5. Exit\n");
        printf("Enter your option: ");
        scanf("%s",c);

        if(*c == '5'){
            sendto(sfd, c, 1024, 0, (struct sockaddr*)&server, sizeof(struct sockaddr));
            exit(0);
        }
        printf("Enter First Number: ");
        scanf("%s", a);
        printf("Enter Secon Number: ");
        scanf("%s", b);

        sendto(sfd, c, 1024, 0, (struct sockaddr*)&server, sizeof(struct sockaddr));
        sendto(sfd, a, 1024, 0, (struct sockaddr*)&server, sizeof(struct sockaddr));
        sendto(sfd, b, 1024, 0, (struct sockaddr*)&server, sizeof(struct sockaddr));

        socklen_t addr = sizeof(struct sockaddr);
        recvfrom(sfd, buffer, 1024, 0, (struct sockaddr*)&server, &addr);
        printf("\n%s\n\n", buffer);
    }
    return 0;
}

