#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<math.h>

int infinity=10000;
int main()
{
    struct route{
        char rou;
        int dis[20];
        char hop[20];
    }router[20];
    //i is router and j is the router destination
    int i,j,n,cost[20][20],c,k;
    char a;
    printf("Enter the details of the routing table");
    printf("Enter the number of routers");
    scanf("%d",&n);
    printf("Enter the router\n");
    for(i=0;i<n;i++)
    {
        scanf("%c",&router[i].rou);
        scanf("%c",&router[i].rou);
    }
    printf("Enter the Cost of each node");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter y if cost is there for %c and %c\n",router[i].rou,router[j].rou);
            scanf("%c",&a);
            scanf("%c",&a);
            if(a=='y')
            {
                scanf("%d",&cost[i][j]);
            }
            else if(i==j)
            {
                cost[i][j]=0;
            }
            else
            {
                cost[i][j]=infinity;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            router[i].dis[j]=cost[i][j];
            if(cost[i][j]!=infinity)
            {
                router[i].hop[j]=router[j].rou;
            }
        }
    }
    do
    {
        c=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    if(router[i].dis[j]>router[i].dis[k]+router[k].dis[j])
                    {
                       router[i].dis[j]=router[i].dis[k]+router[k].dis[j];
                       router[i].hop[j]=router[k].rou;
                    }
                }
            }
        }
    } while (c!=0);

    printf("Final Routing Table\n");
    for(i=0;i<n;i++)
    {
        printf("%c\tDistance\tHOP\n",router[i].rou);
        for(j=0;j<n;j++)
        {
            printf("\t\t%c\t%d\t%c\n",router[j].rou,router[i].dis[j],router[i].hop[j]);
        }
    }
    
    return 0;
}