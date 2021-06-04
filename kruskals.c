#include<stdio.h>
#define infinity 999
int n,names[10],cost[10][10],visited[10],src[100],des[100],wei[100],k=0,parent[10];
void sort()
{
    int i,j;
    for(i=1;i<=k;i++)
    {
        for (j=1;j<=k-i;j++)
        {
            if (wei[j] > wei[j+1]) 
            {
                swap(&wei[j],&wei[j+1]);
                swap(&src[j],&src[j+1]);
                swap(&des[j],&des[j+1]);
            }
        }
    }
}
void swap(int *a, int *b)
{   
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void init()
{
    int i,j;
    printf("Enter no.of nodes : ");
    scanf("%d",&n);
    printf("Enter names of nodes : ");
    for(i=1;i<=n;i++)
        scanf("%d",&names[i]);
    printf("Enter cost matrix : ");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i!=j && cost[i][j]==0)
                cost[i][j]=infinity;
        }
    }
    for(i=1;i<=n;i++)
        visited[i]=0;
}
void kruskal()
{
    int i,j,count=0,p=0,min_cost=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i!=j && cost[i][j]!=infinity)
            {
                src[++k]=names[i];
                des[k]=names[j];
                wei[k]=cost[i][j];
            }
        }
    }
    sort();
    for(i=1;i<=k;i++)
    {
        for(j=i+1;j<=k;j++)
        {
            if(src[i]==des[j] && des[i]==src[j])
            {
                for(p=j;p<=k;p++)
                {
                    src[p]=src[p+1];
                    des[p]=des[p+1];
                    wei[p]=wei[p+1];
                }
                k--;
            }
        }
    }
    printf("After sorting edge weights\n");
    printf("Src   Des   Weight\n");
    for(i=1;i<=k;i++)
    {
        printf("%d\t%d\t%d\n",src[i],des[i],wei[i]);
    }
    for(i=1;i<=n;i++)
        parent[names[i]]=-1;
    printf("Edge\tCost\n");
    i=1;
    while(count<n-1)
    {
        if(parent[des[i]]==-1)
        {
            parent[des[i]]=src[i];
            printf("%d-\t%d\n",src[i],des[i],wei[i]);
            min_cost=min_cost+wei[i];
            count++;
        }
        i++;
    }
    printf("Minimum Cost = ",min_cost);
}
int main()
{
    init();
    kruskal();
}