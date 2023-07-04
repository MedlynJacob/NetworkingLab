#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>

int main()
{
    char buffer[100];
    int sockid,s;
    struct sockaddr_in addr1;
    printf("Server Side\n");
    sockid=socket(AF_INET,SOCK_DGRAM,0);
    addr1.sin_family=AF_INET;
    addr1.sin_addr.s_addr=INADDR_ANY;
    addr1.sin_port=3008;

    
    s=sizeof(struct sockaddr_in);
    bind(sockid,(struct sockaddr *)&addr1,sizeof(addr1));
    do
    {
        printf("---------------------------------------------\n");
        printf("Receieved message...\n");
        recvfrom(sockid,buffer,sizeof(buffer),0,(struct sockaddr *)&addr1,&s);
        printf("%s",buffer);
        printf("---------------------------------------------\n");
        printf("Enter the message to be send...\n");
        scanf("%s",buffer);
        sendto(sockid,buffer,sizeof(buffer),0,(struct sockaddr *)&addr1,s);
    } while (strcmp(buffer,"stop")!=0);
    close(sockid);
    
    return 0;

}
