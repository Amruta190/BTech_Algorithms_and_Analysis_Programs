#include<stdio.h>
int arr[100];
void swap(int *a, int *b)
{   
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int heap_capacity,int i)
{
    int root=i;
    int left=2*i + 1;
    int right=2*i + 2;
    if(left<heap_capacity && arr[left]>arr[root])
        root=left;
    if(right< heap_capacity && arr[right]>arr[root])
        root=right;
    if(root!=i)
    {
        swap(&arr[i],&arr[root]);
        heapify(heap_capacity, root);
    }
}
void heap_sort(int heap_capacity)
{
    for(int i=(heap_capacity/2) - 1;i>=0;i--)
        heapify(heap_capacity, i);
    for(int i=heap_capacity-1 ; i>=0 ; i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(i,0);
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