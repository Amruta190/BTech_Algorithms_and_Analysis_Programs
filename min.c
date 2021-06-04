#include<stdio.h>
int min(int arr[],int n)
{
    int min1=arr[0];
    int i;
    for(i=1;i<n;i++)
    {
        if(arr[i]<min1)
            min1=arr[i];
    }
    return min1;
}
void main()
{
    int arr[20],n,i;
    printf("Enter array length : ");
    scanf("%d",&n);
    printf("Enter elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int final=min(arr,n);
    printf("The minimum value is : %d",final);
}