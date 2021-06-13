#include<stdio.h>
int Prim(int,int);
#define infinity 9999
int n,names[10],cost[10][10],E[2][10],t[10][3];
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
        for(j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i!=j&&cost[i][j]==0)
                cost[i][j]=infinity;
        }
    }
    int p=0,k,l,min=infinity;
    for(i=2;i<=n;i++)
    {
        for(j=1;j<i;j++)
        {
            if(cost[i][j]!=infinity)
            {
                E[0][p]=names[i];
                E[1][p++]=names[j];
                if(min>=cost[i][j])
                {
                    min=cost[i][j];
                    k=i;l=j;
                }
            }
        }
    }
    int q=Prim(k,l);
    printf("Min cost is : %d",q);
}
int Prim(int k,int l)
{
    int i,x;
    int min_cost=cost[k][l],near[n];
    t[1][1]=k;t[1][2]=l;
    for(i=1;i<=n;i++)
    {
        if(cost[i][l]<cost[i][k])
            near[i]=l;
        else
            near[i]=k;
        near[k]=near[l]=0;
    }
    int j;
    for(i=2;i<n;i++)
    {
        int r=infinity;
        for(j=1;j<=n;j++)
        {
            if(near[j]!=0)
            {
                if(r>cost[j][near[j]])
                {
                    r=cost[j][near[j]]; 
                    x=j;
                }
            }
        }
        t[i][1]=x;
        t[i][2]=near[x];
        min_cost=min_cost+cost[x][near[x]];
        near[x]=0;
        for(k=1;k<=n;k++)
        {
            if(near[k]!=0 && (cost[k][near[k]] > cost[k][x]))
                near[k]=j;
        }
    }
    printf("\nEdge\tCost\n");
    for(i=1;i<n;i++)
        printf("%d-%d\t%d\n",names[t[i][1]],names[t[i][2]],cost[t[i][1]][t[i][2]]);
    return min_cost;
}