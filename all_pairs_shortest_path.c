#include<stdio.h>
int min(int a,int b)
{
    return (a>b)?b:a;
}
void print(int n,int a[n][n])
{
    printf("Matrix of shortest paths is \n");
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
}
void allPairs(int n,int c[n][n],int a[n][n])
{
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            a[i][j]=c[i][j];
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        }
    }
    print(n,a);
}
int main()
{
    int n,i,j;
    printf("Enter n value : ");
    scanf("%d",&n);
    int a[n][n],c[n][n];
    printf("Enter cost matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&c[i][j]);
    }
    allPairs(n,c,a);
}