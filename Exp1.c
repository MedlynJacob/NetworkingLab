#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/wait.h>

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

    int pd=fork();
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
        for(i=0;i<n;i++)
        {
            printf("%d\t",arr[i]);
        }

    }
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
        for(i=0;i<n;i++)
        {
            printf("%d\t",arr[i]);
        }
    }

    return 0;

}