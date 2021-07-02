#include <stdio.h>
int T[20][20], p[10], w[10];
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int Knapsack(int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int y = 1; y <= m; y++)
        {
            if (w[i] > y)
            {
                T[i][y] = T[i - 1][y];
            }
            else
            {
                T[i][y] = max(T[i - 1][y], p[i] + T[i - 1][y - w[i]]);
            }
        }
    }
    return T[n][m];
}
int main()
{
    int n, m;
    printf("Enter n, m values : ");
    scanf("%d%d", &n, &m);
    printf("Enter profit array : ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    printf("Enter weights array : ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    Knapsack(n, m);
    int x[n];
    int y = m;
    for (int i = n; i >= 0; i--)
    {
        if (T[i][y] == T[i - 1][y])
            x[i] = 0;
        else
        {
            x[i] = 1;
            y = y - w[i];
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            printf("%d\t", T[i][j]);
        }
        printf("\n");
    }
    printf("Maximum profit is : %d\n",T[n][m]);
    printf("Optimal solution x[i] values : ");
    for (int i = 1; i <= n; i++)
        printf("%d ", x[i]);
}