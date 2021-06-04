#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *a;
void exchange(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int p, int q)
{
    int pivot,i,j,flag=0;
    pivot=a[p];
    while(flag!=1)
    {
        for(i=p+1;i<=q;i++)
        {
            if(a[i]>pivot)
                break;
        }
        for(j=q;j>=p+1;j--)
        {
            if(a[j]<pivot)
                break;
        }
        if(i<j)
            exchange(&a[i],&a[j]);
        else if(i>=j)
        {
            flag=1;
            exchange(&a[j],&a[p]);
            return (j);
        }
    }
}
void QuickSort(int p,int q)
{
    int j;
    if(p<q)
    {
        j=partition(p,q);
        QuickSort(p,j-1);
        QuickSort(j+1,q);
    }
}
int main()
{
    int n,i,p,q,k;
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
        a[n]=n+1;
        switch (k)
        {
        case 1:
            a[0]=n/2;
            for (i = 1; i < n/2; i++) 
            {
                a[i] = i;
            }
            for (i = n/2; i < n; i++) 
            {
                a[i] = i+1;
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
                a[i] = n-i ;
            }
            break;
        default:printf("Enter either 1 or 2 !");
            break;
        }
        clock_gettime(CLOCK_REALTIME, &start);
        p=0;
        q=n-1;
        QuickSort(p,q);
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