#include<stdio.h>
#include<conio.h>
void dijkstra(int n,int cost[10][10],int src)
{
    int p[10],vis[10],i,j,u,min,dist[10];
    for(i=0;i<n;i++)
    {
        dist[i]=cost[src][i];
        vis[i]=0;
        p[i]=src;
    }
    vis[src]=1;
    for(i=0;i<n;i++)
    {
        min = 999;
        for(j=0;j<n;j++)
        {
            if(vis[j]==0 && dist[j]<min)
            {
                min = dist[j];
                u = j;
            }
        }
        vis[u]=1;
        for(j=0;j<n;j++)
        {
            if(vis[j]==0 && (dist[u]+cost[u][j]<dist[j]))
            {
                dist[j]=dist[u]+cost[u][j];
                p[j]=u;
            }
        }
    }
    printf("finded shortest length from src to each noeds\n");
    for(i=0;i<n;i++)
    {
        printf("distance from %d to %d is:\n",src,i);
        j=i;
        while(j!=src)
        {
            printf("%d<-",j);
            j=p[j];
        }
        printf("%d",j);
        printf("::cost is %d\n",dist[i]);
    }
}
void main()
{
    int n,cost[10][10],src,i,j;
    printf("enter number of nodes\n");
    scanf("%d",&n);
    printf("enter cost adjecency matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    printf("enter the source vertex\n");
    scanf("%d",&src);
    dijkstra(n,cost,src);
}