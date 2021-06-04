#include<stdio.h>
int max(int arr[],int n)
{
    int max1=arr[0];
    int i;
    for(i=1;i<n;i++)
    {
        if(arr[i]>max1)
            max1=arr[i];
    }
    return max1;
}
void main()
{
    int arr[20],n,i;
    printf("Enter array length : ");
    scanf("%d",&n);
    printf("Enter elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int final=max(arr,n);
    printf("The maximum value is : %d",final);
}