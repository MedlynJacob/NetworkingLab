/*
The Third process reads the output from second named pipe and displays it on the screen
*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    char *myfifo2="f2.txt";
    char final[200];
    mkfifo(myfifo2,0666);
    int fd2;
    fd2=open(myfifo2,O_RDONLY);
    read(fd2,final,sizeof(final));
    close(fd2);
    printf("%s",final);
    return 0;
}