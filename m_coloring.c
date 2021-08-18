#include<stdio.h>
int x[100],adj[100][100],m,n;
void next_value(int k)
{
    int j;
    while(1)
    {
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0)
            return;
        for(j=1;j<=n;j++)
        {
            if((adj[k][j]!=0) && (x[k]==x[j]))
                break;
        }
        if(j==n+1)
            return;
    }
}
void m_coloring(int k)
{
    while(1)
    {
        next_value(k);
        if(x[k]==0)
            return;
        if(k==n)
        {
            for (int i = 1; i <= n; i++)
                printf("%d ", x[i]);
            printf("\n");
        }
        else
            m_coloring(k+1);
    }
}
int main()
{
    printf("Enter no.of vertices of the graph : ");
    scanf("%d",&n);
    printf("Enter adjacency matrix : ");
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&adj[i][j]);
    printf("Enter m value : ");
    scanf("%d",&m);
    for(int i=1;i<=n;i++)
        x[i]=0;
    m_coloring(1);
}