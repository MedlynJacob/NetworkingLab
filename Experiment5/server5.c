#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>

int main ()
{
    printf("Server Side..\n");
    int sockid,newsockid,s;
    char buffer[100];
    struct sockaddr_in addr1,addr2;

    addr1.sin_family=AF_INET;
    addr1.sin_addr.s_addr=INADDR_ANY;
    addr1.sin_port=3008;

    s=sizeof(struct sockaddr_in);

    sockid=socket(AF_INET,SOCK_STREAM,0);

    bind(sockid,(struct sockaddr *)&addr1,sizeof(addr1));
    listen(sockid,5);
    newsockid=accept(sockid,(struct sockaddr *)&addr2,&s);

    do
    {
        printf("Established connection ...\n");
        printf("---------------------------------------------\n");
        printf("Message Received...\n");
        recv(newsockid,buffer,sizeof(buffer),0);
        printf("%s",buffer);
        printf("---------------------------------------------\n");
        printf("Enter the message to be sent...\n");
        scanf("%s",buffer);
        send(newsockid,buffer,sizeof(buffer),0);
        
        
    } while (strcmp(buffer,"stop")!=0);
    close(sockid);
    close(newsockid);
    
    return 0;
}