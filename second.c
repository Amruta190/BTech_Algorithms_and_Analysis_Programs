#include<stdio.h>
void main()
{
    int arr[10],n,i,j;
    printf("Enter n :");
    scanf("%d",&n);
    printf("Enter elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
    printf("First smallest element is %d\n",arr[0]);
    printf("Second smallest element is %d\n",arr[1]);
    printf("First largest element is %d\n",arr[n-1]);
    printf("Second largest element is %d\n",arr[n-2]);
}