#include<stdio.h>
int heap_size=0,heap_arr[100];
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
void insert(int k,int heap_capacity)
{
    int i=heap_size;
    heap_arr[i]=k;
    while(i>0 && heap_arr[parent(i)] < heap_arr[i])
    {
        swap(&heap_arr[parent(i)],&heap_arr[i]);
        i=parent(i);
    }
    for(int j=0;j<heap_capacity;j++)
            printf("%d\t",heap_arr[j]);
    printf("\n");
    heap_size++;
}
void Max_heap(int arr[],int heap_capacity)
{
    for(int i=0;i<heap_capacity;i++)
    {
        insert(arr[i],heap_capacity);
        // for(int j=0;j<heap_capacity;j++)
        //     printf("%d\t",arr[i]);
        // printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter no.of elements : ");
    scanf("%d",&n);
    int i,arr[n];
    printf("Enter elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    Max_heap(arr,n);
    printf("Max heap is : ");
    for(int i=0;i<heap_size;i++)
        printf("%d ",heap_arr[i]);
}