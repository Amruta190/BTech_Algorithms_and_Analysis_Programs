#include<stdio.h>
int max(int a,int b)
{
    return (a>b)?a:b;
}
int LIS(int n,int arr[],int count[])
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            {
                if(count[i]==count[j])
                    count[i]=count[j]+1;
                else
                    count[i]=max(count[i],count[j]);
            }
        }
    }
    int sequence[n], k=0,p=1,i=0,flag=0;
    while(i<n)
    {
        flag=0;
        while(count[i]==p && i<n)
        {
            i++;
        }
        if(count[i-1]==p)
        {
            flag=1;
            sequence[k++]=arr[i-1];
            p++;
        }
        if(flag==0)
            i++;
    }
    printf("The longest increasing subsequence is : \n");
    for(int i=0;i<k;i++)
        printf("%d ",sequence[i]);
}
int main()
{
    int n;
    printf("Enter array size : ");
    scanf("%d",&n);
    int arr[n],count[n];
    printf("Enter elements : ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<n;i++)
        count[i]=1;
    LIS(n,arr,count);
}