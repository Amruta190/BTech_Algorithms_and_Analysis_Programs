#include<stdio.h>
void swap(int *a, int *b)
{   
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void swap1(char *a, char *b)
{
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void sort(int n,int count[],char arr[])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (count[j] > count[j+1]) 
            {
                swap(&count[j],&count[j+1]);
                swap1(&arr[j],&arr[j+1]);
            }
        }
    }
}
int max(int a,int b)
{
    return (a>b)?a:b;
}
int LIS(int n,char arr[],int count[])
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
    sort(n,count,arr);
    char sequence[n];
    int k=0;
    for(int i=1;i<=n;i++)
    {
        if(count[i]>count[i-1])
        {
            sequence[k++]=arr[i-1];
        }
    }
    printf("The longest increasing subsequence is : \n");
    for(int i=0;i<k;i++)
        printf("%c",sequence[i]);
}
int main()
{
    int n;
    printf("Enter the size of the string : ");
    scanf("%d",&n);
    char arr[n];
    int count[n];
    printf("Enter the string : ");
    scanf("%s",arr);
    for(int i=0;i<n;i++)
        count[i]=1;
    LIS(n,arr,count);
}