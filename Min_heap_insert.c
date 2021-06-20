#include<stdio.h>
int heap_size=5,heap_arr[10]={3,6,5,9,8};
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
void insert(int k)
{
    int i=heap_size;
    heap_arr[i]=k;
    while(i>0 && heap_arr[parent(i)] > heap_arr[i])
    {
        swap(&heap_arr[parent(i)],&heap_arr[i]);
        i=parent(i);
    }
    heap_size++;
}
int main()
{
    int j;
    printf("Min heap is : ");
    for(int i=0;i<heap_size;i++)
        printf("%d ",heap_arr[i]);
    printf("\nEnter an element to insert : ");
    scanf("%d",&j);
    insert(j);
    printf("Min heap after inserting %d is : ",j);
    for(int i=0;i<heap_size;i++)
        printf("%d ",heap_arr[i]);
}