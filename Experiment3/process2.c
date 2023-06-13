/*
The second process reads sentences from the first named pipe and find the number of characters, words and sentences and writes it into second named pipe.
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<ctype.h>

int main()
{
    // Intialising the first named pipe
    
    char *myfifo="f1.txt";
    char *myfifo2="f2.txt";
    int fd1,fd2,i,word=0,cha=0,sen=0;

    // Creating pipe using function mkfifo with permission read and write to alll users
    mkfifo(myfifo,0666);
    mkfifo(myfifo2,0666);
    char recv[100],out[200];
    
    //Reading from pipe 1
    fd1=open(myfifo,O_RDONLY);
    read(fd1,recv,sizeof(recv)+1);
    close(fd1);
    for(i=0;i<strlen(recv);i++)
    {
        if(isblank(recv[i]))
        {
            word++;

        }
        if(isalnum(recv[i]))
        {
            cha++;
        }
        if(recv[i]=='.')
        {
            cha++;
            word++;
            sen++;
        }
    }
    sprintf(out,"Sentence Entered :%s\nNo. of Sentences: %d\nNo. of Words: %d\nNo. of Characters: %d",recv,sen,word,cha);
    fd2=open(myfifo2,O_WRONLY);
    write(fd2,out,strlen(out)+1);
    close(fd2);
    return 0;

}