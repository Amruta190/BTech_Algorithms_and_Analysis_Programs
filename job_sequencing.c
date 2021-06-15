#include<stdio.h>
int sort(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void JS(int d[],int J[],int n,int p[],int k,int job[])
{
    int m=0,r,sum=0;
    for(int i=1;i<=n;i++)
    {
        r=d[i];
        if(J[r]==0)
        {
            J[r]=job[i];
            sum+=p[i];
            m+=1;
        }
        else
        {
            r=r-1;
            while(r>0)
            {
                if(J[r]==0)
                {
                    J[r]=job[i];
                    sum+=p[i];
                    m+=1;
                    break;
                }
                r=r-1;
            }
        }
        if(m==k)
            break;
    }
    printf("Optimal Sequence of jobs is : ");
    for(int i=1;i<=k;i++)
    {
        if(J[i]!=0)
            printf("%d ",J[i]);
    }
    printf("\nProfit is : %d",sum);
}
int main()
{
    int n;
    printf("Enter no.of jobs : ");
    scanf("%d",&n);
    int d[n],p[n],J[n];
    printf("Enter deadlines : ");
    for(int i=1;i<=n;i++)
        scanf("%d",&d[i]);
    printf("Enter profits : ");
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    int job[n];
    for(int i=1;i<=n;i++)
        job[i]=i;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(p[i]<p[j])
            {
                sort(&p[i],&p[j]);
                sort(&d[i],&d[j]);
                sort(&job[i],&job[j]);
            }
        }
    }
    int k=0;
    for(int i=1;i<=n;i++)
    {
        if(k<d[i])
            k=d[i];
    }
    for(int i=1;i<=k;i++)
        J[i]=0;
    JS(d,J,n,p,k,job);
}