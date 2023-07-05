#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int buc_size,pac,store=0,out_rate,i,pac_s;
    printf("Enter the bucket size");
    scanf("%d",&buc_size);
    printf("Enter the output rate");
    scanf("%d",&out_rate);
    printf("Enter the number of packet");
    scanf("%d",&pac);
    while(pac!=0)
    {
        printf("enter the packet size\t");
        scanf("%d",&pac_s);
        if(pac_s<=buc_size-store)
        {
            store+=pac_s;
            printf("Packet accepted..\n");
            printf("Current Storage: \t%d",store);
        }
        else if(pac_s>buc_size-store)
        {
            printf("Packet Rejected...\n");
            printf("Current Storage: \t%d",store);
        }
        store-=out_rate;
        if(store<0)
        {
            store=0;
        }
        
        printf(" After leak Current Storage: \t%d",store);
        pac--;

    }
    return 0;
}