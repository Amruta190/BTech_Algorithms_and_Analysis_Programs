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
int parent(int i)
{
    return (i-1)/2;
}
void insert(int k,int heap_size)
{
    int i=heap_size;
    arr[i]=k;
    while(i>0 && arr[parent(i)] < arr[i])
    {
        swap(&arr[parent(i)],&arr[i]);
        i=parent(i);
    }
    heap_size++;
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
        for (i = 0; i < n-1; i++) 
        {
            arr[i] = n - i;
        }
        srand(time(0));
        k = rand() % n;
        clock_gettime(CLOCK_REALTIME, &start);
        insert(k,n);
        clock_gettime(CLOCK_REALTIME, &end);   
        total_time=(double) (end.tv_nsec - start.tv_nsec) + (double) (end.tv_sec-start.tv_sec)*1000000000;     
        fprintf (fptr,"\nn= %d, Total time = %lf micro seconds\n",n, total_time/1000);
        free(arr);
    }
    return 0; 
}