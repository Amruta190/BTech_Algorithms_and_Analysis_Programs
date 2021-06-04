#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *arr;
void Merge(int low, int mid, int high)
{
    int i,j,k;
    int p=mid-low+1;
    int q=high-mid;
    int st[p],str[q];
    for(i=0;i<p;i++)
      st[i]=arr[low+i];
    for(j=0;j<q;j++)
      str[j]=arr[mid+1+j];
    i=0;j=0;k=low;
    while(i<p&&j<q)
    {
        if(st[i]<=str[j])
        {
            arr[k]=st[i];
            i++;
        }
        else
        {
            arr[k]=str[j];
            j++;
        }
        k++;
    }
    while(i<p)
    {
        arr[k]=st[i];
        i++;
        k++;
    }
    while(j<q)
    {
        arr[k]=str[j];
        j++;
        k++;
    }
}
void MergeSort(int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        MergeSort(low,mid);
        MergeSort(mid+1,high);
        Merge(low,mid,high);
    }
}
int main()
{
    int n,i,low,mid,high,k;
    // clock_t st,et;
    struct timespec start,end;
    double total_time;
    FILE *fptr = fopen("sample1.txt", "w");
    if (fptr == NULL)
    {
        printf("Could not open file");
        return 0;
    }
    // printf("Enter array size :");
    // scanf("%d",&n);
    printf("Choose one of the options\n");
    printf("1.Best case\n2.Average case\n3.Worst case\n");
    scanf("%d",&k);
    for(n=10000;n<=100000;n=n+10000)
    {
        arr=(int*)malloc(n*sizeof(int));
        if(arr==NULL)
        {
            printf("Sufficient space could not be allocated!");
            return 0;
        }
        switch (k)
        {
        case 1:
            for (i = 0; i < n; i++) 
            {
                arr[i] = i + 1;
            }
            break;
        case 2:
            srand(time(0));
            for(i = 0; i<n; i++)
            {
                arr[i] = rand() % n + 1;
            }
            break;    
        case 3:
            for (i = 0; i <n; i++) 
            {
                arr[i] = n-i ;
            }
            break;
        default:printf("Enter either 1 or 2 !");
            break;
        }
        // st=clock();
        clock_gettime(CLOCK_REALTIME, &start);
        low=0;
        high=n-1;
        mid=(low+high)/2;
        MergeSort(low,high);
        // et=clock();
        clock_gettime(CLOCK_REALTIME, &end);
        // total_time = (double)(et-st)/CLOCKS_PER_SEC;     
        total_time=(double) (end.tv_nsec - start.tv_nsec) + (double) (end.tv_sec-start.tv_sec)*1000000000;
        // printf("The sorted array is : ");
        // for(i=0;i<n;i++)
        // {
            // printf("%d ",arr[i]);
        // }
        // printf("\nThe time taken is %lf",total_time);     
        fprintf (fptr,"\nn= %d, Total time = %lf micro seconds\n",n, total_time/1000);
        free(arr);
    }
    return 0; 
}