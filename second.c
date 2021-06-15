#include<stdio.h>
void main()
{
    int arr[10],n,i,j;
    printf("Enter n :");
    scanf("%d",&n);
    printf("Enter elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int max=arr[0],min=arr[0];
    for(i=1;i<n;i++)
    {
        if(max<arr[i])
            max=arr[i];
    }
    for(i=1;i<n;i++)
    {
        if(min>arr[i])
            min=arr[i];
    }
    int max2=min,min2=max;
    for(i=0;i<n;i++)
    {
        if(max2<arr[i] && arr[i]!=max)
            max2=arr[i];
    }
    for(i=0;i<n;i++)
    {
        if(min2>arr[i] && arr[i]!=min)
            min2=arr[i];
    }
    printf("Second largest element is %d\n",max2);
    printf("Second smallest element is %d\n",min2);
}