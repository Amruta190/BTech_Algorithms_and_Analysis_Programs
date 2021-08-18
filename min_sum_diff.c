#include <stdio.h>
int main()
{
    printf("Enter array size : ");
    int n;
    scanf("%d", &n);
    int arr[n], sum = 0;
    printf("Enter array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("Sum : %d\n", sum);
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
            dp[i][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j]; //i-1th element is not included to get sum j
            if (arr[i - 1] <= j)     //i-1th element is included to get sum j
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
        }
    }  
    printf("dp\n\t");
    for (int i = 0; i <= sum; i++)
        printf("%d ", i);
    printf("\n\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d\t", i);
        for (int j = 0; j <= sum; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    for (int j = sum / 2; j >= 0; j--)
    {
        if (dp[n][j] == 1)
        {
            printf("Minimum difference is : %d", sum - 2 * j);
            break;
        }
    }
}