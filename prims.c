#include<stdio.h>
#define infinity 9999
int n,names[10],cost[10][10],visited[10],arr[10];
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
    for(i=1;i<=n;i++)
        visited[i]=0;
    printf("\nEdge\tCost\n");
    int min=infinity,k=0,p,q,sum=0,count=0,x;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i!=j && min>=cost[i][j])
            {
                min=cost[i][j];
                x=i;
            }
        }
    }   
    visited[x]=1;
    while(count<n-1)
    {
        min=infinity;
        p=0,q=0;
        for(i=1;i<=n;i++)
        {
            if(visited[i]==1)
            {
                for(j=1;j<=n;j++)
                {
                    if(visited[j]==0 && cost[i][j])
                    {
                        if(min>cost[i][j])
                        {
                            min=cost[i][j];
                            p=i;
                            q=j;
                        }
                    }
                }
            }
        }
        printf("%d-%d\t%d\n",names[p],names[q],cost[p][q]);
        visited[q]=1;
        arr[k]=cost[p][q]; 
        k++;
        count++;
    }
    printf("\nMinimum cost = ");
    for(i=0;i<k;i++)
        sum=sum+arr[i];
    printf("%d",sum);
}