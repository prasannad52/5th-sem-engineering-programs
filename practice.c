#include<stdio.h>
#include<unistd.h>
#define bktsize 700
int c=0;
int count=0;
void leakybucket(int a,int b,int i)
{
    if(a>(bktsize-c))
    {
        printf("overflow occurs and non confirmed packets\n");
    }
    else
    {
        sleep(1);
        while(a>b)
        {
            printf("%d bytes are outputed\n",b);
            a=a-b;
            sleep(1);
            count++;
        }
        if(a>0)
        {
            c=a+c;
            if(count==0)
            {
                printf("%d bytes are stored\n",c);
                count++;
            }
            else
            {
                if(c==b)
                {
                    printf("%d bytes are outputed\n",b);
                    c=0;
                }
                if(c>b)
                {
                    printf("%d bytes are outputed\n",b);
                    c=c-b;
                    printf("%d bytes are stored\n",c);
                }
                else
                {
                    printf("%d bytes are stored\n",c);
                }
            }
            printf("confirming packets\n");
        }
    }
    if(i==5&&c!=0)
    {
        printf("%d bytes stored are outputed\n");
    }
}
void main()
{
    int pktsize,oprate,i;
    printf("enter the output rate\n");
    scanf("%d",&oprate);
    for(i=1;i<=5;i++)
    {
        printf("enter %d packet:\n",i);
        scanf("%d",&pktsize);
        printf("%d packet having size %d\n",i,pktsize);
        leakybucket(pktsize,oprate,i);
    }
}