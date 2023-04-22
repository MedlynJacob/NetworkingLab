#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/wait.h>

int display(int arr [], int n);
int main()
{
    int arr[20],n,temp,i,j;
    printf("Enter the no. of integers\n");
    scanf("%d",&n);
    printf("Enter the integers\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }   

    // fork() creates new process
    int pd=fork();

    //Child process
    if(pd==0)
    {
        printf("\nThis is a child process... descending order\t");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr[i]>arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
        display(arr,n);

    }

    // Parent process
    else if(pd>0)
    {
        printf("\nThis is a parent process... ascending order\t");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr[i]<arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
        display(arr,n);
        
    }

    return 0;

}

int display(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}