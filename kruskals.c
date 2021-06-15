#include<stdio.h>
#define infinity 999
int n,names[10],cost[10][10],src[20],des[20],wei[20],k=0,parent[10];
void swap(int *a, int *b)
{   
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
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
int find(int i)
{
    while(parent[i])
        i=parent[i];
    return i;
}
int Union(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}
void kruskal()
{
    int i,j,count=1,p=0,min_cost=0;
    for(i=2;i<=n;i++)
    {
        for(j=1;j<i;j++)
        {
            if(cost[i][j]!=infinity)
            {
                src[++k]=names[i];
                des[k]=names[j];
                wei[k]=cost[i][j];
            }
        }
    }
    sort();
    printf("After sorting edge weights\n");
    printf("Src   Des   Weight\n");
    for(i=1;i<=k;i++)
        printf("%d\t%d\t%d\n",src[i],des[i],wei[i]);
    printf("Edge\tCost\n");
    i=1;
    while(count<n)
    {
        int x=find(src[i]);
        int y=find(des[i]);
        if(Union(x,y))
        {
    		printf("%d-%d\t%d\n",src[i],des[i],wei[i]);
            min_cost+=wei[i];
            count++;
        }
        i++;
    }
    printf("Minimum Cost = %d",min_cost);
}
int main()
{
    int i,j;
    printf("Enter no.of nodes : ");
    scanf("%d",&n);
    printf("Enter names of nodes : ");
    for(i=1;i<=n;i++)
        scanf("%d",&names[i]);
    printf("Enter cost matrix : \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(i!=j && cost[i][j]==0)
                cost[i][j]=infinity;
        }
    }
    kruskal();
}