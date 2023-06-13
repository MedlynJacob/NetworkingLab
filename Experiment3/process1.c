/*
The first process reads sentences from the user into the first named pipe
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<sys/wait.h>

int main()
{
    // Intialising the first named pipe

    char *myfifo="f1.txt";
    int fd1;

    // Creating pipe using function mkfifo with permission read and write to alll users
    mkfifo(myfifo,0666);
    char sent[100];
    printf("Enter the sentences..\n");
    fgets(sent,sizeof(sent),stdin);

    // writing into the pipe
    fd1=open(myfifo,O_WRONLY);
    write(fd1,sent,strlen(sent)+1);
    close(fd1);
    return 0;

}