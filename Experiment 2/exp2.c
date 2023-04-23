/*Implement a full duplex communication between parent and child process.
Parent process writes Filename of a file on pipe1.
This filename is read by child process .
The child process writes the contents of the file to pipe 2.
The contents are read from pipe2 by the parent process and is displayed on standard output.*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/wait.h>

int main()
{
    int fd1[2],fd2[2],pipe1,pipe2,pd,i,sen=0,word=0,cha=0;
    char fname[20],fname2[20] ,fcont[500],final[500];
    FILE *f;
    
    //Creating two pipes
    pipe1=pipe(fd1);
    pipe2=pipe(fd2);

    //fork() to create a new process
    pd=fork();

    //Parent process
    if(pd>0)
    {
        printf("Process 1...Enter the file name\n");
        // file name used here is file.txt
        scanf("%s",fname);
        // writing the file name to pipe1
        write(fd1[1],fname,sizeof(fname)+1);
        close(fd1[1]);

        // Waiting for the child process
        sleep(8);
        // Reading the contents from the second pipe
        printf("Process 1....Reading the contents\n");
        read(fd2[0],final,sizeof(final)+1);
        printf("%s",final);

    }
    else if(pd==0)
    {
        // waiting for the parent process 
        sleep(5);
        //reading from the first pipe
      
        read(fd1[0],fname2,sizeof(fname2));
        close(fd1[0]);
        printf("File name is : %s\n",fname2);
        printf("Reading the name of the file...\n");
        f=fopen(fname2,"r");
        fgets(fcont,sizeof(fcont),f);
        printf("Process2...Writing the contents of the file...\n");
        //writing to the second pipe
        write(fd2[1],fcont,sizeof(fcont)+1);
        close(fd2[1]);
    }


    return 0;
}