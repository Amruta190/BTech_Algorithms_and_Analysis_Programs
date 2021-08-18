#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *a;
void swap(int* a, int* b)
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
    if(left<heap_capacity && a[left]>a[root])
        root=left;
    if(right< heap_capacity && a[right]>a[root])
        root=right;
    if(root!=i)
    {
        swap(&a[i],&a[root]);
        heapify(heap_capacity, root);
    }
}
void heap_sort(int heap_capacity)
{
    for(int i=(heap_capacity/2) - 1;i>=0;i--)
        heapify(heap_capacity, i);
    for(int i=heap_capacity-1 ; i>=0 ; i--)
    {
        swap(&a[0],&a[i]);
        heapify(i,0);
    }
}
int main()
{
    int n,i,k;
    struct timespec start,end;
    double total_time;
    FILE *fptr = fopen("sample.txt","w");
    if(fptr == NULL)
    {
        printf("Could not open file");
        return 0;
    }
    // printf("Enter the size of the array : ");
    // scanf("%d",&n);
    // printf("Enter the array elements : ");
    // for(i=0;i<n;i++)
    //     scanf("%d",&a[i]);
    printf("Choose one of the options\n");
    printf("1.Best case\n2.Average case\n3.Worst case\n");
    scanf("%d",&k);
    for(n=10000;n<=100000;n=n+10000)
    {
        a=(int*)malloc((n)*sizeof(int));
        if(a==NULL)
        {
            printf("Sufficient space could not be allocated!");
            return 0;
        }
        switch (k)
        {
        case 1:
            for (i = 0; i < n; i++) 
            {
                a[i] = n-i;
            }
            break;
        case 2:
            srand(time(0));
            for(i = 0; i<n; i++)
            {
                a[i] = rand() % n + 1;
            }
            break;    
        case 3:
            for (i = 0; i <n; i++) 
            {
                a[i] = i+1 ;
            }
            break;
        default:printf("Enter either 1 or 2 !");
            break;
        }
        clock_gettime(CLOCK_REALTIME, &start);
        heap_sort(n);
        clock_gettime(CLOCK_REALTIME, &end);
        total_time=(double) (end.tv_nsec - start.tv_nsec) + (double) (end.tv_sec-start.tv_sec)*1000000000;
        // printf("The sorted array is : ");
        // for(i=0;i<n;i++)
        // printf("%d ",a[i]);
        fprintf (fptr,"\nn= %d, Total time = %lf micro seconds\n",n, total_time/1000);
        free(a);
    }
    return 0; 
}