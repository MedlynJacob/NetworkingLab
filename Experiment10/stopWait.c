#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
   int i,j,n,frame[10][10],r,s;
   printf("Enter the number of frame :");
   scanf("%d",&n);
   printf("Enter the frame size : ");
   scanf("%d",&s);
   printf("Enter the frames\n");
   for(i=0;i<n;i++)
   {
    printf("%d : ",i+1);
    for(j=0;j<s;j++)
    {
        scanf("%d",&frame[i][j]);
    }
    
   }
   int nf=n;
   i=0;
   while(nf!=0)
   {
    printf("Sending packet....\n");
    r=rand()%5;
    if(r%2==0)
    {
        printf("Acknowledgement Receieved..\n");
        nf--;
    }
    else{
        printf("Acknowledgement not Receieved... wait fro %d sec",r);
        sleep(r);
        printf("Acknowledgement Receieved Now..\n");
        nf--;
    }
    for(j=0;j<s;j++)
    {
        printf("\t %d",frame[i][j]);
    }
    printf("\n");
    i++;
   }
   return 0;
}