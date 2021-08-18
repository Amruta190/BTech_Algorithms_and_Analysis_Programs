#include <stdio.h>
#include <stdlib.h>
int x[100];
int place(int k, int i)
{
    for (int j = 1; j <= k - 1; j++)
    {
        if (x[j] == i || (abs(x[j] - i)) == (abs(j - k)))
            return 0;
    }
    return 1;
}
void NQueens(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            if (k == n)
            {
                for (int j = 1; j <= n; j++)
                    printf("%d ", x[j]);
                printf("\n");
            }
            else
                NQueens(k + 1, n);
        }
    }
}
int main()
{
    printf("Enter no.of queens : ");
    int n;
    scanf("%d", &n);
    NQueens(1, n);
}