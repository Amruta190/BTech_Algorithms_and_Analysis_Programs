#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *arr;
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
    if(left<heap_capacity && arr[left]<arr[root])
    {
        swap(&arr[left],&arr[root]);
        heap(heap_capacity,left);
    }
    if(right< heap_capacity && arr[right]<arr[root])
    {
        swap(&arr[right],&arr[root]);
        heap(heap_capacity,right);
    }
}
void Min_heap(int heap_capacity)
{
    int i=(heap_capacity/2)-1;
    for(int j=i;j>=0;j--)
        heap(heap_capacity,j);
}
int main()
{
    int n,i,k;
    struct timespec start,end;
    double total_time;
    FILE *fptr = fopen("sample1.txt", "w");
    if (fptr == NULL)
    {
        printf("Could not open file");
        return 0;
    }
    for(n=10000;n<=100000;n=n+10000)
    {
        arr=(int*)malloc(n*sizeof(int));
        if(arr==NULL)
        {
            printf("Sufficient space could not be allocated!");
            return 0;
        }
        for (i = 0; i < n; i++) 
        {
            arr[i] = n-i;
        }
        clock_gettime(CLOCK_REALTIME, &start);
        Min_heap(n);
        clock_gettime(CLOCK_REALTIME, &end);   
        total_time=(double) (end.tv_nsec - start.tv_nsec) + (double) (end.tv_sec-start.tv_sec)*1000000000;     
        fprintf (fptr,"\nn= %d, Total time = %lf micro seconds\n",n, total_time/1000);
        free(arr);
    }
    return 0; 
}