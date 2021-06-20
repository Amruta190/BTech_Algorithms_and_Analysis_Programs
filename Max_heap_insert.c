#include<stdio.h>
int heap_size=4,heap_arr[10]={4,3,2,1};
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
    while(i>0 && heap_arr[parent(i)] < heap_arr[i])
    {
        swap(&heap_arr[parent(i)],&heap_arr[i]);
        i=parent(i);
    }
    heap_size++;
}
int main()
{
    int j;
    printf("Max heap is : ");
    for(int i=0;i<heap_size;i++)
        printf("%d ",heap_arr[i]);
    printf("\nEnter an element to insert : ");
    scanf("%d",&j);
    insert(j);
    printf("Max heap after inserting %d is : ",j);
    for(int i=0;i<heap_size;i++)
        printf("%d ",heap_arr[i]);
}