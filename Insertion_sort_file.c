#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// #include <unistd.h>    // for sleep()
int Insertion_Sort(int[],int);
int main()
{
    int n,*a,i,k;
    struct timespec start, end;
    double total_time;
    FILE *fptr = fopen("sample1.txt", "w");
    if (fptr == NULL)
    {
        printf("Could not open file");
        return 0;
    }
    printf("Choose one of the options\n");
    printf("1.Best case\n2.Average case\n3.Worst case\n");
    scanf("%d",&k);
    
    //printf("Enter the size of array:")   ;
    //scanf("%d",&n);
    for(n=10000;n<=100000;n=n+10000)
    {
    a=(int*)malloc(n*sizeof(int));
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
            a[i] = i + 1;
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
    default:printf("Enter 1, 2 or 3 !");
        break;
    }
    
    //printf("\nElements before sorting:\n");
    //for(i=0;i<n;i++)
        //printf("%d\t",a[i]);
    clock_gettime(CLOCK_REALTIME, &start);
    //clock_gettime(CLOCK_MONOTONIC, &start);
    Insertion_Sort(a,n);
    //sleep(3);
    clock_gettime(CLOCK_REALTIME, &end);
    //clock_gettime(CLOCK_MONOTONIC, &end);
    total_time=(double) (end.tv_nsec - start.tv_nsec) + (double) (end.tv_sec-start.tv_sec)*1000000000;
    //printf("\nElements after sorting:\n");
    //for(i=0;i<n;i++)
        //printf("%d\t",a[i]);
    //printf ("\nTotal time = %lf nano seconds\n",total_time);
    //printf ("\nTotal time = %lf micro seconds\n",total_time/1000);
    fprintf (fptr,"\nn= %d, Total time = %lf micro seconds\n",n, total_time/1000);
    free(a);
    }
    return 0;
}
int Insertion_Sort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        // Insert a[i] into the sorted part of the array, i.e., a [1: i-1]
        int j=i-1;
        while(j>=0 && a[j]>key)
        {
          a[j+1]=a[j];  // move a[j] to its next position  in the right side
          j--;
        }
        a[j+1]=key;
    }
}
