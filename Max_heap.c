#include<stdio.h>
int arr[100],heap_capacity;
void swap(int *a, int *b)
{   
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heap(int i)
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
        heap(root);
    }
}
void Max_heap()
{
    int i=(heap_capacity/2)-1;
    for(int j=i;j>=0;j--)
        heap(j);
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
    heap_capacity=n;
    Max_heap();
    printf("Max heap is : ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}