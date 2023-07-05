#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys//types.h>
#include<sys/wait.h>

int main()
{
    int fd1[2],fd2[2],i,j=0,k;
    pid_t pd;
    char st[20],rev[20];
    int pipe1=pipe(fd1);
    int pipe2=pipe(fd2);

    pd=fork();
    if(pd<0)
    {
        printf("Error");
    }
    else if(pd>0)
    {
        printf("Enter the word to be reversed..");
        fgets(st,sizeof(st),stdin);
        write(fd1[1],st,strlen(st));
        close(fd1[1]);
        sleep(10);

        read(fd2[0],rev,sizeof(rev));
        printf("The reversed string is:\t%s",rev);
        close(fd2[0]);
    }
    else if(pd==0)
    {
        sleep(5);
        read(fd1[0],st,sizeof(st));
        close(fd1[0]);
        for(i=strlen(st)-1;i>=0;i--)
        {
            rev[j]=st[i];
            j++;
        }
        rev[j]='\0';
        write(fd2[1],rev,strlen(rev));
        close(fd2[1]);


    }


    return 0;
}