#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>

int main()
{
    printf("ClientSide..\n");
    char buffer[100];
    int sockid;
    struct sockaddr_in addr1,addr2;
    sockid=socket(AF_INET,SOCK_STREAM,0);

    addr2.sin_family=AF_INET;
    addr2.sin_addr.s_addr=INADDR_ANY;
    addr2.sin_port=3008;

    connect(sockid,(struct sockaddr *)&addr2,sizeof(addr2));
    do
    {
        printf("---------------------------------------------\n");
        printf("Enter the message to be sent...\n");
        scanf("%s",buffer);
        send(sockid,buffer,sizeof(buffer),0);
        printf("---------------------------------------------\n");
        printf("Message Received...\n");
        recv(sockid,buffer,sizeof(buffer),0);
        printf("%s",buffer);

    } while (strcmp(buffer,"stop")!=0);
    close(sockid);
    return 0;
}
