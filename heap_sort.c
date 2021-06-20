#include<stdio.h>
int arr[100];
void swap(int *a, int *b)
{   
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heap(int heap_capacity,int i)
{
    int root=i;
    int left=2*i + 1;
    int right=2*i + 2;
    if(left<heap_capacity && arr[left]>arr[root])
    {
        swap(&arr[left],&arr[root]);
        heap(heap_capacity, left);
    }
    if(right< heap_capacity && arr[right]>arr[root])
    {
        swap(&arr[right],&arr[root]);
        heap(heap_capacity, right);
    }
}
void heap_sort(int heap_capacity)
{
    for(int i=(heap_capacity/2) - 1;i>=0;i--)
        heap(heap_capacity, i);
    for(int i=heap_capacity-1 ; i>=0 ; i--)
    {
        swap(&arr[0],&arr[i]);
        heap(i,0);
    }
}
int main()
{
    int n;
    printf("Enter no.of elements : ");
    scanf("%d",&n);
    int i;
    printf("Enter elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    heap_sort(n);
    printf("Sorted array is : ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}