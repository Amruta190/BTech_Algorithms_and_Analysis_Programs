#include<stdio.h>
int heap_size=0;
void swap(int *a, int *b)
{   
    int temp=*a;
    *a=*b;
    *b=temp;
}
int parent(int i)
{
    return (i-1)/2;
}
void insert(int k,int heap_arr[])
{
    int i=heap_size;
    while(i>0 && heap_arr[parent(i)] > heap_arr[i])
    {
        swap(&heap_arr[parent(i)],&heap_arr[i]);
        i=parent(i);
    }
    for(int j=0;j<=heap_size;j++)
            printf("%d\t",heap_arr[j]);
    printf("\n");
    heap_size++;
}
int main()
{
    int n;
    printf("Enter no.of elements : ");
    scanf("%d",&n);
    int i,heap_arr[n];
    printf("Enter elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&heap_arr[i]);
        insert(heap_arr[i],heap_arr);
    }
    printf("Min heap is : ");
    for(int i=0;i<heap_size;i++)
        printf("%d ",heap_arr[i]);
}