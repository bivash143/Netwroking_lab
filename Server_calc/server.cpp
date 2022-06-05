#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main(){
    int sfd, res=0;
    char a[10], b[10], c[2], buffer[1024];
    struct sockaddr_in server, client;

    sfd = socket(AF_INET, SOCK_DGRAM, 0);

    if(sfd < 0 ){
        printf("Socket Error");
        return -1;
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(7000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    bzero(&server.sin_zero, 16);
    bind(sfd, (struct sockaddr *)&server, sizeof(struct sockaddr));

    
    while(1){
        socklen_t addr = sizeof(struct sockaddr);
        recvfrom(sfd, c, 1024, 0, (struct sockaddr*)&client, &addr);
        if(*c == '5'){
            printf("Exiting...");
            exit(0);
        }
        recvfrom(sfd, a, 1024, 0, (struct sockaddr*)&client, &addr);
        recvfrom(sfd, b, 1024, 0, (struct sockaddr*)&client, &addr);

    printf("%d", res);
        switch(atoi(c)){
            case 1: res = atoi(a) + atoi(b);
                    break;
            case 2: res = atoi(a) - atoi(b);
                    break;
            case 3: res = atoi(a) * atoi(b);
                    break;
            case 4: res = atoi(a) / atoi(b);
                    break;
        }
        printf("%d", res);
        sprintf(buffer, "%d", res);
        sendto(sfd, buffer, 1024, 0, (struct sockaddr*)&client, sizeof(struct sockaddr));
    }
}
