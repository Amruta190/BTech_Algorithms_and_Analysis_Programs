#include<stdio.h>
void Knapsack(int n,float M,float profit[],float weights[]);
int sort(float *a,float *b)
{
    float tmp=*a;
    *a=*b;
    *b=tmp;
}
void main()
{
    int n;
    float M;
    printf("Enter no.of items : ");
    scanf("%d",&n);
    printf("Enter capacity : ");
    scanf("%f",&M);
    float profit[n],weights[n];
    printf("Enter profits : ");
    for(int i=1;i<=n;i++)
        scanf("%f",&profit[i]);
    printf("Enter weights : ");
    for(int i=1;i<=n;i++)
        scanf("%f",&weights[i]);
    float profit_density[n];
    for(int i=1;i<=n;i++)
        profit_density[i]=profit[i]/weights[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(profit_density[i]<profit_density[j])
            {
                sort(&profit_density[i],&profit_density[j]);
                sort(&profit[i],&profit[j]);
                sort(&weights[i],&weights[j]);
            }
        }
    }
    Knapsack(n,M,profit,weights);
}
void Knapsack(int n,float M,float profit[],float weights[])
{
    float x[n];
    for(int i=1;i<=n;i++)
        x[i]=0.0;
    float rc=M;
    int i;
    for(i=1;i<=n;i++)
    {
        if(weights[i]>rc)
            break;
        else
        {
            x[i]=1.0;
            rc=rc-weights[i];
        }
    }
    if(i<=n)
        x[i]=rc/weights[i];
    printf("Optimal sequence of xi : ");
    for(int i=1;i<=n;i++)
        printf("%.2f ",x[i]);
    float sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=x[i]*profit[i];
    }
    printf("\nMaximum profit is %.2f",sum);
}