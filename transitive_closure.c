#include <stdio.h>
int g[100][100];
void Transitive_closure(int n)
{
    int t[n][n];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            t[i][j]=g[i][j];
        }
    }
    for(int k=1;k<=n;k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                t[i][j]=t[i][j]||(t[i][k] && t[k][j]);
            }
        }
    }
    printf("Final matrix is :\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",t[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    printf("Enter n value : ");
    int n;
    scanf("%d", &n);
    printf("Enter the matrix :\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    Transitive_closure(n);
}